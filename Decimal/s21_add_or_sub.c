#include "s21_decimal.h"

int s21_add_or_sub(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal* result,
                   int is_sub) {  // сложение или вычитание (в зависимости от
                                  // флага 0-сложение, 1-вычитание)
  s21_big_decimal value_1_big, value_2_big, result_big = {{0}};
  int negate = 0, scale = 0, err = 0,
      sign = s21_getSign(
          value_1);  // флаг необхожимости изм знака, , , знак результата

  s21_decimalToBigDecimal(value_1, &value_1_big);
  s21_decimalToBigDecimal(value_2, &value_2_big);
  s21_normalise(&value_1_big, &value_2_big);

  if (is_sub) {  // если вычитание
    if ((s21_is_greater(value_1, value_2) && !sign) ||
        (s21_is_less(value_1, value_2) &&
         sign)) {  // первое число >|< второго и знак рез окажется полож
      s21_bitwiseSubtraction(value_1_big, value_2_big, &result_big);
    } else {
      s21_bitwiseSubtraction(value_2_big, value_1_big, &result_big);
      negate = 1;
    }
  } else
    s21_bitwiseAddition(value_1_big, value_2_big, &result_big);  // сложение
  scale = s21_bigGetScale(value_1_big);
  sign = s21_getSign(value_1);
  // проверка не превышает ли масштаб максимум и не является ли рез 0
  if (!(s21_bigIsZero(result_big)) || scale > 28) {
    err = s21_correct_overflow(&result_big, scale,
                               sign);  // коррекция переполнения
  } else
    s21_bigSetScale(&result_big, scale);
  s21_bigSetSign(&result_big, sign);
  s21_bigDecimalToDecimal(result_big, result);  // обратно в дец. формат
  if (negate) s21_negate(*result, result);  // инверт знака  если нужно
  return err;
}