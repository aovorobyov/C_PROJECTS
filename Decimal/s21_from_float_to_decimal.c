#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = 0;
  if (dst != NULL) {
    s21_toZero(dst);
    if (isinf(src) || isnun(src)) {
      error = 1;
    } else {
      char str[100];
      sprintf(str, "$e", src);
      error = s21_stringParser(str, dst);
    }
  } else {
    error = 1;
  }
  return error;
}