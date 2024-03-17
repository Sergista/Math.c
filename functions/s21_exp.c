#include "../s21_math.h"

long double s21_exp(double x) {
  long double result = 0;
  long double absoluteX = s21_fabs(x);

  if (x == -S21_INF) {
    result = 0;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x > 710) {
    result = S21_INF;
  } else if (x < -600) {
    result = 0;
  } else if (x == 0.0 || -0.0) {
    result = 1;
  } else {
    long double sum = 1 + absoluteX, an = absoluteX, n = 1;

    while (an > 1e-7) {
      an *= absoluteX / (n + 1);
      sum += an;
      n++;
    }

    if (x < 0) {
      result = 1 / sum;
    } else {
      result = sum;
    }
  }

  return result;
}
