#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  if (get_sign(value_1) && !get_sign(value_2))
    res = 1;
  else if (get_sign(value_1) && get_sign(value_2)) {
    if (get_scale(value_1) < get_scale(value_2))
      res = 1;
    else if (get_scale(value_1) == get_scale(value_2)) {
      for (int i = 0; i < 3; i++) {
        if (value_1.bits[i] > value_2.bits[i]) {
          res = 1;
          break;
        }
      }
    }
  } else if (!get_sign(value_1) && !get_sign(value_2)) {
    if (get_scale(value_1) > get_scale(value_2))
      res = 1;
    else if (get_scale(value_1) == get_scale(value_2)) {
      for (int i = 0; i < 3; i++) {
        if (value_1.bits[i] < value_2.bits[i]) {
          res = 1;
          break;
        }
      }
    }
  }
  return res;
}