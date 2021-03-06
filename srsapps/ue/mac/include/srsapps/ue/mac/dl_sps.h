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




#include "srsapps/common/log.h"
#include "srsapps/ue/phy/phy.h"
#include "srsapps/ue/mac/mac_params.h"
#include "srsapps/common/timers.h"

#ifndef DLSPS_H
#define DLSPS_H

/* Downlink Semi-Persistent schedulign (Section 5.10.1) */

namespace srslte {
namespace ue {
  
typedef _Complex float cf_t; 

class dl_sps
{
public:

  void            clear(); 
  void            reset(uint32_t tti, dl_sched_grant *grant); 
  dl_sched_grant *get_pending_grant(uint32_t tti); 
private:  
  
};

} 
}
#endif