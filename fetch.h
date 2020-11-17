#ifndef __FETCH
#define __FETCH

#include "fetching_decoding_ip.h"
void fetch(
  code_address_t current_pc,
  instruction_t *mem,
  instruction_t *instruction);

#endif
