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


#include <unistd.h>

#include "liblte_rrc.h"
#include "srsapps/radio/radio_uhd.h"
#include "srsapps/ue/phy/phy.h"
#include "srsapps/common/tti_sync_cv.h"
#include "srsapps/common/log_stdout.h"
#include "srsapps/ue/mac/mac.h"



/**********************************************************************
 *  Program arguments processing
 ***********************************************************************/
typedef struct {
  float uhd_rx_freq;
  float uhd_tx_freq; 
  float uhd_rx_gain;
  float uhd_tx_gain;
  int   verbose; 
}prog_args_t;

void args_default(prog_args_t *args) {
  args->uhd_rx_freq = -1.0;
  args->uhd_tx_freq = -1.0;
  args->uhd_rx_gain = -1; // set to autogain
  args->uhd_tx_gain = -1; 
  args->verbose     = 0; 
}

void usage(prog_args_t *args, char *prog) {
  printf("Usage: %s [gv] -f rx_frequency (in Hz) -F tx_frequency (in Hz)\n", prog);
  printf("\t-g UHD RX gain [Default AGC]\n");
  printf("\t-G UHD TX gain [Default same as RX gain (AGC)]\n");
  printf("\t-v [increase verbosity, default none]\n");
}

void parse_args(prog_args_t *args, int argc, char **argv) {
  int opt;
  args_default(args);
  while ((opt = getopt(argc, argv, "gGfFv")) != -1) {
    switch (opt) {
    case 'g':
      args->uhd_rx_gain = atof(argv[optind]);
      break;
    case 'G':
      args->uhd_tx_gain = atof(argv[optind]);
      break;
    case 'f':
      args->uhd_rx_freq = atof(argv[optind]);
      break;
    case 'F':
      args->uhd_tx_freq = atof(argv[optind]);
      break;
    case 'v':
      args->verbose++;
      break;
    default:
      usage(args, argv[0]);
      exit(-1);
    }
  }
  if (args->uhd_rx_freq < 0 || args->uhd_tx_freq < 0) {
    usage(args, argv[0]);
    exit(-1);
  }
}

// Determine SI messages scheduling as in 36.331 5.2.3 Acquisition of an SI message
uint32_t sib_start_tti(uint32_t tti, uint32_t period, uint32_t x) {
  return (period*10*(1+tti/(period*10))+x)%10240; // the 1 means next opportunity
}

