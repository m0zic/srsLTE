/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2015 The srsLTE Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution.
 *
 * \section LICENSE
 *
 * This file is part of the srsLTE library.
 *
 * srsLTE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsLTE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#include "srsapps/ue/mac/proc_bsr.h"
#include "srsapps/ue/mac/mac_params.h"
#include "srsapps/ue/mac/mac.h"
#include "srsapps/ue/mac/mux.h"

namespace srslte {
  namespace ue {
    
bsr_proc::bsr_proc()
{
  initiated = false; 
  timer_periodic = false; 
  timer_retx = false; 
  for (int i=0;i<MAX_LCID;i++)  {
    lcg[i]        = -1; 
    priorities[i] = -1; 
  }        
  triggered_bsr_type=NONE; 
}

void bsr_proc::init(log* log_h_, timers *timers_db_, mac_params* params_db_, mac_io *mac_io_h_)
{
  log_h     = log_h_; 
  params_db = params_db_;
  mac_io_h  = mac_io_h_;
  timers_db = timers_db_; 
  initiated = true;
}

void bsr_proc::reset()
{
  triggered_bsr_type = NONE; 
}

/* Process Periodic BSR */
void bsr_proc::timer_expired(uint32_t timer_id) {
  switch(timer_id) {
    case mac::BSR_TIMER_PERIODIC:
      if (triggered_bsr_type == NONE) {
        // Check condition 4 in Sec 5.4.5 
        if (check_all_channels()) {
          triggered_bsr_type = PERIODIC; 
          Info("BSR set to PERIODIC\n");
        }
      }
      break;
    case mac::BSR_TIMER_RETX:
      // Check condition 3 in Sec 5.4.5 
      if (check_all_channels()) {
        Info("BSR set to REGULAR RETX\n");
        triggered_bsr_type = REGULAR; 
        sr_is_sent = false; // Enable reTx of SR 
      }
      break;      
  }
}

// Checks if data is available for a a channel with higher priority than others 
bool bsr_proc::check_highest_channel() {
  uint32_t pending_data = 0; 
  uint32_t pending_data_lcid = 0; 
  
  for (int i=0;i<mac_io::NOF_UL_LCH && !pending_data;i++) {
    if (lcg[i] >= 0) {
      pending_data = mac_io_h->get(i+mac_io::MAC_LCH_CCCH_UL)->pending_data()/8;
      if (pending_data > 0) {
        pending_data_lcid = i; 
        for (int j=0;j<mac_io::NOF_UL_LCH;j++) {
          if (!mac_io_h->get(j+mac_io::MAC_LCH_CCCH_UL)->isempty()) {
            if (priorities[j] > priorities[i]) {
              pending_data = 0; 
            }
          }
        }
      }      
    }
  }
  if (pending_data) {
    pending_bsr.buff_size[lcg[pending_data_lcid]] = pending_data; 
    if (triggered_bsr_type != REGULAR) {        
      Info("Triggered REGULAR BSR for Max Priority LCID=%d\n", pending_data_lcid);
    }
    triggered_bsr_type = REGULAR; 
    return true; 
  } else {
    return false; 
  }
}
    
// Checks if only one logical channel has data avaiable for Tx
bool bsr_proc::check_single_channel() {    
  uint32_t pending_data_lcid = 0; 
  uint32_t nof_nonzero_lcid = 0; 
  
  for (int i=0;i<mac_io::NOF_UL_LCH;i++) {
    if (lcg[i] >= 0) {
      if (!mac_io_h->get(i+mac_io::MAC_LCH_CCCH_UL)->isempty()) {
        pending_data_lcid = i;
        nof_nonzero_lcid++; 
      }
    }
  }
  if (nof_nonzero_lcid == 1) {
    pending_bsr.buff_size[lcg[pending_data_lcid]] = mac_io_h->get(pending_data_lcid+mac_io::MAC_LCH_CCCH_UL)->pending_data()/8; 
    triggered_bsr_type = REGULAR; 
    Info("Triggered REGULAR BSR for single LCID=%d\n", pending_data_lcid);
    return true; 
  } else {
    return false; 
  }
}

bool bsr_proc::check_all_channels() {
  bool ret = false; 
  bzero(&pending_bsr, sizeof(bsr_t));    
  for (int i=0;i<mac_io_h->NOF_UL_LCH;i++) {
    if (lcg[i] >= 0) {
      uint32_t n = mac_io_h->get(i+mac_io::MAC_LCH_CCCH_UL)->pending_data()/8;
      pending_bsr.buff_size[lcg[i]] += n;
      if (n > 0) {
        ret = true; 
      }
    }
  }
  return ret; 
}

void bsr_proc::get_pending_bsr_format(uint32_t nof_padding_bytes) {
  uint32_t nof_lcg=0;
  for (int i=0;i<4;i++) {
    if (pending_bsr.buff_size[i] > 0) {
      nof_lcg++;
    }
  }
  if (triggered_bsr_type == PADDING) {            
    if (nof_padding_bytes < 4) {
      // If space only for short  
      if (nof_lcg > 1) {
        pending_bsr.format = TRUNC_BSR;
        uint32_t max_prio_ch = find_max_priority_lcid();
        for (int i=0;i<4;i++) {
          if (lcg[max_prio_ch] != i) {
            pending_bsr.buff_size[i] = 0; 
          }
        }
      } else {
        pending_bsr.format = SHORT_BSR;
      }
    } else {
      // If space for long BSR  
      pending_bsr.format = LONG_BSR;
    }
  } else {
    pending_bsr.format = SHORT_BSR;    
    if (nof_lcg > 1) {
      pending_bsr.format = LONG_BSR;
    }  
  }     
}

// Checks if Regular BSR must be assembled, as defined in 5.4.5 
// Padding BSR is assembled when called by mux_unit when UL grant is received
// Periodic BSR is triggered by the expiration of the timers 
void bsr_proc::step(uint32_t tti)
{
  if (!initiated) {
    return;
  }  
  
  if (!timer_periodic) {
    if (params_db->get_param(mac_params::BSR_TIMER_PERIODIC)) {
      timer_periodic = true; 
      timers_db->get(mac::BSR_TIMER_PERIODIC)->set(this, params_db->get_param(mac_params::BSR_TIMER_PERIODIC));
    }
  }

  if (!timer_retx) {
    if (params_db->get_param(mac_params::BSR_TIMER_RETX)) {
      timer_retx = true; 
      timers_db->get(mac::BSR_TIMER_RETX)->set(this, params_db->get_param(mac_params::BSR_TIMER_RETX));
    }
  }

  // Check condition 1 in Sec 5.4.5   
  if (triggered_bsr_type == NONE) {
    check_single_channel();
  }
  // Higher priority channel is reported regardless of a BSR being already triggered
  check_highest_channel();
}

bool bsr_proc::need_to_send_bsr_on_ul_grant(uint32_t nof_grant_bytes, uint32_t nof_padding_bytes, bsr_t *bsr) 
{
  bool ret = false; 

  if (triggered_bsr_type == NONE) {
    // If enough space for at least truncated BSR 
    if (nof_padding_bytes >= 2) {
      // Check condition 2 in Sec 5.4.5 
      if (check_all_channels()) {
        triggered_bsr_type = PADDING; 
      }      
    }
  } 
  if (triggered_bsr_type != NONE) {
    // If no more data is pending and there is no space for MAC CE
    uint32_t nof_pending_bytes = 0;
    for (int i=0;i<4;i++) {
      nof_pending_bytes += pending_bsr.buff_size[i]; 
    }
    Info("Triggered BSR: nof_grant_bytes=%d, nof_padding_bytes=%d, nof_pending_bytes=%d\n", nof_grant_bytes, nof_padding_bytes, nof_pending_bytes);

    get_pending_bsr_format(nof_padding_bytes);    
    
    // Do not include BSR CE if the UL grant can accomodate all pending data but is not sufficient 
    // to additionally accomodate the BSR MAC CE plus its header
    uint32_t bsr_sz_plus_header = pending_bsr.format == LONG_BSR?4:2;
    if (nof_pending_bytes + bsr_sz_plus_header == nof_grant_bytes) {
      triggered_bsr_type = NONE;       
    } else {
      // Instruct MUX unit to generate MAC CE 
      ret = true; 
      memcpy(bsr, &pending_bsr, sizeof(bsr_t));
      if (timer_periodic && pending_bsr.format != TRUNC_BSR) {
        timers_db->get(mac::BSR_TIMER_PERIODIC)->reset();
        timers_db->get(mac::BSR_TIMER_PERIODIC)->run();
      }
      // Cancel all triggered BSR 
      triggered_bsr_type = NONE;     
    }
  }
  
  // Restart or Start ReTX timer
  if (timer_retx) {
    timers_db->get(mac::BSR_TIMER_RETX)->reset();
    timers_db->get(mac::BSR_TIMER_RETX)->run();
  }
  return ret; 
}

bool bsr_proc::need_to_send_sr() {
  if (!sr_is_sent && triggered_bsr_type == REGULAR) {
    sr_is_sent = true; 
    return true; 
  } 
  return false; 
}

void bsr_proc::setup_lcg(uint32_t lcid, uint32_t new_lcg)
{
  if (lcid < MAX_LCID && new_lcg < 4) {
    lcg[lcid] = new_lcg; 
  }      
}

void bsr_proc::set_priority(uint32_t lcid, uint32_t priority) {
  if (lcid < MAX_LCID) {
    priorities[lcid] = priority;     
  }
}

uint32_t bsr_proc::find_max_priority_lcid() {
  uint32_t max_prio = 0, max_idx = 0; 
  for (int i=0;i<MAX_LCID;i++) {
    if (priorities[i] > max_prio) {
      max_prio = priorities[i]; 
      max_idx  = i; 
    }
  }
  return max_idx; 
}

}
}
