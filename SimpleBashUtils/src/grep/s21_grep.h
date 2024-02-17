#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  _Bool e;  // шаблон
  _Bool i;  // игнорирует различия регистра
  _Bool v;  // инвертирует смысл поиска соответствий
  _Bool c;  // выводит только количество совпадающих строк
  _Bool l;  // выводит только совпадающие файлы
  _Bool n;  // предваряет каждую строку вывода номером строки из файла ввода
  _Bool h;  // выводит совпадающие строки, не предваряя их именами файлов
  _Bool s;  // подавляет сообщения об ошибках о несуществующих или нечитаемых
            // файлах
  _Bool f;  // получает регулярные выражения из файла
  _Bool o;  // печатает только совпадающие (непустые) части совпавшей строки
  int wrong;      // запись ошибочной опции
  char *pattern;  // хранение шаблона
} Argums;

void error_alloc();
void error_pattern(char *pattern);
void error_file(char *filename);
void add_pattern(Argums *argums, char *new_pattern);
void scan_file(Argums *argum, char *new_file);
void parser(int argc, char *argv[], Argums *argums);
void print_line(int f_count, Argums *argums, char *filename, int strnum,
                char *line /*, size_t len*/);
void print_summary(char *filename, int f_count, int counter, Argums *argums);
void process(char *filename, Argums *argums, int f_count);