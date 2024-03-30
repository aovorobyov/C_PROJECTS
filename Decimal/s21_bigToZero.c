#include "s21_decimal.h"

/* 
*  Функция устанавливает значение 0 для числа s21_big_decimal.
*  Функция использует цикл for для перебора каждого элемента массива битов структуры 
*  s21_big_decimal. Для каждого элемента массива функция устанавливает
*  его значение в 0 с помощью оператора присваивания =
*/

void s21_bigToZero(s21_big_decimal* num) {
  for (int i = 0; i <= 7; i++) {
    num->bits[i] = 0;
  }
}