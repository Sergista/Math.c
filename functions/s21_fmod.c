#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double rem;

  if (y == 0.0) {
    rem = S21_NAN;  // Возвращаем S21_NAN, так как деление на 0 не определено
  } else {
    long double q = x / y;
    long double w = (long int)q;
    rem = x - w * y;
  }

  return rem;
}