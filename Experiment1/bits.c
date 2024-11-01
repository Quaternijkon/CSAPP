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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~x & ~y) & ~(x & y);
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
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    int x_plus1 = x + 1;
    // 检查 x + 1 是否等于 ~x
    int check = (x_plus1 ^ ~x);
    // 排除 x 为 -1 的情况
    int not_minus_one = !!x_plus1;
    return !(check) & not_minus_one;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    int mask = 0xAA;    // 构造掩码0xAA
    mask = mask + (mask << 8);// 0xAAAA
    mask = mask + (mask << 16);// 0xAAAAAAAA
    return !((x & mask) ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
   // x - 0x30
    int lower_diff = x + (~0x30 + 1); 
    //  x - 0x30 的符号位
    int lower_sign = (lower_diff >> 31) & 1;
    
    // 0x39 - x
    int upper_diff = 0x39 + (~x + 1); 
    //  0x39 - x 的符号位
    int upper_sign = (upper_diff >> 31) & 1;

    int lower_ok = ~lower_sign & 1;
    int upper_ok = ~upper_sign & 1;
    return lower_ok & upper_ok;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // 生成掩码：如果x非零，mask为0xFFFFFFFF；否则为0
    int mask = (~ (!!x)) + 1;
    // 根据mask选择返回y或z
    return (mask & y) | ((~mask) & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    // 提取符号位
    int sign_x = (x >> 31) & 1;
    int sign_y = (y >> 31) & 1;
    
    // 判断符号是否不同
    int sign_diff = sign_x ^ sign_y;
    
    // 计算 y - x
    int y_minus_x = y + (~x + 1);
    int sign_y_minus_x = (y_minus_x >> 31) & 1;
    
    // 如果符号不同且x为负，则x < y
    int less_when_sign_diff = sign_diff & sign_x;
    
    // 如果符号相同且 y - x >= 0，则x <= y
    int less_when_sign_same = (!sign_diff) & (!sign_y_minus_x);
    
    // x <= y 的情况包括 x < y 或 x == y
    int is_less_or_equal = less_when_sign_diff | less_when_sign_same;
    
    // 返回结果，确保为0或1
    return is_less_or_equal;
}

//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    // 计算 ~x + 1，即 -x
    int neg_x = ~x + 1;
    
    // 将 x 和 -x 进行按位或操作
    int or_result = x | neg_x;
    
    // 右移31位，提取最高位
    int sign = or_result >> 31;
    
    // 对最高位取反并加1，得到逻辑非的结果
    return (sign + 1) & 1;
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
    int sign, bits, tmp;
    
    // 1. 统一处理符号：如果x为负，取反
    sign = (x >> 31) & 1;
    x = (sign) ? ~x : x;
    
    bits = 1; // 至少需要1位来表示
    
    // 2. 检查16位
    tmp = x >> 16;
    bits += (!!tmp) << 4; // 如果高16位有1，加16位
    x = tmp | (x >> 16); // 如果高16位有1，x右移16位后继续检查
    
    // 3. 检查8位
    tmp = x >> 8;
    bits += (!!tmp) << 3; // 如果高8位有1，加8位
    x = tmp | (x >> 8);
    
    // 4. 检查4位
    tmp = x >> 4;
    bits += (!!tmp) << 2; // 如果高4位有1，加4位
    x = tmp | (x >> 4);
    
    // 5. 检查2位
    tmp = x >> 2;
    bits += (!!tmp) << 1; // 如果高2位有1，加2位
    x = tmp | (x >> 2);
    
    // 6. 检查1位
    tmp = x >> 1;
    bits += !!tmp; // 如果高1位有1，加1位
    
    return bits;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned sign = uf & 0x80000000;        // 提取符号位
    unsigned exp = (uf & 0x7F800000) >> 23; // 提取阶码
    unsigned frac = uf & 0x007FFFFF;        // 提取尾数

    // 判断是否为 NaN 或 Infinity
    if (exp == 0xFF) {
        // NaN 或 Infinity，直接返回原值
        return uf;
    }

    if (exp == 0) {
        // 非规格化数，乘以2相当于左移1位
        frac <<= 1;
        // 检查是否溢出为规格化数
        if (frac & 0x00800000) {
            exp = 1;          // 转换为规格化数，阶码设为1
            frac &= 0x007FFFFF; // 去掉最高位
        }
        // 重新组合
        return sign | (exp << 23) | frac;
    } else {
        // 规格化数，阶码增加1
        exp += 1;
        if (exp == 0xFF) {
            // 阶码溢出为 Infinity
            frac = 0;
        }
        // 重新组合
        return sign | (exp << 23) | frac;
    }
}

/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    // 提取符号位（0或1）
    int sign = uf >> 31;
    
    // 提取阶码（8位）
    int exp = (uf >> 23) & 0xFF;
    
    // 提取尾数（23位）
    int frac = uf & 0x7FFFFF;
    
    // 实际指数 E = exp - 127
    int E = exp - 127;
    
    // 处理特殊情况：NaN 或 Infinity
    if (exp == 255) {
        return 0x80000000u;
    }
    
    // 处理小于1的情况（E < 0）
    if (E < 0) {
        return 0;
    }
    
    // 处理溢出情况（E > 30）
    if (E > 30) {
        return 0x80000000u;
    }
    
    // 规格化数：添加隐含的1
    int mantissa = frac | 0x800000;
    
    int result;
    
    if (E > 23) {
        // E > 23，左移 (E - 23) 位
        result = mantissa << (E - 23);
    } else {
        // E <= 23，右移 (23 - E) 位
        result = mantissa >> (23 - E);
    }
    
    // 应用符号位
    if (sign) {
        result = -result;
    }
    
    return result;
}

/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    // 计算阶码 E = x + 127
    int E = x + 127;
    
    // 判断溢出：E >= 255
    if (E >= 255) {
        // 返回正无穷大：阶码全1，尾数全0
        return 0x7F800000;
    }
    
    // 判断下溢：E <= 0
    if (E <= 0) {
        // 无法表示为规格化数，返回0
        return 0;
    }
    
    // 构造浮点数表示：符号位0，阶码E，尾数0
    unsigned result = (E << 23);
    
    return result;
}

