#include "s21_decimal.h"

int s21_getBit(s21_decimal num, int bit_index) {
  int part = s21_getPart(bit_index);
  bit_index %= 32;
  return (num.bits[part] &= 1 << bit_index) >> bit_index;
}