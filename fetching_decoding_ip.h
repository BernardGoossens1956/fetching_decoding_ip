#ifndef __FETCHING_DECODING_IP
#define __FETCHING_DECODING_IP

#include "ap_cint.h"

#define LOG_CODE_MEM_SIZE 12
//size in bytes
#define CODE_MEM_SIZE     (1<<LOG_CODE_MEM_SIZE)

#define RET               0x8067

#define LOAD           0b00000
#define LOAD_FP        0b00001
#define CUSTOM_0       0b00010
#define MISC_MEM       0b00011
#define OP_IMM         0b00100
#define AUIPC          0b00101
#define OP_IMM_32      0b00110
#define RV48_0         0b00111
#define STORE          0b01000
#define STORE_FP       0b01001
#define CUSTOM_1       0b01010
#define AMO            0b01011
#define OP             0b01100
#define LUI            0b01101
#define OP_32          0b01110
#define RV_64          0b01111
#define MADD           0b10000
#define MSUB           0b10001
#define NMSUB          0b10010
#define NMADD          0b10011
#define OP_FP          0b10100
#define RESERVED_0     0b10101
#define CUSTOM_2_RV128 0b10110
#define RV48_1         0b10111
#define BRANCH         0b11000
#define JALR           0b11001
#define RESERVED_1     0b11010
#define JAL            0b11011
#define SYSTEM         0b11100
#define RESERVED_2     0b11101
#define CUSTOM_3_RV128 0b11110
#define RV80           0b11111

#define UNDEFINED_TYPE 0
#define R_TYPE         1
#define I_TYPE         2
#define S_TYPE         3
#define B_TYPE         4
#define U_TYPE         5
#define J_TYPE         6
#define OTHER_TYPE     7

typedef unsigned int instruction_t;
typedef uint12 code_address_t;
typedef uint3  type_t;
typedef int12  i_immediate_t;
typedef int12  s_immediate_t;
typedef int12  b_immediate_t;
typedef int20  u_immediate_t;
typedef int20  j_immediate_t;
typedef uint12 i_uimmediate_t;
typedef uint12 s_uimmediate_t;
typedef uint12 b_uimmediate_t;
typedef uint20 u_uimmediate_t;
typedef uint20 j_uimmediate_t;
typedef uint5  opcode_t;
typedef uint5  reg_num_t;
typedef uint3  func3_t;
typedef uint7  func7_t;
typedef uint1  bit_t;
typedef struct decoded_instruction_s{
  bit_t     inst_31;
  uint6     inst_30_25;
  uint4     inst_24_21;
  bit_t     inst_20;
  uint8     inst_19_12;
  uint4     inst_11_8;
  bit_t     inst_7;
  opcode_t  inst_6_2;
  opcode_t  opcode;
  uint2     inst_1_0;
  reg_num_t rd;
  func3_t   func3;
  reg_num_t rs1;
  reg_num_t rs2;
  func7_t   func7;
  type_t    type;
} decoded_instruction_t;

void fetching_decoding_ip(
  unsigned int *pc,
  unsigned int *code_mem,
  unsigned int *nb_instruction);

#endif
