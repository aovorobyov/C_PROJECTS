#include "s21_decimal.h"

void set_sign(s21_decimal *num, unsigned int sign) {
    if (sign) num->bits[3] |= 1;
    else num->bits[3] &= ~(1);  
}