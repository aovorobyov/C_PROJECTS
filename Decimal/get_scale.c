#include "s21_decimal.h"

int get_scale(s21_decimal num) {
  int res = 0b11111111;

  return (res & (num.bits[3] >> 16));
}