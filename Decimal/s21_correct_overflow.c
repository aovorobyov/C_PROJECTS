#include "s21_decimal.h"

int s21_correct_overflow(s21_big_decimal* result_big, int scale, int sign) {
  s21_big_decimal temp = {{0}};  // хранение промежут рез
  int sum = 0, err = 0;  // суммирование сброшенных цифр при уменьшении масштаба
  while (scale > 28) {
    temp = BigDiv10(result_big);
    scale--;
    sum += temp.bits[0];
  }
  while ((IsOverflow(*result_big)) && (scale > 0)) {
    temp = BigDiv10(result_big);
    scale--;
    sum += temp.bits[0];
  }
  if (temp.bits[0] == 5 &&
      sum > 5)  // если посл цифра 5 и сумма сброш цифр > 5 то применяем мат окр
    MathRounding(result_big, temp);
  else
    BankRounding(result_big, temp);
  if (((IsOverflow(*result_big)) && (scale == 0)) ||
      (scale >
       28)) {  // если все еще переполнение при масштабе 0 или >28, то ошибка
    err = 1 + sign;  // ошибка бесконечности со знаком
    BigToZero(result_big);  // очищаем рез
  }
  BigSetScale(result_big,
              scale);  // устанавливает масштаб в соотв с текущ scale
  return err;
}