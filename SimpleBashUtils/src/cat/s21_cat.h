#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  _Bool b;  // нумерация всех непустных строк
  _Bool e;  // вывод \n как $, подразумевает флаг v
  _Bool n;  // нумерация всех строк
  _Bool s;  // сокращает несколько пустых строк до 1
  _Bool t;  // вывод \t как ^I, подразумевает флаг v
  _Bool v;  // заменяет все символы с учетом ^ и M- нотацией
  int wrong;  // запись ошибочной опции
} Argums;

void error_opt();
void error_alloc();
void error_file(char *filename);
void process(char *filename, Argums *argums);
void parser(int argc, char *argv[], Argums *argums);

void s_func(char *line, int *empty_line_count);
void etv_func(char *line, Argums *argums);
void bn_func(char *line, int *line_num, Argums *argums);

#endif  // S21_CAT_H