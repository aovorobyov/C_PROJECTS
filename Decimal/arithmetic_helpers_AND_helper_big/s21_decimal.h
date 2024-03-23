#include <stdio.h>

#define SCALE 0x00ff0000
#define MINUS 0x80000000

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

void s21_normalise(s21_big_decimal* a, s21_big_decimal* b);
int s21_bigGetScale(s21_big_decimal num);
void s21_bigSetScale(s21_big_decimal* num, int scale_value);
void s21_mul10(s21_big_decimal* decimal);
void s21_shiftLeft(s21_big_decimal* num, int shift_value);
int s21_bigGetBit(s21_big_decimal num, int bit_index);
void s21_bigSetBit(s21_big_decimal* num, int bit_index, unsigned value);
void s21_printBigDecimal(s21_big_decimal decimal);
int s21_bigIsZero(s21_big_decimal num);
void s21_bigToZero(s21_big_decimal* num);
int s21_bigGetSign(s21_big_decimal num);
void s21_bigSetSign(s21_big_decimal* num, int sign_value);
void s21_decimalToBigDecimal(s21_decimal decimal, s21_big_decimal* big_decimal);
void s21_bigDecimalToDecimal(s21_big_decimal big_decimal, s21_decimal* decimal);
int s21_isOverflow(s21_big_decimal decimal);
void s21_bitwiseAddition(s21_big_decimal a, s21_big_decimal b,
                         s21_big_decimal* result);
void s21_bitwiseSubtraction(s21_big_decimal a, s21_big_decimal b,
                            s21_big_decimal* result);
void s21_bitwiseMultiplication(s21_big_decimal a, s21_big_decimal b,
                               s21_big_decimal* result);
void s21_bitwiseDivision(s21_big_decimal a, s21_big_decimal b,
                         s21_big_decimal* result);
s21_big_decimal s21_divide(s21_big_decimal a, s21_big_decimal b,
                           s21_big_decimal* result);
s21_big_decimal s21_bigDiv10(s21_big_decimal* decimal);