void setup_mac_phy_sib2(LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_2_STRUCT *sib2, srslte::ue::mac *mac, srslte::ue::phy *phy) {
  // RACH-CONFIGCOMMON
  if (sib2->rr_config_common_sib.rach_cnfg.preambles_group_a_cnfg.present) {
    mac->set_param(srslte::ue::mac_params::RA_NOFGROUPAPREAMBLES, 
                   liblte_rrc_message_size_group_a_num[sib2->rr_config_common_sib.rach_cnfg.preambles_group_a_cnfg.size_of_ra]);
    mac->set_param(srslte::ue::mac_params::RA_MESSAGESIZEA, 
                   liblte_rrc_message_size_group_a_num[sib2->rr_config_common_sib.rach_cnfg.preambles_group_a_cnfg.msg_size]);
    mac->set_param(srslte::ue::mac_params::RA_MESSAGEPOWEROFFSETB, 
                   liblte_rrc_message_power_offset_group_b_num[sib2->rr_config_common_sib.rach_cnfg.preambles_group_a_cnfg.msg_pwr_offset_group_b]);        
  }
  mac->set_param(srslte::ue::mac_params::RA_NOFPREAMBLES, 
                 liblte_rrc_number_of_ra_preambles_num[sib2->rr_config_common_sib.rach_cnfg.num_ra_preambles]);
  mac->set_param(srslte::ue::mac_params::RA_POWERRAMPINGSTEP, 
                 liblte_rrc_power_ramping_step_num[sib2->rr_config_common_sib.rach_cnfg.pwr_ramping_step]);
  mac->set_param(srslte::ue::mac_params::RA_INITRECEIVEDPOWER, 
                 liblte_rrc_preamble_initial_received_target_power_num[sib2->rr_config_common_sib.rach_cnfg.preamble_init_rx_target_pwr]);
  mac->set_param(srslte::ue::mac_params::RA_PREAMBLETRANSMAX, 
                 liblte_rrc_preamble_trans_max_num[sib2->rr_config_common_sib.rach_cnfg.preamble_trans_max]);
  mac->set_param(srslte::ue::mac_params::RA_RESPONSEWINDOW, 
                 liblte_rrc_ra_response_window_size_num[sib2->rr_config_common_sib.rach_cnfg.ra_resp_win_size]);
  mac->set_param(srslte::ue::mac_params::RA_CONTENTIONTIMER, 
                 liblte_rrc_mac_contention_resolution_timer_num[sib2->rr_config_common_sib.rach_cnfg.mac_con_res_timer]);
  mac->set_param(srslte::ue::mac_params::HARQ_MAXMSG3TX, 
                 sib2->rr_config_common_sib.rach_cnfg.max_harq_msg3_tx);
  
  printf("Set RACH ConfigCommon: NofPreambles=%d, ResponseWindow=%d, ContentionResolutionTimer=%d ms, MaxTrials=%d\n",  
         liblte_rrc_number_of_ra_preambles_num[sib2->rr_config_common_sib.rach_cnfg.num_ra_preambles], 
         liblte_rrc_ra_response_window_size_num[sib2->rr_config_common_sib.rach_cnfg.ra_resp_win_size], 
         liblte_rrc_mac_contention_resolution_timer_num[sib2->rr_config_common_sib.rach_cnfg.mac_con_res_timer], 
         liblte_rrc_preamble_trans_max_num[sib2->rr_config_common_sib.rach_cnfg.preamble_trans_max]);
  
  // PDSCH ConfigCommon
  mac->set_param(srslte::ue::mac_params::PDSCH_RSPOWER, 
                 sib2->rr_config_common_sib.pdsch_cnfg.rs_power);
  mac->set_param(srslte::ue::mac_params::PDSCH_PB, 
                 sib2->rr_config_common_sib.pdsch_cnfg.p_b);

  // PUSCH ConfigCommon
  phy->set_param(srslte::ue::phy_params::PUSCH_BETA, 10);
  phy->set_param(srslte::ue::phy_params::PUSCH_EN_64QAM, 
                 sib2->rr_config_common_sib.pusch_cnfg.enable_64_qam);
  phy->set_param(srslte::ue::phy_params::PUSCH_HOPPING_OFFSET, 
                 sib2->rr_config_common_sib.pusch_cnfg.pusch_hopping_offset);
  phy->set_param(srslte::ue::phy_params::PUSCH_HOPPING_N_SB, 
                 sib2->rr_config_common_sib.pusch_cnfg.n_sb);
  phy->set_param(srslte::ue::phy_params::PUSCH_HOPPING_INTRA_SF, 
                 sib2->rr_config_common_sib.pusch_cnfg.hopping_mode == LIBLTE_RRC_HOPPING_MODE_INTRA_AND_INTER_SUBFRAME?1:0);
  phy->set_param(srslte::ue::phy_params::PUSCH_RS_GROUP_HOPPING_EN, 
                 sib2->rr_config_common_sib.pusch_cnfg.ul_rs.group_hopping_enabled?1:0);
  phy->set_param(srslte::ue::phy_params::PUSCH_RS_SEQUENCE_HOPPING_EN, 
                 sib2->rr_config_common_sib.pusch_cnfg.ul_rs.sequence_hopping_enabled?1:0);
  phy->set_param(srslte::ue::phy_params::PUSCH_RS_CYCLIC_SHIFT, 
                 sib2->rr_config_common_sib.pusch_cnfg.ul_rs.cyclic_shift);
  phy->set_param(srslte::ue::phy_params::PUSCH_RS_GROUP_ASSIGNMENT, 
                 sib2->rr_config_common_sib.pusch_cnfg.ul_rs.group_assignment_pusch);

  printf("Set PUSCH ConfigCommon: HopOffset=%d, RSGroup=%d, RSNcs=%d, N_sb=%d\n",
    sib2->rr_config_common_sib.pusch_cnfg.pusch_hopping_offset,
    sib2->rr_config_common_sib.pusch_cnfg.ul_rs.group_assignment_pusch,
    sib2->rr_config_common_sib.pusch_cnfg.ul_rs.cyclic_shift, 
    sib2->rr_config_common_sib.pusch_cnfg.n_sb);
  
  // PUCCH ConfigCommon
  phy->set_param(srslte::ue::phy_params::PUCCH_BETA, 10);
  phy->set_param(srslte::ue::phy_params::PUCCH_DELTA_SHIFT, 
                 liblte_rrc_delta_pucch_shift_num[sib2->rr_config_common_sib.pucch_cnfg.delta_pucch_shift]);
  phy->set_param(srslte::ue::phy_params::PUCCH_CYCLIC_SHIFT, 
                 sib2->rr_config_common_sib.pucch_cnfg.n_cs_an);
  phy->set_param(srslte::ue::phy_params::PUCCH_N_PUCCH_1, 
                 sib2->rr_config_common_sib.pucch_cnfg.n1_pucch_an);
  phy->set_param(srslte::ue::phy_params::PUCCH_N_RB_2, 
                 sib2->rr_config_common_sib.pucch_cnfg.n_rb_cqi);
  printf("Set PUCCH ConfigCommon: DeltaShift=%d, CyclicShift=%d, N1=%d, NRB=%d\n",
         liblte_rrc_delta_pucch_shift_num[sib2->rr_config_common_sib.pucch_cnfg.delta_pucch_shift],
         sib2->rr_config_common_sib.pucch_cnfg.n_cs_an,
         sib2->rr_config_common_sib.pucch_cnfg.n1_pucch_an,
         sib2->rr_config_common_sib.pucch_cnfg.n_rb_cqi);

  
  // PRACH Configcommon
  phy->set_param(srslte::ue::phy_params::PRACH_ROOT_SEQ_IDX, 
                 sib2->rr_config_common_sib.prach_cnfg.root_sequence_index);
  phy->set_param(srslte::ue::phy_params::PRACH_HIGH_SPEED_FLAG, 
                 sib2->rr_config_common_sib.prach_cnfg.prach_cnfg_info.high_speed_flag?1:0);
  phy->set_param(srslte::ue::phy_params::PRACH_FREQ_OFFSET, 
                 sib2->rr_config_common_sib.prach_cnfg.prach_cnfg_info.prach_freq_offset);
  phy->set_param(srslte::ue::phy_params::PRACH_ZC_CONFIG, 
                 sib2->rr_config_common_sib.prach_cnfg.prach_cnfg_info.zero_correlation_zone_config);
  phy->set_param(srslte::ue::phy_params::PRACH_CONFIG_INDEX, 
                 sib2->rr_config_common_sib.prach_cnfg.prach_cnfg_info.prach_config_index);
  
  printf("Set PRACH ConfigCommon: SeqIdx=%d, HS=%d, FreqOffset=%d, ZC=%d, ConfigIndex=%d\n", 
     sib2->rr_config_common_sib.prach_cnfg.root_sequence_index, 
     sib2->rr_config_common_sib.prach_cnfg.prach_cnfg_info.high_speed_flag?1:0,
     sib2->rr_config_common_sib.prach_cnfg.prach_cnfg_info.prach_freq_offset,
     sib2->rr_config_common_sib.prach_cnfg.prach_cnfg_info.zero_correlation_zone_config,
     sib2->rr_config_common_sib.prach_cnfg.prach_cnfg_info.prach_config_index);
}

