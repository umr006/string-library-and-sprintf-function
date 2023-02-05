#include "tests_includes/s21_tests.h"

int main(void) {
  run_tests();

  return 0;
}

void run_testcase(Suite *testcase) {
  setlocale(LC_ALL, "");
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
  // sleep(1);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_memchr(),          suite_memcmp(),
                         suite_memcpy(),          suite_memmove(),
                         suite_memset(),          suite_strcat(),
                         suite_strncat(),         suite_strchr(),
                         suite_strcmp(),          suite_strncmp(),
                         suite_strcpy(),          suite_strncpy(),
                         suite_strcspn(),         suite_strerror(),
                         suite_strlen(),          suite_strpbrk(),
                         suite_strrchr(),         suite_strspn(),
                         suite_strstr(),          suite_strtok(),
                         suite_sprintf_c(),       suite_sprintf_d(),
                         suite_sprintf_e(),       suite_sprintf_f(),
                         test_sprintf_hex(),      test_sprintf_HEX(),
                         test_sprintf_octal(),    suite_sprintf_procent(),
                         test_sprintf_unsigned(), test_sprintf_pointer(),
                         test_sprintf_n(),        test_sprintf_g(),
                         test_sprintf_string(),   test_trim(),
                         test_to_upper(),         test_to_lower(),
                         test_insert(),           NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}
