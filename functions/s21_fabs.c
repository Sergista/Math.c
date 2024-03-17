#include "../s21_math.h"

long double s21_fabs(double x) {
  long double result;
  // Проверка на отрицательную бесконечность
  if (x < 0) {
    // Обработка краевого случая: возвращаем -x
    result = -x;
  } else {
    // В остальных случаях возвращаем x (включая положительную бесконечность и
    // неотрицательные числа)
    result = x;
  }
  return result;
}