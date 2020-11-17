#include "fetching_decoding_ip.h"
#include "fetch.h"
#include "decode.h"
#include "execute.h"

void fetching_decoding_ip(
  unsigned int pc[2],
  unsigned int code_mem[CODE_MEM_SIZE/sizeof(int)],
  unsigned int *nb_instruction){
#pragma HLS INTERFACE s_axilite port=pc
#pragma HLS INTERFACE s_axilite port=code_mem
#pragma HLS INTERFACE s_axilite port=nb_instruction
#pragma HLS INTERFACE ap_ctrl_none port=return
  code_address_t        current_pc;
  code_address_t        next_pc;
  instruction_t         instruction;
  unsigned int          nbi;
  decoded_instruction_t d_i;
  next_pc = (code_address_t)(pc[0]);
  nbi = 0;
  do{
#pragma HLS PIPELINE off
    current_pc = next_pc;
    fetch(current_pc, code_mem, &instruction);
    decode(instruction, &d_i);
    execute(current_pc, d_i, &next_pc);
    nbi = nbi + 1;
  } while (instruction != RET);
  pc[1] = (unsigned int)current_pc;
  *nb_instruction = nbi;
}