void process_connsetup(LIBLTE_RRC_CONNECTION_SETUP_STRUCT *msg, srslte::ue::mac *mac, srslte::ue::phy *phy) {
  mac->set_param(srslte::ue::mac_params::HARQ_MAXTX, 
                 liblte_rrc_max_harq_tx_num[msg->rr_cnfg.mac_main_cnfg.explicit_value.ulsch_cnfg.max_harq_tx]);
  printf("Set MAX HARQ reTX: %d\n", liblte_rrc_max_harq_tx_num[msg->rr_cnfg.mac_main_cnfg.explicit_value.ulsch_cnfg.max_harq_tx]);
  
  phy->set_param(srslte::ue::phy_params::SR_PUCCH_RESINDEX, 
                 msg->rr_cnfg.phy_cnfg_ded.sched_request_cnfg.sr_pucch_resource_idx);
  phy->set_param(srslte::ue::phy_params::SR_CONFIG_INDEX, 
                 msg->rr_cnfg.phy_cnfg_ded.sched_request_cnfg.sr_cnfg_idx);

  mac->set_param(srslte::ue::mac_params::SR_TRANS_MAX, 
                 liblte_rrc_dsr_trans_max_num[msg->rr_cnfg.phy_cnfg_ded.sched_request_cnfg.dsr_trans_max]);
  mac->set_param(srslte::ue::mac_params::SR_PUCCH_CONFIGURED, 1);
  
  printf("Set SR configuration: TransMAX: %d, n_pucch=%d, configIndex=%d\n", 
         liblte_rrc_dsr_trans_max_num[msg->rr_cnfg.phy_cnfg_ded.sched_request_cnfg.dsr_trans_max], 
         msg->rr_cnfg.phy_cnfg_ded.sched_request_cnfg.sr_pucch_resource_idx,
         msg->rr_cnfg.phy_cnfg_ded.sched_request_cnfg.sr_cnfg_idx);
  
  mac->set_param(srslte::ue::mac_params::BSR_TIMER_RETX, 
                 liblte_rrc_retransmission_bsr_timer_num[msg->rr_cnfg.mac_main_cnfg.explicit_value.ulsch_cnfg.retx_bsr_timer]);
  mac->set_param(srslte::ue::mac_params::BSR_TIMER_PERIODIC, 
                 liblte_rrc_periodic_bsr_timer_num[msg->rr_cnfg.mac_main_cnfg.explicit_value.ulsch_cnfg.periodic_bsr_timer]);

  printf("Set MAC BSR configuration: ReTX timer: %d, Periodic: %d\n", 
         liblte_rrc_retransmission_bsr_timer_num[msg->rr_cnfg.mac_main_cnfg.explicit_value.ulsch_cnfg.retx_bsr_timer], 
         liblte_rrc_periodic_bsr_timer_num[msg->rr_cnfg.mac_main_cnfg.explicit_value.ulsch_cnfg.periodic_bsr_timer]);
  
  phy->set_param(srslte::ue::phy_params::UCI_I_OFFSET_ACK, msg->rr_cnfg.phy_cnfg_ded.pusch_cnfg_ded.beta_offset_ack_idx);
  phy->set_param(srslte::ue::phy_params::UCI_I_OFFSET_CQI, msg->rr_cnfg.phy_cnfg_ded.pusch_cnfg_ded.beta_offset_cqi_idx);
  phy->set_param(srslte::ue::phy_params::UCI_I_OFFSET_RI, msg->rr_cnfg.phy_cnfg_ded.pusch_cnfg_ded.beta_offset_ri_idx);
 
  
  // Setup radio bearers
  for (int i=0;i<msg->rr_cnfg.srb_to_add_mod_list_size;i++) {
    if (msg->rr_cnfg.srb_to_add_mod_list[i].lc_default_cnfg_present) {
      printf("Setting up Default Configuration for SRB%d \n", msg->rr_cnfg.srb_to_add_mod_list[i].srb_id);  
      switch(msg->rr_cnfg.srb_to_add_mod_list[i].srb_id) {
        case 1:
          mac->setup_lcid(1, 0, 1, -1, -1);
          break;
        case 2: 
          mac->setup_lcid(2, 0, 3, -1, -1);
          break;
      }
    }
  }
  for (int i=0;i<msg->rr_cnfg.drb_to_add_mod_list_size;i++) {
    printf("Setting up DRB%d\n", msg->rr_cnfg.drb_to_add_mod_list[i].drb_id);
    // todo 
  }
}


