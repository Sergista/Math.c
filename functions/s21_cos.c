#include "../s21_math.h"

long double s21_cos(double x) {
  if (S21_ISINF(x)) {
    return S21_NAN;  // Возвращаем S21_NAN, если x - бесконечность
  }

  double eps = 1e-6;
  int n = 1;
  long double result = 1.0;
  long double numerator = 1.0;
  long double denominator = 1.0;
  long double y = 1.0;

  while (s21_fabs(result) > eps) {
    numerator *= x * x;
    denominator *= 2 * n * (2 * n - 1);
    result = numerator / denominator;

    if (n % 2 == 0) {
      y += result;
    } else {
      y -= result;
    }
    n++;
  }

  return y;
}
