#include "s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  int res;
  s21_big_decimal big_a = {{0}};
  s21_big_decimal big_b = {{0}};

  s21_decimalToBigDecimal(a, &big_a);
  s21_decimalToBigDecimal(b, &big_b);
  res = s21_compare(big_a, big_b);

  return res == 0 ? 1 : 0;
}