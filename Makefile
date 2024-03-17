CC = gcc -Wall -Wextra -Werror -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage -fPIC
OS=$(shell uname -s)
LINUX=-lcheck -lm -lpthread -lrt -lsubunit
MACOS= -lcheck

# ---------------------

all: gcov_report

# ---------------------

s21_math.a :
	$(CC) -c functions/*.c
	ar rc s21_math.a *.o
	rm -rf *.o

test : clean s21_math.a
	checkmk clean_mode=1 tests/test.check > tests/s21_test.c
	clang-format --style=Google -i tests/s21_test.c
ifeq ($(OS), Darwin)
	gcc tests/s21_test.c -o unit_test s21_math.a $(MACOS)
else
	gcc tests/s21_test.c -o unit_test s21_math.a $(LINUX)
endif
	./unit_test

gcov_report : test
ifeq ($(OS), Darwin)
	gcc $(GCOVFLAGS) tests/*.c functions/*.c -o gcov_report $(MACOS)
else
	gcc $(GCOVFLAGS) tests/*.c functions/*.c -o gcov_report $(LINUX)
endif
	./gcov_report
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o report/ Coverage_Report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	open ./report/index-sort-f.html

# ---------------------

style:
	clang-format --style=Google -i functions/*.c *.h *.c

check_style:
	clang-format --style=Google -n functions/*.c *.h *.c

cpp:
	cppcheck --enable=all --inconclusive --force --language=c --std=c11 --suppress=missingIncludeSystem functions/*.c *.h tests/*.c *.c

rebuild: clean all

clean:
	rm -rf *.a *.o *.gcno ./report *.out gcov_report unit_test tests/*.c