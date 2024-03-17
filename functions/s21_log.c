#include "../s21_math.h"

long double s21_log(double x) {
  long double step = 1, sum = 0;
  if (x < 0)
    sum = S21_NAN;
  else if (x != x)
    sum = S21_NAN;
  else if (x == PLUS_INF)
    sum = PLUS_INF;
  else if (x == 0)
    sum = MINUS_INF;
  else {
    x = (x - 1) / (x + 1);
    for (long n = 1; s21_fabs(step *= x) > EPS && n < S21_INF; n++) {
      sum += step;
      step *= x * (2 * n - 1) / (2 * n + 1);
    }
  }
  return 2 * sum;
}
