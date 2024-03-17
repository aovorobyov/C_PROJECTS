#ifndef S21_DECIMAL
#define S21_DECIMAL

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

#include <stdio.h>
#include <stdlib.h>

get_part(int bit_index);  // определение части числа (1, 2, 3) по индексу
get_bit(s21_decimal num, int bit_index);  // бит по индексу

int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // вычитание

#endif  // S21_DECIMAL