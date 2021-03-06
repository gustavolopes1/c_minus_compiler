#ifndef _CGEN_H_
#define _CGEN_H_

#define nlabel_size 3
#define ntemp_size 3

typedef enum {  opADD, opSUB, opMULT, opDIV, opBLT, opSLE, opBGT, opSGE, opBEQ, opBNE, opAND, opOR, opASSIGN,
                opALLOC, opADDI, opSUBI, opLOAD, opSTORE, opVEC, opGOTO, opIFF, opRET, opFUN, opEND, opPARAM,
                opCALL, opARG, opLABEL, opHALT, opMOVE, opPUT} OpKind;

typedef enum {  Empty, IntConst, String } AddrKind;

typedef struct {
  AddrKind kind;
  union {
    int val;
    struct {
      char * name;
      char * scope;
    } var;
  } contents;
} Address;

typedef struct {
  OpKind op;
  Address addr1, addr2, addr3;
} Quad;

typedef struct QuadListRec {
  int location;
  Quad quad;
  struct QuadListRec * next;
} * QuadList;

void codeIntermedGen(TreeNode * arv_sintatica);

QuadList getIntermediate();

void printCode();

#endif