// Hex bytes for the connection setup complete packet
// Got hex bytes from http://www.sharetechnote.com/html/RACH_LTE.html 
uint8_t setupComplete_segm[10][12] ={{0x88, 0x00, 0x00, 0x20, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0}, 
                                      {0x98, 0x01, 0x20, 0x80, 0x01, 0x00, 0x59, 0x17, 0x0,  0x0,  0x0,  0x0},
                                      {0x98, 0x02, 0x39, 0x45, 0xE5, 0x34, 0x0B, 0x07, 0x0,  0x0,  0x0,  0x0},
                                      {0x98, 0x03, 0x41, 0x02, 0x0B, 0xF6, 0x03, 0x02, 0x0,  0x0,  0x0,  0x0},
                                      {0x98, 0x04, 0x27, 0x80, 0x01, 0x00, 0xD0, 0xCC, 0x0,  0x0,  0x0,  0x0},
                                      {0x98, 0x05, 0x71, 0x51, 0x04, 0xE0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0},
                                      {0x98, 0x06, 0xE0, 0xC0, 0x40, 0x00, 0x21, 0x02, 0x0,  0x0,  0x0,  0x0},
                                      {0x98, 0x07, 0x03, 0xD0, 0x11, 0xD1, 0x27, 0x1A, 0x0,  0x0,  0x0,  0x0},
                                      {0x98, 0x08, 0x80, 0x80, 0x21, 0x10, 0x01, 0x00, 0x0,  0x0,  0x0,  0x0},
                                      {0xB0, 0x09, 0x00, 0x10, 0x81, 0x06, 0x00, 0x00, 0x00, 0x00, 0x83, 0x06}};
