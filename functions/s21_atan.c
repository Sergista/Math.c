#include "../s21_math.h"

long double s21_atan(double x) {
  long double sum = x, an = x, n = 1, sign = 1, oldX = 0;

  if (x > 1 || x < -1) {
    oldX = x;
    x = 1 / x;
    sum = x;
    an = x;

    if (oldX < -1) {
      sign *= -1;
    }
  }

  while (an > 1e-7 || an < -1e-7) {
    an *= ((-1 * (x * x)) * (2 * n - 1)) / (2 * n + 1);
    sum += an;
    n++;
  }

  if (oldX > 1 || oldX < -1) {
    sum = sign * (PI / 2L) - sum;
  }

  return sum;
}