CC= gcc -Werror -Wall -Wextra -std=c11 -g
TEST= ./tests/test*.c
LFLAGS= -lcheck

# ifeq (shell name, Linux)
# 	LFLAGS= -lcheck -lsubunit -pthread -lrt -lm
# else
# 	LFLAGS= -lcheck
# endif

all: s21_decimal.a test gcov_report

s21_decimal.a:
	$(CC) -c s21_*.c
	ar rsc ./s21_decimal.a *.o

test: s21_decimal.a
	$(CC) s21_*.c $(TEST) $(LFLAGS) -o test
	./test

gcov_report: s21_decimal.a
	$(CC) --coverage s21_*.c $(TEST) $(LFLAGS) -o gcov_test
	./gcov_test
	lcov -t "gcov-test" -o test_report.info -c -d .
	genhtml -o report test_report.info
	open ./report/index.html

clean:
	rm -rf *.a *.gch *.o *.gcno *.gcda gcov_test test_report.info report test

rebuild:
	make clean
	make all

clang_n:
	cd unit_tests
	clang-format -style=Google -n *.[ch]
	cd ../
	clang-format -style=Google -n *.[ch]

clang_i:
	cd unit_tests
	clang-format -style=Google -i *.[ch]
	cd ../
	clang-format -style=Google -i *.[ch]
