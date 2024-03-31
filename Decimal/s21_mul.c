#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_big_decimal value_1_big, value_2_big, result_big = {{0}};
  int scale = 0, sign = 0, err = 0;

  if (!(is_dec_valid(value_1) && is_dec_valid(value_2)) || (result == NULL))
    err = 1;  // infinity
  else {
    s21_decimalToBigDecimal(value_1, &value_1_big);
    s21_decimalToBigDecimal(value_2, &value_2_big);
    sign = s21_getSign(value_1) ^ s21_getSign(value_2);
    scale = s21_bigGetScale(value_1_big) + s21_bigGetScale(value_2_big);
    s21_bitwiseMultiplication(value_1_big, value_2_big, &result_big);

    if (!(s21_bigIsZero(result_big)) || scale > 28) {
      err = s21_correct_overflow(&result_big, scale, sign);
    } else
      s21_bigSetScale(&result_big, scale);
    s21_bigSetSign(&result_big, sign);
    s21_bigDecimalToDecimal(result_big, result);
    if (s21_isZero(*result)) s21_setSign(result, 0);
  }
  return err;
}