#ifndef S21_DECIMAL
#define S21_DECIMAL

#define SCALE 0x00ff0000
#define MINUS 0x80000000
#define ODD 0x00000001

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

typedef struct {
  int length;
  int scale;
  int exponent;
  int expSign;
} DecimalString;

#include <stdio.h>
#include <math.h>

int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // corriele
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // corriele
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // corriele
int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  // corriele
int s21_add_sub_neg(s21_decimal negative, s21_decimal positive,
                    s21_decimal* result,  // corriele
                    int is_sub);
int s21_add_or_sub(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal* result,  // corriele
                   int is_sub);
int s21_correct_overflow(s21_big_decimal* result_big, int scale,
                         int sign);  // corriele
int s21_getSign(s21_decimal value);
void s21_setSign(s21_decimal* num, int sign_value);
int s21_getBit(s21_decimal num, int bit_index);
void s21_setBit(s21_decimal* num, int bit_index, unsigned value);
int s21_getPart(int num);
void s21_setScale(s21_decimal* num, int scale_value);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_isZero(s21_decimal num);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
void s21_toZero(s21_decimal* num);
int is_dec_valid(s21_decimal decimal);

int s21_stringParser(char* str, s21_decimal* dst);
void s21_bankRounding(s21_big_decimal *decimal, s21_big_decimal rem);
void s21_mathRounding(s21_big_decimal *decimal, s21_big_decimal rem);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_compare(s21_big_decimal a, s21_big_decimal b);
int s21_getScale(s21_decimal num);
s21_decimal s21_div10(s21_decimal *decimal);
int s21_floor(s21_decimal value, s21_decimal *result);
void s21_transform(s21_big_decimal *whole, DecimalString decStr, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_truncate(s21_decimal value, s21_decimal *result);

void s21_normalise(s21_big_decimal* a, s21_big_decimal* b);
int s21_bigGetScale(s21_big_decimal num);
void s21_bigSetScale(s21_big_decimal* num, int scale_value);
void s21_mul10(s21_big_decimal* decimal);
void s21_shiftLeft(s21_big_decimal* num, int shift_value);
int s21_bigGetBit(s21_big_decimal num, int bit_index);
void s21_bigSetBit(s21_big_decimal* num, int bit_index, unsigned value);
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

#endif  // S21_DECIMAL