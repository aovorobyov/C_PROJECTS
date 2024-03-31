#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  s21_decimal max_int1 = {{0x7FFFFFFF, 0, 0, 0}};
  s21_decimal max_int2 = {{0x7FFFFFFF, 0, 0, 0x80000000}};
  if (s21_is_less_or_equal(src, max_int1) && dst != NULL &&
      s21_is_greater_or_equal(src, max_int2)) {
    s21_truncate(src, &src);
    *dst = src.bits[0];
    if (s21_getSign(src)) {
      *dst *= -1;
    }
  } else {
    error = 1;
  }
  return error;
}