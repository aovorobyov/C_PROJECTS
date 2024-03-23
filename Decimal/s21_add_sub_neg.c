#include "s21_decimal.h"

int s21_add_sub_neg(s21_decimal negative, s21_decimal positive,
                    s21_decimal* result, int is_sub) {
  int err = 0;
  s21_decimal value_neg = {{0}};  // положит представление отр числа
  s21_negate(negative, &value_neg);  // меняем отр в положит

  if (is_sub) {  // вычитание
    if (s21_is_greater(
            value_neg,
            positive)) {  // если абсол. значение отр числа больше полож
      err = s21_add_or_sub(value_neg, positive, result,
                           1);  // выполнить вычитание
      s21_negate(
          *result,
          result);  // меняем знак рез, т.к. отр число было больше по модулю
    } else
      err = s21_add_or_sub(positive, value_neg, result, 1);
  } else
    err = s21_add_or_sub(positive, value_neg, result, 0);  // сложение
  return err;
}