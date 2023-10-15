/**************************************************************/
/******************** Layer : HAL*************************/
/********************Ver :06 *************************/
/********************Component :CALC *************************/
/********************Author : Reham Naser *************************/
/******************** *************************/

#ifndef CALC_PRIVATE_H_
#define CALC_PRIVATE_H_
/*
 * 7 8 9 /
 * 4 5 6 *
 * 1 2 3 -
 * CLC 0 = +
 */

#define zero  14
#define one   1
#define two   2
#define three 3
#define four  5
#define five  6
#define six   7
#define seven 9
#define eight 10
#define nine  11

#define OPERATION_KEYS  key==4 || key==8 || key==12 || key==13 || key==15 || key==16

#define ADD  4
#define SUB  8
#define MUL   12
#define DIV  13
#define EQL  15
#define CLC  16




#endif
