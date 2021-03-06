#include "debug_fetching_decoding_ip.h"
#include "fetching_decoding_ip.h"
#include "type.h"
#ifndef __SYNTHESIS__
#ifdef DEBUG_DECODE
#include "print.h"
#endif
#endif

void decode(
  instruction_t i,
  decoded_instruction_t *d_i){
#pragma HLS INLINE off
  d_i->inst_31    = (i>>31);
  d_i->inst_30_25 = (i>>25);
  d_i->inst_24_21 = (i>>21);
  d_i->inst_20    = (i>>20);
  d_i->inst_19_12 = (i>>12);
  d_i->inst_11_8  = (i>> 8);
  d_i->inst_7     = (i>> 7);
  d_i->inst_6_2   = (i>> 2);
  d_i->opcode     = (i>> 2);
  d_i->inst_1_0   = (i    );
  d_i->rd         = (i>> 7);
  d_i->func3      = (i>>12);
  d_i->rs1        = (i>>15);
  d_i->rs2        = (i>>20);
  d_i->func7      = (i>>25);
  d_i->type       = type(d_i->opcode);
#ifndef __SYNTHESIS__
#ifdef DEBUG_DECODE
  print_decode(*d_i);
#endif
#endif
}
