#include "s21_decimal.h"

get_part(int bit_index) {
  int part;

  if (bit_index < 32) part = 0;
  if (bit_index >= 32 && bit_index < 64) part = 1;
  if (bit_index >= 64 && bit_index < 96) part = 2;

  return part;
}

get_bit(s21_decimal num, int bit_index) {
  int part = get_part(bit_index);
  bit_index %= 32;

  return (num.bits[part] & (1 << bit_index));
}