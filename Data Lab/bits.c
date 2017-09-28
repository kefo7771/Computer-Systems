/*
 * CS:APP Data Lab
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

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "kefo7771",
   /* Student name 1: Replace with the full name of first team member */
   "Kenneth Ford",
   /* Login ID 1: Replace with the login ID of first team member */
   "kefo7771",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "",
   /* Login ID 2: Login ID of the second team member */
   ""
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:

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

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
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
   <http://www.gnu.org/licenses/>.  */
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
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
//
// 15 problems, 40 points
// 2 - rating 1
// 5 - rating 2
// 4 - rating 3
// 4 - rating 4
// rating 1
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  //Uses Demorgan's Law that says A&B= ~(~A|~B)
  int result=0;
  result=~(~x|~y);
  return result;
}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
//largest two's complement number can be expressed in the formula 2^(bit size-1)-1
//with bit size being 32, end up with 2^(32-1)-1= 2^(31)-1
//smallest value is 2^ 31, expressed in hex as 0x80000000
//this means that the largest positive integer found is the inverse of the smallest negative value
    unsigned int result=~(0);
    result=result>>1;

  return result;
}
// rating 2
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int evenBits(void) {
    signed int initialPattern=0x55;//initialize bits to all ones
    int secondPattern=initialPattern<<8;//pattern of 5 is what we are looking for as the final pattern
    int thirdPattern=secondPattern | 0x55;//keep matching this until all 32 bits match
    int fourthPattern=(thirdPattern<<8);
    fourthPattern=fourthPattern | 0x55;


  return (fourthPattern<<8) | 0x55;
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
//create a mask, save the bits wanted, shift wanted bits over to the right most bits
        int shift=n<<3;//left shift by 3 = multiply by 2^3, or 8
        int mask=0xFF<<shift;//left shift the byte mask by n*8
        int result=x & mask; //and the initial word with the mask
        result=result>>shift;// gets the desired byte from the left to the right most bits
        result= result & 0xFF;//removes any unwanted bits to the left of our desired bits

    return result;
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
//checks whether or not two values are equal to each other
    int result=!(x^y);//xor produces zero if identical, one if different
    //bang operator changes integer value from 0 to 1 and vice versa

  return result;
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //change the sign of a number
  //two's complement math, change signs by inverting bits and adding 1

  int result=(~x)+1;

  return result;
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
//divide x by n to the power of 2 using right bit shifting
//need to determine first if x is a positive or negative value

    int result=(x+((x>>31) & ((1<<n) +~0)))>>n;
    //x right shifted 31 times saves its sign bit
    //this anded together with mask will determine sign, 0 is positive, 1 is negative
    //x+sign>>n will divide the value of x+sign by 2^n

  return result;
}
// rating 3
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  //if x and y share sign and sum is opposite sign, overflow has occurred
  //if x and y share sign and sum is same sign, overflow has not occurred
    int signX=(x>>31)&(0x00000001);//shift 31 changes sign on negatives and hex masks and maintains sign value
    //fill x with 0's on left, anded with one will result in the sign of x being saved
    int signY= (y>>31)&(0x00000001);//same as above, just with y this time
    //fill y with 0's on left, anded with one will result in the sign of y being saved
    int signSum=((x+y)>>31)&(0x00000001);//adding x and y and shifting by 31 and masking maintains sign value
    //saves the sign of the sum of the signs of x+y
    int result=!((~signX&~signY&signSum)|(signX&signY&~signSum));//use truth table to check conditions of when overflow occurs and represent those conditions
    //bang operator used to change sign to expected output
  return result;
}

