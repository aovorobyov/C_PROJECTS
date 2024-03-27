#include "s21_decimal.h"

int set_scale(s21_decimal *num, unsigned int scale) {
  int res = 1;
  if (scale <= 28)
    num->bits[3] |= (scale << 16);
  else
    res = 0;
  return res;
}