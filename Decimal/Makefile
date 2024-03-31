FLAGS = -Wall -Wextra -Werror -std=c11
EXECUTABLES := lcov
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	CFLAGS := -lcheck -lsubunit -lm
	COMMAND := xdg-open
	EXECUTABLES += xdg-open
endif
ifeq ($(UNAME_S),Darwin)
	CFLAGS := -lcheck
	COMMAND := open
endif

all: s21_decimal.a

s21_decimal.a: clean
	gcc -c $(FLAGS) s21_*.c
	ar -rcs s21_decimal.a *.o
	rm *.o

test: s21_decimal.a
	gcc $(FLAGS) tests/*.c $(CFLAGS) s21_decimal.a -o main

gcov_report: clean exec_check
	cd tests/ && gcc $(FLAGS) --coverage ../s21_*.c test*.c $(CFLAGS) -o s21_test
	-cd tests/ && ./s21_test
	cd tests/ && lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report tests/s21_test.info
	rm -f tests/*.g*
	$(COMMAND) report/index.html

exec_check:
	@:
	$(foreach exec, $(EXECUTABLES),\
	$(if $(shell command -v $(exec) 2> /dev/null),, $(info Error: Install '$(exec)')))

clean:
	rm -f *.a main tests/*.g* a.out tests/*.info tests/s21_test *.g* s21_test*
	rm -rf report/
