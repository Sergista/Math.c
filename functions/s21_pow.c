#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1;
  if (s21_fmod(exp, 1.0) == 0 && exp > 0)
    for (int i = 0; i < (int)exp; i++) result *= base;
  else {
    if (s21_fabs(exp) == 0.0)
      result = 1;
    else if (base == 0.0 && exp < 0 && s21_fmod(exp, 1.) == 0. &&
             s21_fmod(exp, 2.0) != 0)
      result = S21_INF;
    else if (s21_fabs(base) == 0.0 && exp < 0 &&
             (s21_fmod(exp, 1.0) != 0 || s21_fmod(exp, 2.0) == 0))
      result = S21_INF;
    else if ((base == -1 || base == 1) && (S21_ISINF(exp) || S21_ISNAN(exp)))
      result = 1;
    else if (base == 0)
      result = 0;
    else if (s21_fabs(base) < 1 && S21_ISINF(exp) && exp < 0)
      result = S21_INF;
    else if (s21_fabs(base) > 1 && S21_ISINF(exp) && exp < 0)
      result = 0;
    else if (s21_fabs(base) < 1 && S21_ISINF(exp) && exp > 0)
      result = 0;
    else if (s21_fabs(base) > 1 && S21_ISINF(exp) && exp > 0)
      result = S21_INF;
    else if (S21_ISINF(base) && (exp < 0))
      result = 0;
    else if (S21_ISINF(base) && base < 0 && exp > 0) {
      result = S21_INF;
    } else if (base < 0 && exp != (int)exp)
      result = -S21_NAN;
    else if (S21_ISNAN(base) || S21_ISNAN(exp))
      result = S21_NAN;
    else if (base > 0)
      result = s21_exp(exp * s21_log(base));
    else if (base < 0) {
      result = s21_exp(exp * s21_log(-base));
    }
  }

  return result;
}
