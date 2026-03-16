/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~((~((~x)&y)) & (~(x&(~y))));
// when you xor, result is 1 iff a!=b for each bits.
// You can easily get x^y = ((~x)&y)|(x&(~y))
// by the Demorgan's law, x^y = ~(~(((~x)&y)|(x&(~y))))
// cont. x^y = ~((~((~x)&y)) & (~(x&(~y))))
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {

x = x | (x >> 16);
x = x | (x >> 8);

return !(!(x & 0x55));
/*
GOAL: static_cast<bool>(x & 0x55555555)
It is equal to !(!(x & 0x55555555))
Owing to I can't use 4byte constant, I will compress $x$.
You can easily know:
staic_cast<bool>(((x>>24) | (x>>16) | (x>>8) | x) & 0x55) = static_cast<bool>(x & (0x55555555))
*/
}

/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  // a + b = a + (~b) + 1
  int shifter = 32 + (~n); // shifter for top bits
  int top = ((x >> shifter) >> 1) & ((1 << n) + (~0));
  // (1<<n) + (~0) is 0000000....0111111
  // shift the $x$
  // and add the disappeared top bits to bottom.
  return (x << n) | top; 
}
/*
 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7D3D591
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int bitReverse(int x) {
    int c1 = 0x55, c2 = 0x33, c3 = 0x0F, c4 = 0xFF, c5 = 0xFF;
    
    c1 = c1 | (c1 << 8); c1 = c1 | (c1 << 16);
    // c1 = 01010101010101010101010101010101

    c2 = c2 | (c2 << 8); c2 = c2 | (c2 << 16);
    // c2 = 00110011001100110011001100110011

    c3 = c3 | (c3 << 8); c3 = c3 | (c3 << 16);
    // c3 = 00001111000011110000111100001111

    c4 = c4 | (c4 << 16);
    // c4 = 00000000111111110000000011111111

    c5 = c5 | (c5 << 8);
    // c5 = 00000000000000001111111111111111


    // Combine
    x = ((x >> 1) & c1) | ((x & c1) << 1); // swap each bits (01) (23) (45) ..
    x = ((x >> 2) & c2) | ((x & c2) << 2); // swap each 2 bits (01,23) (45,67) ...
    x = ((x >> 4) & c3) | ((x & c3) << 4); // swap each bytes (0, 1), (2, 3), ..
    x = ((x >> 8) & c4) | ((x & c4) << 8); // swap each 2 bytes
    x = ((x >> 16) & c5) | ((x & c5) << 16); // swap half

    return x;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int sign, b16, b8, b4, b2, b1, b0;
    // We want to find MSB of ~x (without sign bit)
  sign = x >> 31;
  x = x ^ sign;
    // if x is negative, x = ~x;
    // otherwise, x = x
    // **2. Performs right shifts arithmetically.**
    
    // lets find out bit. (binary search)
  b16 = (!(!(x>>16))) << 4; x = x >> b16;
  b8 = (!(!(x>>8))) << 3; x = x >> b8;
  b4 = (!(!(x>>4))) << 2; x = x >> b4;
  b2 = (!(!(x>>2))) << 1; x = x >> b2;
  b1 = (!(!(x>>1))); x = x >> b1;
  b0 = x;
  return b16 + b8 + b4 + b2 + b1 + b0 + 1;
    // If there are bit on upper 16 bits, we need 16 more bit.
    // If there are bit on upper 8 bits, we need 8 more bit.
    // ...
    // Add all.
    // Finally, add 1 (sign bit)
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    return (!x) | y;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int ret = (!x) + (~0); // IF $x$ is false, $!x$ is 1, then x = 0. otherwise, x = 0b11111111...
  return ((ret) & y) | (~ret & z);
}
/* 
 * subtractionOK - Determine if can compute x-y without overflow
 *   Example: subtractionOK(0x80000000,0x80000000) = 1,
 *            subtractionOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subtractionOK(int x, int y) {
  int subtraction, signx, signy, signSub;
  subtraction = x + (~y) + 1;
  signx = x>>31; signy = y>>31; signSub = subtraction>>31;
  // get MSB to find sign
  // If the sign of the x and y is different, and, sign of x and x - y is different, then overflow will occur.
  return !((signx ^ signy) & (signx ^ signSub));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int sub, signx, signy, signSub, ds;
  sub = y + (~x) + 1;
  signx = (x>>31) & 1; signy = (y>>31) & 1; signSub = (sub>>31) & 1;
  // * Why this machine fill msb of '1'? *
  // We should (x >> 31) & 1, not x >> 31.
  
  ds = signx ^ signy;
  return (ds & signx) | ((!ds) & (!signSub));

  // Do y-x, and check the sign.
  // If the sign is negative, x is greater than y;
  // if the sign of x and y is equal, overflow does not occur.
  // so we enough to check the signSub represent positive
  // Otherwise, sign x (or sign y) is the sign of signSub;
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  int sign;
  sign = x >> 31;
  return (x + sign) ^ sign;
  // if sign bit is on, (x + sign) ^ sign = (x - 1)^1 = ~x + 1
  // otherwise (x+0)^0 = x;
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // sign of $x | ((~x) + 1)$ is negative if and only if x != 0.
  // So, we can figure '!' with it.
  return 1 + ((x | ((~x) + 1)) >> 31); // +1 for every non zero
}
/* 
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) {
    unsigned pf, pg;
    pf = uf & 0x7FFFFFFF; // abs(uf)
    pg = ug & 0x7FFFFFFF; // abs(ug)

    // exceptions
    if(pf > 0x7F800000 || pg > 0x7F800000) return 0; // is it nan? if so return 0
    // 0x7F80000, exp = 
    if(pf == 0 && pg == 0) return 1; // -0 vs 0

    return uf == ug; // simply compare
}
/* 
 * floatUnsigned2Float - Return bit-level equivalent of expression (float) u
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatUnsigned2Float(unsigned u) {
    unsigned x, exp, frac, round;
    x = u;
    exp = 158; // bias 127 + shift 31

    if(u==0) return 0; // if u is 0, then return 0;

    while((x & 0x80000000) == 0) {
      x<<=1;
      --exp;
    }

    frac = (x >> 8) & 0x7FFFFF; // get frac part
    round = x & 0xFF; // upper 2 bytes for rounding

    if(round > 0x80 || (round == 0x80 && (frac & 1))) {
      ++frac;
      if(frac > 0x7FFFFF){
        frac = 0;
        ++exp;
      }
    }

    return (exp << 23) | frac;
}

/* 
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
unsigned floatScale64(unsigned uf) {
  unsigned s, exp, frac, t;
  s = uf & 0x80000000; // sign part
  exp = (uf >> 23) & 0xFF; // exp part
  frac = uf & 0x7FFFFF; // fraction part

  if(exp == 255) return uf; // nan
  if(exp == 0 && frac == 0) return uf; // uf == 0; so, uf * 64 == 0
  
  // mul 2 6times
  t = 6;
  while(t--) {
    if (exp == 0) {
      frac <<= 1;
      if (frac > 0x7FFFFF) { // carring
        exp = 1;
        frac &= 0x7FFFFF;
      }
    } else {
      ++exp;
      if (exp == 255) { // nan
        frac = 0;
        break;
      }
    }
  }

  return s | (exp<<23) | frac; //combine them
}
