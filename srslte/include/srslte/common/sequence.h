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

/**********************************************************************************************
 *  File:         sequence.h
 *
 *  Description:  Pseudo Random Sequence generation. Sequences are defined by a length-31 Gold
 *                sequence.
 *
 *  Reference:    3GPP TS 36.211 version 10.0.0 Release 10 Sec. 7.2
 *********************************************************************************************/

#ifndef LTESEQ_
#define LTESEQ_

#include "srslte/config.h"
#include "srslte/common/phy_common.h"

typedef struct SRSLTE_API {
  uint8_t *c;
  uint32_t len;
} srslte_sequence_t;

SRSLTE_API int srslte_sequence_init(srslte_sequence_t *q, uint32_t len);

SRSLTE_API void srslte_sequence_free(srslte_sequence_t *q);

SRSLTE_API int srslte_sequence_LTE_pr(srslte_sequence_t *q, 
                                      uint32_t len, 
                                      uint32_t seed);

SRSLTE_API void srslte_sequence_set_LTE_pr(srslte_sequence_t *q, 
                                           uint32_t seed); 

SRSLTE_API int srslte_sequence_pbch(srslte_sequence_t *seq, 
                                    srslte_cp_t cp, 
                                    uint32_t cell_id);

SRSLTE_API int srslte_sequence_pcfich(srslte_sequence_t *seq, 
                                      uint32_t nslot, 
                                      uint32_t cell_id);

SRSLTE_API int srslte_sequence_phich(srslte_sequence_t *seq, 
                                     uint32_t nslot, 
                                     uint32_t cell_id);

SRSLTE_API int srslte_sequence_pdcch(srslte_sequence_t *seq, 
                                     uint32_t nslot, 
                                     uint32_t cell_id, 
                                     uint32_t len);

SRSLTE_API int srslte_sequence_pdsch(srslte_sequence_t *seq, 
                                     uint16_t rnti, 
                                     int q,
                                     uint32_t nslot, 
                                     uint32_t cell_id, 
                                     uint32_t len);

SRSLTE_API int srslte_sequence_pusch(srslte_sequence_t *seq, 
                                     uint16_t rnti, 
                                     uint32_t nslot, 
                                     uint32_t cell_id, 
                                     uint32_t len);

SRSLTE_API int srslte_sequence_pucch(srslte_sequence_t *seq, 
                                     uint16_t rnti, 
                                     uint32_t nslot, 
                                     uint32_t cell_id); 
#endif
