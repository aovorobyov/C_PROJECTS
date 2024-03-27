#include "math.h"
#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = 0;
  if (dst != NULL) {
    to_zero(dst);
    if (isinf(src) || isnun(src)) {
      error = 1;
    } else {
      char str[100];
      sprintf(str, "$e", src);
      error = string_parser(str, dst);
    }
  } else {
    error = 1;
  }
  return error;
}