/*
 * multFiveEights - multiplies by 5/8 rounding toward 0.
 *   Examples: multFiveEights(77) = 48
 *             multFiveEights(-22) = -13
 *   You can assume |x| < (1 << 29)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEights(int x) {
  //multiply x by 5/8
  //have to break down fraction into multiply by 5 and then divide by 8
  int value=(x<<2)+x;//multiply x by 2^2 and then add x to be equivalent to x*5
  int result=(value+((value>>31) & ((1<<3) +~0)))>>3;//similar to above problem, shifting handles sign assignment and then divides by 2^3 or 8

  return result;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {


    int twoCompX = ~x+1;
    int twoCompxPlusY = twoCompX + y; //valid if not under/overflow
    int sign = twoCompxPlusY >> 31 & 1; //shifts and saves sign

    //need some sort of under/overflow protection
    int msbMask = 1 << 31;//masking the most significant bit
    int xSign = x & msbMask;//use bit mask to find the sign bit of x
    int ySign = y & msbMask;//use bit mask to find the sign bit of y
    int diffSign = xSign ^ ySign;//checks signs of x and y, returns 1 when diff, 0 when same
    diffSign = (diffSign >> 31) & 1;//move sign bit to lsb and mask/save it
    //checks three steps:
    //step 1: determine if numbers have different signs
    //step 2: if signs are same, then and it together with xSign lsb
    //step 3: if signs are different, inverse sign in order to prevent overflow and "and" them together

    return (diffSign & (xSign>>31)) | (!diffSign & !sign);
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
    // create a bitmask to save the bits in the range of lowbit to highbit
    int firstMask=(~(0)<<highbit<<1);//create first mask of everything up to highbit and move past it by one bit
    //creates line of bits of all ones and left shifts them up to highbit, everything on right are zeros
    int secondMask= (~(0)<<lowbit);//create second mask of everything up to lowbit
    //all one bits are shifted by lowbit with zeros one the right of lowbit
    int result= (firstMask ^ secondMask) & secondMask;// xor the first two masks; this will fill in range with one bits
    //"and" the xor result with secondMask to remove excess ones

    return result;
}
// rating 4
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 60
 *   Rating: 4
 */
int isPower2(int x) {
//will check input x and determine if it is a power of 2 or not
//power of 2 will be in the format of 1 followed by some amount of zeros, except 0 and 1

    int isPowTwo= x & (x+0xFF);//checks if x is power of 2
    //adds x to mask of all ones to eventually compare x to x-1
    //ands x to x-1 to see if x is power of 2
    //if power of two, will result in zero; !=0 when not power of two

    //and isPowTwo and x will give 0 if a power and non zero is not a power
    //+!x: will give 0 if x is positive, will give |x|-1 if negative
    //bang at front will change inside to 0 if not power and to a 1 if a power
    return !((x & (isPowTwo)) + !x);

}
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4
 */
int leastBitPos(int x) {
  //conditions
    //return mask that marks least significant 1 bit
    //x==0, return 0
    int negX= ~x;//negation of x, part 1
    negX= negX + 1;//negation of x plus one in two's complement
    //adding one will shift all bits which will come in handy in the next step
    //the 1's in the negation of x will carry forward, lsb one will be preserved as 1

    //anding x and negX will create a mask that will save the least significant 1
    return (x & negX);
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  //use xor to find out how many 1's in x
  //use right shift on the bits to the right
  //continue with the pattern until last bit
  //and it to save the least significant bit
  x^=x>>16;//xor 32 bit integer and compare first 16 and last 16 bits
  //will result in 16 bits
  x^=x>>8;//xor the resulting 16 bits and divide it in half looking at first 8 and last 8
  //will result in 8 bits
  x^=x>>4;//xor the resulting 8 bits and divide it in half and look at the first 4 bits and last 4
  //will result in 4 bits
  x^=x>>2;//xor the resulting 4 bits and divide it in half and look at most significant 2 and least significant 2
  //will result in 2 bits
  x^=x>>1;//xor the left and right bits to finally narrow it to one bit


    //mask that will save the one bit to see the parity value
  return (x & 0x01);
}
/*
 * logicalNeg - implement the ! operator, using any of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
    int twosCompX=~x+1;//first get the twos complement of x
    int result= x | twosCompX;//or x and two complement of x to get comparison
    result=(~(result>>31));//shift the sign bit to the least significant bit position
    result=result & 0x1;//bit wise invert, will result in either 0 for non zero numbers and 1 for zero

  return result;
}
