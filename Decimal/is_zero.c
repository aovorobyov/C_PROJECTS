#include "s21_decimal.h"

int is_zero(s21_decimal num) { // выдает 1, если число равно нулю, иначе - 0;
    int res = 0;
    if (!num.bits[0] && !num.bits[1] && !num.bits[2]) res = 1;
    return res;
}