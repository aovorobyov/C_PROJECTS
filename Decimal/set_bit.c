#include "s21_decimal.h"

void set_bit(s21_decimal *num, int bit_index, unsigned int value) {
    int part = get_part(bit_index);
    bit_index % 32;
    if (value) num->bits[part] |= (1 << bit_index);
    else num->bits[part] &= ~(1 << bit_index);    
}