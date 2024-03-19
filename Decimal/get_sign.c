#include "s21_decimal.h"

int get_sign(s21_decimal value) {
    return value.bits[3] & (1 << 0) ? 1 : 0; // 1 - отрицательное число; 0 - положительное
}