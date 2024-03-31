#include "s21_decimal.h"

void s21_setBit(s21_decimal* num, int bit_index, unsigned value) {
  int part = s21_getPart(bit_index);
  bit_index %= 32;
  if (value) num->bits[part] |= (1 << bit_index);
  if (!value) num->bits[part] &= ~(1 << bit_index);
}