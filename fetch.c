#include "debug_fetching_decoding_ip.h"
#include "fetching_decoding_ip.h"
#ifndef __SYNTHESIS__
#ifdef DEBUG_FETCH
#include <stdio.h>
#endif
#endif

void fetch(
  code_address_t current_pc,
  instruction_t *code_mem,
  instruction_t *instruction){
#pragma HLS INLINE off
  *instruction = code_mem[current_pc>>2];
#ifndef __SYNTHESIS__
#ifdef DEBUG_FETCH
  printf("%03d: %08x\n",
    (unsigned int)current_pc,
    (unsigned int)*instruction);
#endif
#endif
}
