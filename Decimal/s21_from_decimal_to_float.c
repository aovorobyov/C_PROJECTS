#include "math.h"
#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  int power = 0;
  int scale = get_scale(src);
  int sign = get_sign(src);

  if (dst != NULL) {
    double temp1 = 0.;
    double temp2 = 0.;
    double ten = 10;
    s21_decimal rem = {{0}};

    while (!is_zero(src)) {
      rem = Div10(&src);
      temp1 = rem.bits[0];
      temp2 *= pow(10, power);
      temp2 += temp1;
      power++;
    }
    while (scale--) {
      temp2 /= 10;
    }
    if (sign) {
      temp2 *= -1;
    }
    *dst = (float)temp2;
  } else {
    error = 1;
  }
  return error;
}