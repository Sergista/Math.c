#ifndef S21_MATH_H
#define S21_MATH_H

#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NAN (0. / 0.)
#define PI 3.1415926535897932384626433832795
#define E 2.7182818284590452353602874713527
#define EPS 1e-17
#define PLUS_INF 1. / 0.
#define MINUS_INF -1. / 0.
#define S21_INF 1 / 0.0
#define S21_LN2 0.6931471805599453

#define S21_ISNAN(x) (x != x)
#define S21_ISINF(x) ((x == S21_INF) || (x == -S21_INF))

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_pow(double base, double exp);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);

#endif
