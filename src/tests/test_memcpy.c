#include "../tests_includes/s21_tests.h"

START_TEST(regular_test) {
  char src[] = "hi stranger";
  s21_size_t n_byte = 12;
  char res[14];
  char expected[14];

  s21_memcpy(res, src, n_byte);
  memcpy(expected, src, n_byte);

  ck_assert_mem_eq(res, expected, n_byte);
}
END_TEST

START_TEST(zero_byte) {
  char src[] = "hi stranger";
  s21_size_t n_byte = 0;
  char res[10];
  char expected[10];

  s21_memcpy(res, src, n_byte);
  memcpy(expected, src, n_byte);

  ck_assert_mem_eq(res, expected, n_byte);
}
END_TEST

START_TEST(empty_string) {
  char src[] = "";
  s21_size_t n_byte = 0;
  char res[10];
  char expected[10];

  s21_memcpy(res, src, n_byte);
  memcpy(expected, src, n_byte);

  ck_assert_mem_eq(res, expected, n_byte);
}
END_TEST

START_TEST(long_with_diff_dt) {
  char src[] = "hi stranger228))))))0 it's been a while$";
  s21_size_t n_byte = 41;
  char res[n_byte];
  char expected[n_byte];

  s21_memcpy(res, src, n_byte);
  memcpy(expected, src, n_byte);

  ck_assert_mem_eq(res, expected, n_byte);
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, regular_test);
  tcase_add_test(tc, zero_byte);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, long_with_diff_dt);

  suite_add_tcase(s, tc);
  return s;
}