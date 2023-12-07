CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11

C_FILES = s21_*.c
O_FILES = s21_*.o

all: clean s21_decimal.a

clean:
		rm -rf *.o *.gch *.out *.gcno *.gcda *.info *.gcov *.a
		rm -rf report/

test: s21_decimal.a
		${CC} ${FLAGS} test.c tests/test_*.c s21_decimal.a -g `pkg-config --cflags --libs check` -lm

s21_decimal.a: s21_decimal.o
		ar rc s21_decimal.a ${O_FILES}
		ranlib s21_decimal.a

gcov_report:
		${CC} -fprofile-arcs -ftest-coverage ${FLAGS} ${C_FILES} tests/test_*.c test.c -g `pkg-config --cflags --libs check` -lm
		./a.out
		lcov -t "coverage_report" -o coverage.info -c -d .
		genhtml -o report coverage.info

s21_decimal.o:
		${CC} ${FLAGS} -O -c ${C_FILES}

style:
		cppcheck *.h *.c
		clang-format -style=Google -n *.c *.h
		clang-format -style=Google -n tests/*.c tests/*.h

leaks: test
ifeq ($(shell uname -s), Linux)
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --undef-value-errors=yes --quiet ./a.out
else
	CK_FORK=no leaks --atExit -- ./a.out
endif
