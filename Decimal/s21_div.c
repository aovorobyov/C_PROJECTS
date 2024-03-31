#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_big_decimal value_1_big, value_2_big, result_big = {{0}};
  int scale = 0, scale1 = 0, scale2 = 0, sign = 0, err = 0;

  if (!(is_dec_valid(value_1) && is_dec_valid(value_2)) || (result == NULL))
    err = 1;  // infinity
  else if (s21_isZero(value_2))
    err = 3;  // div by zero
  else {
    s21_decimalToBigDecimal(value_1, &value_1_big);
    s21_decimalToBigDecimal(value_2, &value_2_big);
    s21_bigSetSign(&value_1_big, 0);
    s21_bigSetSign(&value_2_big, 0);
    s21_bigSetScale(&value_1_big, 0);
    s21_bigSetScale(&value_2_big, 0);
    scale1 = s21_getScale(value_1);
    scale2 = s21_getScale(value_2);
    sign = s21_getSign(value_1) ^ s21_getSign(value_2);

    while (scale1 < scale2) {
      s21_mul10(&value_1_big);
      scale1++;
    }
    scale = scale1 - scale2;
    s21_bitwiseDivision(value_1_big, value_2_big, &result_big);
    scale += s21_bigGetScale(result_big);

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