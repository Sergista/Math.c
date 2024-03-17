#include "../s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  if (S21_ISNAN(x)) {
    result = S21_NAN;  // Возвращаем S21_NAN для NaN
  } else if (x > 1.0 || x < -1.0) {
    result = S21_NAN;  // Возвращаем S21_NAN для значений вне [-1, 1]
  } else if (x == 1.0) {
    result = 0.0;  // acos(1) = 0
  } else if (x == -1.0) {
    result = PI;  // acos(-1) = π
  } else {
    result = PI / 2 - s21_asin(x);
  }

  return result;
}