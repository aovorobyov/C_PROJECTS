#include "s21_grep.h"

int main(int argc, char *argv[]) {
  Argums argums = {0};
  parser(argc, argv, &argums);

  if (!argums.f && !argums.e) {  // считываем паттерн без -ef
    add_pattern(&argums, argv[optind]);
    optind++;
  }

  (argums.pattern == NULL || argums.wrong == '?')
      ? error_pattern(argums.pattern)
      : 0;  // если не нашелся паттерн или неверная опция

  (argums.pattern[strlen(argums.pattern) - 1] == '|')
      ? argums.pattern[strlen(argums.pattern) - 1] = '\0'
      : 0;  // удаляем посл. пайп в паттерне

  int f_count = argc - optind;  // кол-во файлов

  while (optind < argc && argums.pattern != NULL) {  // обрабатываем файлы
    process(argv[optind], &argums, f_count);
    optind++;
  }

  (argums.pattern != NULL) ? free(argums.pattern) : 0;

  return 0;
}

void parser(int argc, char *argv[], Argums *argums) {
  int opt;
  while ((opt = getopt_long(argc, argv, ":e:ivclnhsf:o", NULL, 0)) != -1) {
    switch (opt) {
      case 'e':
        argums->e = 1;
        add_pattern(argums, optarg);
        break;
      case 'f':
        argums->f = 1;
        scan_file(argums, optarg);
        break;
      case 'i':
        argums->i = 1;
        break;
      case 'v':
        argums->v = 1;
        break;
      case 'c':
        argums->c = 1;
        break;
      case 'l':
        argums->l = 1;
        break;
      case 'n':
        argums->n = 1;
        break;
      case 'h':
        argums->h = 1;
        break;
      case 's':
        argums->s = 1;
        break;
      case 'o':
        argums->o = 1;
        break;
      default:
        if (argums->wrong == 0) {
          argums->wrong = opt;
        }
    }
  }
}

void print_line(int f_count, Argums *argums, char *filename, int strnum,
                char *line) {
  if (argums->c || argums->l) {
    return;
  }

  (f_count > 1 && !argums->h) ? printf("%s:", filename) : 0;
  (argums->n) ? printf("%d:%s", strnum, line) : printf("%s", line);
  (line[strlen(line) - 1] != '\n') ? printf("\n")
                                   : 0;  // перенос строки за последней
}

void print_summary(char *filename, int f_count, int counter, Argums *argums) {
  if (argums->c) {
    (argums->l && counter > 1)
        ? counter = 1
        : 0;  // при сочетании -lc, grep кол-во совпадений приравнивает к 1
    (f_count > 1 && !argums->h) ? printf("%s:", filename) : 0;
    printf("%d\n", counter);
  }

  if (argums->l && counter > 0) {
    printf("%s\n", filename);
  }
}

void process(char *filename, Argums *argums, int f_count) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    (!argums->s) ? error_file(filename) : 0;
    return;
  }

  regex_t reg;
  regmatch_t start;
  char *line = NULL;
  size_t len = 0;
  int match,
      cflags =
          argums->i ? (REG_EXTENDED | REG_ICASE) : REG_EXTENDED;  // флаг -i
  int counter = 0, strnum = 0;
  regcomp(&reg, argums->pattern, cflags);

  while (getline(&line, &len, f) != -1) {
    strnum++;  // нумерация строк
    match = regexec(&reg, line, 1, &start, 0);
    if (argums->v) match = !match;  // флаг -v
    if (!match) {
      counter++;  // счетчик совпадений
      print_line(f_count, argums, filename, strnum, line /*, len*/);
    }
  }
  //(counter > 0) ? printf("\n") : 0;  // конец отображения совпадений 1го файла
  print_summary(filename, f_count, counter, argums);

  fclose(f);
  free(line);
  regfree(&reg);
}

void add_pattern(Argums *argums, char *new_pattern) {
  if (argums->pattern == NULL) {
    argums->pattern = (char *)malloc(strlen(new_pattern) + 2);
    if (argums->pattern == NULL) {
      error_alloc();
    }
    strcpy(argums->pattern, new_pattern);
    strcat(argums->pattern, "|");  // добавление пайпа
  } else {
    argums->pattern = (char *)realloc(
        argums->pattern, strlen(argums->pattern) + strlen(new_pattern) + 2);
    if (argums->pattern == NULL) {
      error_alloc();
    }
    strcat(argums->pattern, new_pattern);
    strcat(argums->pattern, "|");  // добавление пайпа
  }
}

void scan_file(Argums *argum, char *new_file) {
  FILE *f = fopen(new_file, "r");
  char *line = NULL;
  size_t len = 0;

  if (f == NULL) {
    error_file(new_file);
    exit(1);
  }

  while (getline(&line, &len, f) != -1) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }
    add_pattern(argum, line);
  }
  fclose(f);

  if (line) {
    free(line);
  }
}

void error_file(char *filename) {
  printf("s21_grep: %s: No such file or directory\n", filename);
}

void error_pattern(char *pattern) {
  if (pattern != NULL) {
    printf(
        "s21_grep: invalid option\nusage: s21_grep [-ivclnhso] [-e pattern] "
        "[-f file] "
        "[pattern] [file "
        "...]\n");
  }
  exit(1);
}

void error_alloc() {
  printf("UNABLE TO ALLOCATE MEMORY\n");
  exit(1);
}
