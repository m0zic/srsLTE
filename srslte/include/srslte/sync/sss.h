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

/******************************************************************************
 *  File:         sss.h
 *
 *  Description:  Secondary synchronization signal (SSS) generation and detection.
 *
 *
 *  Reference:    3GPP TS 36.211 version 10.0.0 Release 10 Sec. 6.11.2
 *****************************************************************************/

#ifndef SSS_
#define SSS_

#include <stdint.h>
#include <stdbool.h>

#include "srslte/config.h"
#include "srslte/common/phy_common.h"
#include "srslte/dft/dft.h"


#define SRSLTE_SSS_N      31
#define SRSLTE_SSS_LEN    2*SRSLTE_SSS_N

typedef struct SRSLTE_API {
  int z1[SRSLTE_SSS_N][SRSLTE_SSS_N];
  int c[2][SRSLTE_SSS_N];
  int s[SRSLTE_SSS_N][SRSLTE_SSS_N];
}srslte_sss_tables_t;

/* Allocate 32 complex to make it multiple of 32-byte AVX instructions alignment requirement.
 * Should use srslte_vec_malloc() to make it platform agnostic.
 */
typedef struct SRSLTE_API {
  float z1[SRSLTE_SSS_N][SRSLTE_SSS_N];
  float c[2][SRSLTE_SSS_N];
  float s[SRSLTE_SSS_N][SRSLTE_SSS_N];
  float sd[SRSLTE_SSS_N][SRSLTE_SSS_N-1];
}srslte_sss_fc_tables_t;


/* Low-level API */
typedef struct SRSLTE_API {

  srslte_dft_plan_t dftp_input;
  
  uint32_t fft_size;

  float corr_peak_threshold;
  uint32_t symbol_sz;
  uint32_t subframe_sz;
  uint32_t N_id_2;
  
  uint32_t N_id_1_table[30][30];
  srslte_sss_fc_tables_t fc_tables[3]; // one for each N_id_2

  float corr_output_m0[SRSLTE_SSS_N];
  float corr_output_m1[SRSLTE_SSS_N];

}srslte_sss_synch_t;


/* Basic functionality */
SRSLTE_API int srslte_sss_synch_init(srslte_sss_synch_t *q,
                                     uint32_t fft_size);

SRSLTE_API int srslte_sss_synch_realloc(srslte_sss_synch_t *q, 
                                        uint32_t fft_size); 

SRSLTE_API void srslte_sss_synch_free(srslte_sss_synch_t *q);

SRSLTE_API void srslte_sss_generate(float *signal0, 
                                    float *signal5, 
                                    uint32_t cell_id);

SRSLTE_API void srslte_sss_put_slot(float *sss, 
                                    cf_t *symbol, 
                                    uint32_t nof_prb, 
                                    srslte_cp_t cp);

SRSLTE_API int srslte_sss_synch_set_N_id_2(srslte_sss_synch_t *q, 
                                           uint32_t N_id_2);

SRSLTE_API int srslte_sss_synch_m0m1_partial(srslte_sss_synch_t *q, 
                                             cf_t *input, 
                                             uint32_t M, 
                                             cf_t ce[2*SRSLTE_SSS_N],
                                             uint32_t *m0, 
                                             float *m0_value, 
                                             uint32_t *m1, 
                                             float *m1_value);

SRSLTE_API int srslte_sss_synch_m0m1_diff_coh(srslte_sss_synch_t *q, 
                                              cf_t *input, 
                                              cf_t ce[2*SRSLTE_SSS_N],
                                              uint32_t *m0, 
                                              float *m0_value, 
                                              uint32_t *m1, 
                                              float *m1_value);

SRSLTE_API int srslte_sss_synch_m0m1_diff(srslte_sss_synch_t *q, 
                                          cf_t *input, 
                                          uint32_t *m0, 
                                          float *m0_value, 
                                          uint32_t *m1, 
                                          float *m1_value);


SRSLTE_API uint32_t srslte_sss_synch_subframe(uint32_t m0, 
                                              uint32_t m1);

SRSLTE_API int srslte_sss_synch_N_id_1(srslte_sss_synch_t *q, 
                                       uint32_t m0, 
                                       uint32_t m1);

SRSLTE_API int srslte_sss_synch_frame(srslte_sss_synch_t *q, 
                                      cf_t *input, 
                                      uint32_t *subframe_idx, 
                                      uint32_t *N_id_1);

SRSLTE_API void srslte_sss_synch_set_threshold(srslte_sss_synch_t *q, 
                                               float threshold);

SRSLTE_API void srslte_sss_synch_set_symbol_sz(srslte_sss_synch_t *q, 
                                               uint32_t symbol_sz);

SRSLTE_API void srslte_sss_synch_set_subframe_sz(srslte_sss_synch_t *q, 
                                                 uint32_t subframe_sz);


/* High-level API */

typedef struct SRSLTE_API {
  srslte_sss_synch_t obj;
  struct srslte_sss_synch_init {
    uint32_t N_id_2;
  } init;
  cf_t *input;
  uint32_t in_len;
  struct srslte_sss_synch_ctrl_in {
    uint32_t symbol_sz;
    uint32_t subframe_sz;
    uint32_t correlation_threshold;
  } ctrl_in;
  struct srslte_sss_synch_ctrl_out {
    uint32_t subframe_idx;
    uint32_t N_id_1;
  } ctrl_out;
}srslte_sss_synch_hl;

#define DEFAULT_FRAME_SIZE    2048

SRSLTE_API int srslte_sss_synch_initialize(srslte_sss_synch_hl* h);
SRSLTE_API int srslte_sss_synch_work(srslte_sss_synch_hl* hl);
SRSLTE_API int srslte_sss_synch_stop(srslte_sss_synch_hl* hl);

#endif // SSS_

