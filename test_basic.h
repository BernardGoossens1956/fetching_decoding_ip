#ifndef __TEST_BASIC
#define __TEST_BASIC

#include "fetching_decoding_ip.h"

/*
       .globl  main
main:
        addi    sp,sp,-16
        sw      ra,12(sp)
        sw      s0,8(sp)
        j       .L1
        li      a1,0
        li      a2,0
.L1:
        nop
        li      a3,0
        bne     a1,a2,.L2
        li      a4,0
.L2:
        lw      ra,12(sp)
        lw      s0,8(sp)
        addi    sp,sp,16
        ret
*/

instruction_t code_mem[CODE_MEM_SIZE/sizeof(int)]=
{
  0xff010113,
  0x00112623,
  0x00812423,
  0x00c0006f,
  0x00000593,
  0x00000613,
  0x00000013,
  0x00000693,
  0x00c59463,
  0x00000713,
  0x00c12083,
  0x00812403,
  0x01010113,
  0x00008067
};

#endif
