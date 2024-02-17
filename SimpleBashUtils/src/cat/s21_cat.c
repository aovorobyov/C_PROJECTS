#include "s21_cat.h"

int main(int argc, char *argv[]) {
  Argums argums = {0};
  parser(argc, argv, &argums);

  (argums.wrong == '?') ? error_opt() : 0;

  while (optind < argc) {
    process(argv[optind], &argums);
    optind++;
  }

  return 0;
}

void parser(int argc, char *argv[], Argums *argums) {
  int opt;
  struct option long_options[] = {{"number-nonblank", no_argument, NULL, 'b'},
                                  {"number", no_argument, NULL, 'n'},
                                  {"squeeze-blank", no_argument, NULL, 's'}};
  opt = getopt_long(argc, argv, ":beEnstTv", long_options, 0);

  switch (opt) {
    case 'b':
      argums->b = 1;
      break;
    case 'e':
      argums->e = 1;
      argums->v = 1;
      break;
    case 'E':
      argums->e = 1;
      break;
    case 'n':
      argums->n = 1;
      break;
    case 's':
      argums->s = 1;
      break;
    case 't':
      argums->t = 1;
      argums->v = 1;
      break;
    case 'T':
      argums->t = 1;
      break;
    default:
      (argums->wrong == 0) ? argums->wrong = opt : 0;
  }
}

void process(char *filename, Argums *argums) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    error_file(filename);
    return;
  }

  char *line = NULL;
  size_t len = 0;
  int line_num = 1;
  int empty_line_count = 0;

  while (getline(&line, &len, f) != -1) {
    (line == NULL) ? error_alloc() : 0;
    (argums->b || argums->n) ? bn_func(line, &line_num, argums) : 0;
    (argums->e || argums->t) ? etv_func(line, argums) : 0;
    (argums->s) ? s_func(line, &empty_line_count) : 0;
    (!(argums->b || argums->e || argums->n || argums->s || argums->t))
        ? printf("%s", line)
        : 0;
  }

  fclose(f);
  free(line);
}

void bn_func(char *line, int *line_num, Argums *argums) {
  if (line[0] != '\n' ||
      argums->n) {  // либо непустая строка, либо всеобщая нумерация
    printf("%6d\t%s", *line_num, line);
    (*line_num)++;
  } else {
    printf("%s", line);
  }
}

void etv_func(char *line, Argums *argums) {
  unsigned char ch;
  int i = 0;
  while ((ch = line[i]) != '\0') {
    i++;
    if (ch == '\n' && argums->e) {
      printf("$\n");
      continue;
    }
    if (ch == '\t' && argums->t) {
      printf("^I");
      continue;
    }
    if (argums->v) {
      if ((ch != 9 && ch != 10 && ch < 32) || ch == 127) {
        if (ch == 127) ch = '?';
        if (ch == 0) ch = '@';
        printf("^%c", ch + 64);
      } else if (ch >= 128 && ch < 160) {
        printf("M-^%c", ch - 64);
      } else {
        putchar(ch);
      }
      continue;
    }
    putchar(ch);
  }
}

void s_func(char *line, int *empty_line_count) {
  if (strcmp(line, "\n") == 0) {
    (*empty_line_count)++;
    if ((*empty_line_count) <= 1) {
      printf("%s", line);
    }
  } else {
    printf("%s", line);
    (*empty_line_count) = 0;
  }
}

void error_file(char *filename) {
  printf("s21_cat: %s: No such file or directory\n", filename);
}

void error_alloc() {
  printf("UNABLE TO ALLOCATE MEMORY\n");
  exit(1);
}

void error_opt() {
  printf(
      "s21_cat: illegal option\nusage: s21_cat [-b -e -n -s -t] [file "
      "...]\nGNU "
      "usage: s21_cat [-T -E --number-nonblank --number --squeeze-blank] "
      "[file  ...]\n");
  exit(1);
}
