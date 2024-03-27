#include "s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  int res;
  s21_big_decimal big_a = {{0}};
  s21_big_decimal big_b = {{0}};

  DecimalToBigDecimal(a, &big_a);
  DecimalToBigDecimal(b, &big_b);
  res = compare(big_a, big_b);

  if (res < 0) {
    return 1;
  } else if (res > 0) {
    return 0;
  }
}