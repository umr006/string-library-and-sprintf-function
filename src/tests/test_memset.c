#include "../tests_includes/s21_tests.h"

START_TEST(zero_byte) {
  char check1[20] = "test string";
  char check2[20] = "test string";
  size_t n_byte = 0;
  char c = 'g';

  s21_memset(check1, c, n_byte);
  memset(check2, c, n_byte);

  ck_assert_str_eq(check1, check2);
}
END_TEST

START_TEST(empty_string) {
  char check1[20] = "";
  char check2[20] = "";
  size_t n_byte = 0;
  char c = 'g';

  s21_memset(check1, c, n_byte);
  memset(check2, c, n_byte);

  ck_assert_str_eq(check1, check2);
}
END_TEST

START_TEST(regular_test) {
  char check1[20] = "test string";
  char check2[20] = "test string";
  size_t n_byte = 4;
  char c = 'z';

  s21_memset(check1, c, n_byte);
  memset(check2, c, n_byte);

  ck_assert_str_eq(check1, check2);
}
END_TEST

START_TEST(long_string_test) {
  char check1[41] = "hi stranger228))))))0 it's been a while$";
  char check2[41] = "hi stranger228))))))0 it's been a while$";
  size_t n_byte = 6;
  char c = '(';

  s21_memset(check1 + 6, c, n_byte);
  memset(check2 + 6, c, n_byte);

  ck_assert_str_eq(check1, check2);
}
END_TEST

START_TEST(upper_case_test) {
  char check1[] = "test string";
  char check2[] = "test string";
  size_t n_byte = 1;
  char c = 'G';

  s21_memset(check1 + 10, c, n_byte);
  memset(check2 + 10, c, n_byte);

  ck_assert_str_eq(check1, check2);
}
END_TEST

Suite *suite_memset(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, zero_byte);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, regular_test);
  tcase_add_test(tc, long_string_test);
  tcase_add_test(tc, upper_case_test);

  suite_add_tcase(s, tc);
  return s;
}