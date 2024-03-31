#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal temp = {{0}};
  int error = 0;
  if (result != NULL) {
    *result = value;
    s21_big_decimal value_big;
    s21_decimalToBigDecimal(value, &value_big);
    int scale = s21_getScale(value);
    while (scale) {
      temp = s21_bigDiv10(&value_big);
      scale--;
    }
    if (s21_getSign(value) && !s21_bigIsZero(temp)) {
      s21_bitwiseAddition(value_big, one, &value_big);
    }
    s21_bigDecimalToDecimal(value_big, result);
    s21_setSign(result, s21_getSign(value));
    s21_setScale(result, 0);
  } else {
    error = 1;
  }
  return error;
}