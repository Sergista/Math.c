# Проект "S21 Math Library"

Этот проект содержит библиотеку функций для математических операций и тесты для проверки их правильности.

## Сборка проекта

Для сборки проекта используется компилятор GCC с следующими опциями:

```
CC = gcc -Wall -Wextra -Werror -std=c11
```

Дополнительные флаги для сборки с поддержкой gcov:

```
GCOVFLAGS = -fprofile-arcs -ftest-coverage -fPIC
```

## Зависимости

- Для Linux:
    - `libcheck`
    - `libm`
    - `libpthread`
    - `librt`
    - `libsubunit`

- Для MacOS:
    - `libcheck`

## Сборка библиотеки

Для сборки библиотеки `s21_math.a` выполните следующую команду:

```
make s21_math.a
```

## Запуск тестов

Для запуска тестов выполните команду:

```
make test
```

## Генерация отчета о покрытии кода

Для генерации отчета о покрытии кода выполните команду:

```
make gcov_report
```

## Проверка стиля кода

Для проверки стиля кода выполните команду:

```
make check_style
```

## Очистка сборочных файлов

Для очистки сборочных файлов выполните команду:

```
make clean
```

## Предупреждения

- Этот проект использует переменную окружения `uname -s` для определения операционной системы. Пожалуйста, убедитесь, что она доступна на вашей системе.

- Возможно, потребуется установка дополнительных библиотек для корректной сборки и выполнения тестов.
