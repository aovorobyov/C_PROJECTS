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

int get_scale(s21_decimal num);  // определение плавающей точки
int get_part(int bit_index);  // определение части числа (1, 2, 3) по индексу
int get_bit(s21_decimal num, int bit_index);  // бит по индексу
int get_sign(s21_decimal value);
void set_bit(s21_decimal *num, int bit_index, unsigned int value);
int set_scale(s21_decimal *num, unsigned int scale);
int s21_negate(s21_decimal value, s21_decimal *result);
int is_zero(s21_decimal num);
void to_zero(s21_decimal *num);
void SetSign(s21_decimal *num, int sign_value);

int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // вычитание

#endif  // S21_DECIMAL