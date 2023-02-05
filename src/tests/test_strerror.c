#include "../tests_includes/s21_tests.h"

START_TEST(test_1) {
  int i = 54;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(test_2) {
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("strerror_tc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);

  suite_add_tcase(s, tc);
  return s;
}