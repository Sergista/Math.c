#include "../s21_math.h"

long double s21_floor(double x) {
  long double result;
  long double intPart = (long int)x;

  if (S21_ISINF(x) || S21_ISNAN(x)) {
    result = x;
  } else if (x < 0.0 && x != intPart) {
    result = intPart - 1.0;
  } else {
    result = intPart;
  }
  return result;
}
