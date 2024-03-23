#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_big_decimal value_1_big, value_2_big, result_big = {{0}};
  int scale = 0, scale1 = 0, scale2 = 0, sign = 0, err = 0;

  if (!(IsDecValid(value_1) && IsDecValid(value_2)) || (result == NULL))
    err = 1;  // infinity
  else if (IsZero(value_2))
    err = 3;  // div by zero
  else {
    DecimalToBigDecimal(value_1, &value_1_big);
    DecimalToBigDecimal(value_2, &value_2_big);
    BigSetSign(&value_1_big, 0);
    BigSetSign(&value_2_big, 0);
    BigSetScale(&value_1_big, 0);
    BigSetScale(&value_2_big, 0);
    scale1 = GetScale(value_1);
    scale2 = GetScale(value_2);
    sign = GetSign(value_1) ^ GetSign(value_2);

    while (scale1 < scale2) {
      Mul10(&value_1_big);
      scale1++;
    }
    scale = scale1 - scale2;
    BitwiseDivision(value_1_big, value_2_big, &result_big);
    scale += BigGetScale(result_big);

    if (!(BigIsZero(result_big)) || scale > 28) {
      err = s21_correct_overflow(&result_big, scale, sign);
    } else
      BigSetScale(&result_big, scale);
    BigSetSign(&result_big, sign);
    BigDecimalToDecimal(result_big, result);
    if (IsZero(*result)) SetSign(result, 0);
  }
  return err;
}