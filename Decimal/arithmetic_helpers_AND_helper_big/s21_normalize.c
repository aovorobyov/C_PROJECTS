#include "s21_decimal.h"

/* 
*  Функция нормализации принимет в качестве входных данных два числа
*  типа s21_big_decimal, определяет какое из них имеет больший масштаб и
*  нормализует их так, чтобы они имели одинаковый масштаб.
*  Вначале инициализируем меньшую переменную нулями и объявляем
*  переменные для хранения масштабов входных чисел и разницы между ними.
*  Далее определяется число с наибольшим масштабом и устанавливаем
*  масштаб в это значение. Вычисляем разницу между масштабами 2х чисел,
*  сохраняем ее в diff. Затем меньшей переменной присваивается меньшее
*  из 2х входных чисел, масштаб устанавливаем с помощью s21_bigSetScale.
*  В цикле вызываем s21_mul10 для меньшего числа, что приводит к сдвигу
*  десятичной точки на 1у позицию вправо. В финале проверяем, какое из 2х
*  входных чисел имеет больший масштаб и устанавливаем для него меньшее значение.
*/

void s21_normalise(s21_big_decimal* a, s21_big_decimal* b) {
  s21_big_decimal lesser = {{0}};
  int scale = 0, diff = 0, scale1 = s21_bigGetScale(*a), scale2 = s21_bigGetScale(*b);
  scale = scale1 > scale2 ? scale1 : scale2;
  diff = scale1 > scale2 ? (scale1 - scale2) : (scale2 - scale1);
  lesser = scale1 > scale2 ? *b : *a;
  s21_bigSetScale(&lesser, scale);
  for (int i = 0; i < diff; i++) {
    s21_mul10(&lesser);
  }
  if (scale1 > scale2)
    *b = lesser;
  else
    *a = lesser;
}