#include "s21_decimal.h"

// 1 - отрицательное число; 0 - положительное
int s21_getSign(s21_decimal num) { return (num.bits[3] & MINUS) ? 1 : 0; }