#include "s21_decimal.h"

int s21_getScale(s21_decimal num) {
  int scale = (num.bits[3] & SCALE) >> 16;
  return scale;
}