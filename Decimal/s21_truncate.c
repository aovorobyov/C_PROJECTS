#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result != NULL) {
    int scale = s21_getScale(value);
    int sign = s21_getSign(value);
    if (s21_isZero(value)) {
      sign = 0;
      scale = 0;
    } else {
      while ((scale) && !(s21_isZero(value))) {
        s21_div10(&value);
        scale--;
      }
    }
    *result = value;
    s21_setSign(result, sign);
    s21_setScale(result, scale);
  } else {
    error = 1;
  }
  return error;
}