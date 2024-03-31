#ifndef SRC_TEST_H
#define SRC_TEST_H

#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"

Suite *test_sub(void);
Suite *test_mul(void);
Suite *test_div(void);
Suite *test_add(void);
Suite *test_compare(void);
Suite *test_convert(void);
Suite *test_floor(void);
Suite *test_negate(void);
Suite *test_round(void);
Suite *test_truncate(void);

#endif  // SRC_TEST_H