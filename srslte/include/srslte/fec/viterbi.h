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
 *  File:         viterbi.h
 *
 *  Description:  Viterbi decoder for convolutionally encoded data.
 *                Used for decoding of PBCH and PDCCH (type 37 decoder).
 *
 *  Reference:
 *****************************************************************************/

#ifndef VITERBI_
#define VITERBI_

#include <stdbool.h>
#include "srslte/config.h"

typedef enum {
  SRSLTE_VITERBI_27 = 0, 
  SRSLTE_VITERBI_29, 
  SRSLTE_VITERBI_37, 
  SRSLTE_VITERBI_39
}srslte_viterbi_type_t;

typedef struct SRSLTE_API{
  void *ptr;
  uint32_t R;
  uint32_t K;
  uint32_t framebits;
  bool tail_biting;
  float gain_quant; 
  uint32_t poly[3];
  int (*decode) (void*, uint8_t*, uint8_t*, uint32_t);
  int (*decode_f) (void*, float*, uint8_t*, uint32_t);
  void (*free) (void*);
  uint8_t *tmp;
  uint8_t *symbols_uc;
}srslte_viterbi_t;

SRSLTE_API int srslte_viterbi_init(srslte_viterbi_t *q, 
                                   srslte_viterbi_type_t type, 
                                   uint32_t poly[3], 
                                   uint32_t max_frame_length, 
                                   bool tail_bitting);

SRSLTE_API void srslte_viterbi_set_gain_quant(srslte_viterbi_t *q, 
                                              float gain_quant); 

SRSLTE_API void srslte_viterbi_free(srslte_viterbi_t *q);

SRSLTE_API int srslte_viterbi_decode_f(srslte_viterbi_t *q, 
                                       float *symbols, 
                                       uint8_t *data, 
                                       uint32_t frame_length);

SRSLTE_API int srslte_viterbi_decode_uc(srslte_viterbi_t *q, 
                                        uint8_t *symbols, 
                                        uint8_t *data, 
                                        uint32_t frame_length);


/* High-level API */
typedef struct SRSLTE_API{
  srslte_viterbi_t obj;
  struct srslte_viterbi_init {
    int rate;
    int constraint_length;
    int tail_bitting;
    int generator_0;
    int generator_1;
    int generator_2;
    int frame_length;
  } init;
  float *input;
  int in_len;
  uint8_t *output;
  int out_len;
}srslte_viterbi_hl;

SRSLTE_API int srslte_viterbi_initialize(srslte_viterbi_hl* h);
SRSLTE_API int srslte_viterbi_work(srslte_viterbi_hl* hl);
SRSLTE_API int srslte_viterbi_stop(srslte_viterbi_hl* h);

#endif
