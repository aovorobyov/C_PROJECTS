#include "s21_decimal.h"

/* 
*  Функция устанавливает масштаб числа типа s21_big_decimal равным значению scale_value.
*  Первая строка функции устанавливает 32й бит 8го значения int в 0 для очищения 
*  знакового бита перед установкой значения масштаба.
*  Вторая строка функции устанавливает 33й бит 8го значения int в значение scale_value, 
*  сдвинутое влево на 16 бит, сохраняя значение scale_value в битах с 17 по 32 8го int
*/

void s21_bigSetScale(s21_big_decimal* num, int scale_value) {
  num->bits[7] &= MINUS;
  num->bits[7] |= (scale_value << 16);
}