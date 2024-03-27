#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal temp = {{0}};
  int error = 0;
  if (result != NULL) {
    *result = value;
    s21_big_decimal value_big;
    DecimalToBigDecimal(value, &value_big);
    int scale = GetScale(value);
    while (scale) {
      temp = BigDiv10(&value_big);
      scale--;
    }
    if (GetSign(value) && !BigIsZero(temp)) {
      BitwiseAddition(value_big, one, &value_big);
    }
    BigDecimalToDecimal(value_big, result);
    SetSign(result, GetSign(value));
    SetScale(result, 0);
  } else {
    error = 1;
  }
  return error;
}