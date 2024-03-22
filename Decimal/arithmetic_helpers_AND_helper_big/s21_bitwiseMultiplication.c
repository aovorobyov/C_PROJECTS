#include "s21_decimal.h"

/* 
*  функция выполняет умножение двух чисел s21_big_decimal, используя побитовый подход,
*  где каждый бит b используется для определения, следует ли добавлять a к текущему 
*  значению результата. Этот подход аналогичен тому, как выполняется умножение на бумаге,
*  где каждая цифра второго числа используется для определения, сколько раз нужно сложить
*  первое число.
*  Функция сначала устанавливает цикл for, который выполняет итерацию от старшего бита b
*  (начиная с 32-го семибитного фрагмента, поскольку s21_big_decimal это 256-битный тип
*  данных) до младшего бита. Для каждого бита он проверяет, установлен ли бит, с помощью
*  вспомогательной функции s21_bigGetBit. Если бит не установлен, цикл продолжается до
*  следующего бита.
*  Как только установленный бит найден, функция входит в другой цикл for, который
*  выполняет итерацию от индекса установленного бита до 0. На каждой итерации функция
*  проверяет, установлен ли текущий бит с помощью s21_bigGetBit. Если бит установлен,
*  функция вызывает s21_bitwiseAddition, чтобы добавить к текущему значению результата.
*  Если текущий бит не является старшим битом, функция сдвигает биты результата влево на
*  единицу с помощью s21_shiftLeft.
*/

void s21_bitwiseMultiplication(s21_big_decimal a, s21_big_decimal b,
                               s21_big_decimal* result) {
  int i, j;
  for (i = (32 * 7) - 1; i >= 0 && !s21_bigGetBit(b, i); i--)
    ;
  for (j = i; j >= 0; j--) {
    if (s21_bigGetBit(b, j)) s21_bitwiseAddition(a, *result, result);
    if (j) s21_shiftLeft(result, 1);
  }
}