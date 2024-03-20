#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
    for (int i = 0; i < 4; i++) result->bits[i] = value.bits[i];
    if (get_sign(value)) result->bits[3] &= ~1;  
    else result->bits[3] |= 1;
    return 0;
}