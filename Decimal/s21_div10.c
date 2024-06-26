#include "s21_decimal.h"

s21_decimal s21_div10(s21_decimal *decimal) {
  s21_decimal reminder = {{0}};
  s21_big_decimal res = {{0}};
  s21_big_decimal rem = {{0}};
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal big_dec = {{0}};

  s21_decimalToBigDecimal(*decimal, &big_dec);
  rem = s21_divide(big_dec, ten, &res);
  s21_bigDecimalToDecimal(res, decimal);
  s21_bigDecimalToDecimal(rem, &reminder);
  return reminder;
}