uint8_t last_segm[54]; 
uint32_t lengths[10] = {4, 8, 8, 8, 8, 6, 8, 8, 8, 12}; 


int main(int argc, char *argv[])
{
  prog_args_t prog_args; 
  srslte::ue::tti_sync_cv ttisync(10240); 
  srslte::radio_uhd radio_uhd; 
  srslte::ue::phy phy; 
  srslte::ue::mac mac; 
  srslte::log_stdout mac_log("MAC"), phy_log("PHY"); 
  
  parse_args(&prog_args, argc, argv);
  
  switch (prog_args.verbose) {
    case 1:
      mac_log.set_level_info();
      phy_log.set_level_info();
      break;
    case 2: 
      mac_log.set_level_debug();
      phy_log.set_level_debug();
      break;
  }

// Init Radio and PHY
  if (prog_args.uhd_rx_gain > 0 && prog_args.uhd_tx_gain > 0) {
    radio_uhd.init();
    radio_uhd.set_rx_gain(prog_args.uhd_rx_gain);
    radio_uhd.set_tx_gain(prog_args.uhd_tx_gain);
    phy.init(&radio_uhd, &ttisync, &phy_log);
  } else {
    radio_uhd.init_agc();
    radio_uhd.set_tx_rx_gain_offset(0);
    phy.init_agc(&radio_uhd, &ttisync, &phy_log);
  }  
  // Init MAC 
  mac.init(&phy, &ttisync, &mac_log);
    
  // Set RX freq
  radio_uhd.set_rx_freq(prog_args.uhd_rx_freq);
  radio_uhd.set_tx_freq(prog_args.uhd_tx_freq);
  
  LIBLTE_BIT_MSG_STRUCT                bit_msg; 
  LIBLTE_RRC_MIB_STRUCT                bch_msg; 
  LIBLTE_RRC_BCCH_DLSCH_MSG_STRUCT     dlsch_msg; 
  LIBLTE_RRC_UL_CCCH_MSG_STRUCT        ul_ccch_msg;  
  LIBLTE_RRC_DL_CCCH_MSG_STRUCT        dl_ccch_msg;  
  
  uint32_t si_window_len, sib2_period; 
  int tti; 
  enum {START, SIB1, SIB2, CONNECT, SETUPCOMPLETE} state = START;
  int n; 
  
  while(1) {
    switch(state) {
      case START: 
        n = mac.recv_bcch_sdu(bit_msg.msg, LIBLTE_MAX_MSG_SIZE); 
        if (n > 0) {
          bit_msg.N_bits = n; 
          liblte_rrc_unpack_bcch_bch_msg(&bit_msg, &bch_msg); 
          printf("MIB received %d bytes, BW=%s\n", n, liblte_rrc_dl_bandwidth_text[bch_msg.dl_bw]);
          state = SIB1;          
        }
        break;
      case SIB1:
        n = mac.recv_bcch_sdu(bit_msg.msg, LIBLTE_MAX_MSG_SIZE); 
        if (n > 0) {
          bit_msg.N_bits = n; 
          liblte_rrc_unpack_bcch_dlsch_msg(&bit_msg, &dlsch_msg);          
          si_window_len = liblte_rrc_si_window_length_num[dlsch_msg.sibs[0].sib.sib1.si_window_length];
          sib2_period = liblte_rrc_si_periodicity_num[dlsch_msg.sibs[0].sib.sib1.sched_info[0].si_periodicity];
          printf("SIB1 received %d bytes, CellID=%d, si_window=%d, sib2_period=%d\n", 
                 n/8, dlsch_msg.sibs[0].sib.sib1.cell_id&0xfff, si_window_len, sib2_period);          
          state = SIB2; 
        } else {
          tti = mac.get_tti();           
          mac.set_param(srslte::ue::mac_params::BCCH_SI_WINDOW_ST, sib_start_tti(tti, 2, 5));
          mac.set_param(srslte::ue::mac_params::BCCH_SI_WINDOW_LEN, 1);          
        }
        break;
      case SIB2: 
        n = mac.recv_bcch_sdu(bit_msg.msg, LIBLTE_MAX_MSG_SIZE);
        if (n > 0) {
          // Process SIB2
          bit_msg.N_bits = n; 
          liblte_rrc_unpack_bcch_dlsch_msg(&bit_msg, &dlsch_msg);                    
          printf("SIB2 received %d bytes\n", n/8);
          setup_mac_phy_sib2(&dlsch_msg.sibs[0].sib.sib2, &mac, &phy);
          
          // Prepare ConnectionRequest packet
          ul_ccch_msg.msg_type = LIBLTE_RRC_UL_CCCH_MSG_TYPE_RRC_CON_REQ;
          ul_ccch_msg.msg.rrc_con_req.ue_id_type = LIBLTE_RRC_CON_REQ_UE_ID_TYPE_RANDOM_VALUE; 
          ul_ccch_msg.msg.rrc_con_req.ue_id.random = 1000;
          ul_ccch_msg.msg.rrc_con_req.cause = LIBLTE_RRC_CON_REQ_EST_CAUSE_MO_DATA; 
          liblte_rrc_pack_ul_ccch_msg(&ul_ccch_msg, &bit_msg);

          uint64_t uecri=0;
          uint8_t *ue_cri_ptr = (uint8_t*) &uecri; 
          uint32_t nbytes = bit_msg.N_bits/8;
          uint8_t *ptr = bit_msg.msg; 
          for (int i=0;i<nbytes;i++) {
            ue_cri_ptr[nbytes-i-1] = (uint8_t) srslte_bit_unpack(&ptr, 8);
          }
          mac.set_param(srslte::ue::mac_params::CONTENTION_ID, uecri);

          // Send ConnectionRequest Packet
          printf("Send ConnectionRequest %d bytes\n", nbytes);
          mac.send_ccch_sdu(bit_msg.msg, bit_msg.N_bits);
          state = CONNECT; 
        } else {
          tti = mac.get_tti(); 
          mac.set_param(srslte::ue::mac_params::BCCH_SI_WINDOW_ST, sib_start_tti(tti, sib2_period, 0));
          mac.set_param(srslte::ue::mac_params::BCCH_SI_WINDOW_LEN, si_window_len);      
        }
        break;
      case CONNECT: 
        // Wait for Connection Setup
        n = mac.recv_ccch_sdu(bit_msg.msg, LIBLTE_MAX_MSG_SIZE); 
        if (n > 0) {
          printf("ConnSetup received %d bytes\n", n/8);
          bit_msg.N_bits = n; 
          liblte_rrc_unpack_dl_ccch_msg(&bit_msg, &dl_ccch_msg);
          printf("Response: %s\n", liblte_rrc_dl_ccch_msg_type_text[dl_ccch_msg.msg_type]);
          switch (dl_ccch_msg.msg_type) {
            case LIBLTE_RRC_DL_CCCH_MSG_TYPE_RRC_CON_SETUP: 
              // Process ConnectionSetup
              process_connsetup(&dl_ccch_msg.msg.rrc_con_setup, &mac, &phy);

              // Generate and send ConnectionSetupComplete              
              for (int i=0;i<9;i++) {
                printf("Sending Connection Setup Complete %d\n", i);
                srslte_bit_pack_vector(setupComplete_segm[i], bit_msg.msg, lengths[i]);
                n=mac.send_dcch0_sdu(bit_msg.msg, lengths[i]*8);
                if (n < 0) {
                  fprintf(stderr, "Error writting to DCCH0\n");
                  exit(-1);
                }
              }
              // Last segment is 54 bytes long 
              printf("Sending Connection Setup Complete Last segment\n");
              bzero(last_segm, 54*sizeof(uint8_t));
              memcpy(last_segm, setupComplete_segm[9], lengths[9]*sizeof(uint8_t));
              srslte_bit_pack_vector(last_segm, bit_msg.msg, 54);
              n=mac.send_dcch0_sdu(bit_msg.msg, 54*8);
              if (n < 0) {
                fprintf(stderr, "Error writting to DCCH0\n");
                exit(-1);
              }
              
              state = SETUPCOMPLETE;
              break;
            case LIBLTE_RRC_DL_CCCH_MSG_TYPE_RRC_CON_REJ:
              mac.set_param(srslte::ue::mac_params::RNTI_C, 0);
              break;
          } 
         // exit(0);
        }
        break;
      case SETUPCOMPLETE:
        // Wait for ConnectionSetup
        n = mac.recv_dtch0_sdu(bit_msg.msg, LIBLTE_MAX_MSG_SIZE); 
        if (n > 0) {
          printf("Received on DTCH0 %d bytes\n", n/8);
        }
        break;
    }
      
    usleep(10000);
  }
}

  

