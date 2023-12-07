#include "tests/tests.h"

void run() {
  Suite *tests[] = {
      suite_add(),
      suite_sub(),
      suite_mul(),
      suite_div(),

      suite_is_less(),
      suite_is_less_or_equal(),
      suite_is_greater(),
      suite_is_greater_or_equal(),
      suite_is_equal(),
      suite_is_not_equal(),

      suite_from_int_to_decimal(),
      suite_from_float_to_decimal(),
      suite_from_decimal_to_int(),
      suite_from_decimal_to_float(),

      suite_floor(),
      suite_round(),
      suite_truncate(),
      suite_negate(),
      NULL,
  };

  int total = 0;
  int failed = 0;

  for (Suite **current = tests; *current; current++) {
    SRunner *sr = srunner_create(*current);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    total += srunner_ntests_run(sr);
    failed += srunner_ntests_failed(sr);

    srunner_free(sr);
  }

  printf("\n" GRAY_BG WHITE " total: %d " RESET GREEN_BG WHITE
         " success: %d " RESET RED_BG WHITE " failed: %d " RESET "\n",
         total, total - failed, failed);
}

int main() {
  run();

  return 0;
}
