CC= gcc -Werror -Wall -Wextra -std=c11 -gcc
TEST= ./unit_tests/test_*.c

ifeq (shell name, Linux)
	LFLAGS= -lcheck -lsubunit -pthread -lrt -lm
else
	LFLAGS= -lcheck
endif

all: s21_decimal.a test gcov_report

s21_decimal.a:
	$(CC) -c s21_*.c
	ar rsc ./s21_decimal.a *.o

test: s21_decimal.a
	$(CC) s21_*.c ./s21_decimal.a $(TEST) $(LFLAGS) -o test
	./test

gcov_report: s21_decimal.a
	$(CC) --coverage s21_*.c $(TEST) $(LFLAGS) -o gcov_test
	./gcov_test
	lcov -t "gcov-test" -o test_report.info -c -d .
	genhtml -o report test_report.info
	open ./report/index.html

clean:
	rm -rf *.a *.gch *.o *.gcno *.gcda gcov_test test_report.info report test

reduild:
	make clean
	make all

clang_n:
	clang-format -style=Google -n *.[ch]

clang_i:
	clang-format -style=Google -i *.[ch]
