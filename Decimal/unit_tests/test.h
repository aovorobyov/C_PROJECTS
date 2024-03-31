#ifndef SRC_TEST_H
#define SRC_TEST_H

#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"

Suite *test_round(void);
Suite *test_floor(void);
Suite *test_truncate(void);
Suite *test_negate(void);

#endif 
