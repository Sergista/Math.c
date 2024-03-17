#include "../s21_math.h"

long double s21_asin(double x) {
  long double result = x;
  long double tmp = x;

  for (long long i = 1; s21_fabs(tmp) > EPS; i++) {
    if (x < -1 || x > 1) {
      result = S21_NAN;
      break;
    }
    if (x == 1 || x == -1) {
      result = (PI / 2) * x;
      break;
    }
    tmp *= x * x * (2 * i - 1) * (2 * i - 1) / ((2 * i + 1) * 2 * i);
    result += tmp;
  }
  return result;
}
