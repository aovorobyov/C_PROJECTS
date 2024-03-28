#include "test.h"

int main(void) {
  int failed = 0, total = 0;

  Suite *s21_decimal_test[] = {test_add(), test_sub(), test_mul(), test_div(),
                               NULL};

  for (int i = 0; s21_decimal_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_decimal_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    total += srunner_ntests_run(sr);
    srunner_free(sr);
  }
  printf("========= PASSED: %d/%d =========\n", total - failed, total);
  printf("========= FAILED: %d/%d =========\n", failed, total);

  return failed == 0 ? 0 : 1;
}