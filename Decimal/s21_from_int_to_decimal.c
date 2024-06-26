#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  if (dst != NULL) {
    s21_toZero(dst);
    if (src < 0) {
      s21_setSign(dst, 1);
      src *= -1;
    }
    dst->bits[0] = src;
  } else {
    error = 1;
  }
  return error;
}
