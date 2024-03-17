#include "../s21_math.h"

long double s21_ceil(double x) {
  long double res = (long int)x;
  if (x < -9e+18)
    res = MINUS_INF;
  else if (x > 9e+18)
    res = PLUS_INF;
  else if (x > 0 && x != res) {
    res += 1;
  }

  return res;
}