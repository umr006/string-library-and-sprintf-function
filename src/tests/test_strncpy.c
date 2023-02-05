#include "../tests_includes/s21_tests.h"

START_TEST(regular_test_1) {
  char src[] = "hi stranger";

  char s21_dest[15] = "";
  char dest[15] = "";
  s21_size_t n_byte = 12;

  ck_assert_pstr_eq(s21_strncpy(s21_dest, src, n_byte),
                    strncpy(dest, src, n_byte));
}
END_TEST

START_TEST(regular_test_2) {
  char src[] = "hi stranger";

  char s21_dest[12 + 7] = "wooow ";
  char dest[12 + 7] = "wooow ";
  s21_size_t n_byte = 12;

  ck_assert_pstr_eq(s21_strncpy(s21_dest, src, n_byte),
                    strncpy(dest, src, n_byte));
}
END_TEST

START_TEST(line_break) {
  char src[] = "hi \nstranger";

  char s21_dest[15] = "";
  char dest[15] = "";
  s21_size_t n_byte = 13;

  ck_assert_pstr_eq(s21_strncpy(s21_dest, src, n_byte),
                    strncpy(dest, src, n_byte));
}
END_TEST

START_TEST(empty_string) {
  char src[] = "";
  char s21_dest[10] = "";
  char dest[10] = "";
  s21_size_t n_byte = 0;

  ck_assert_pstr_eq(s21_strncpy(s21_dest, src, n_byte),
                    strncpy(dest, src, n_byte));
}
END_TEST

START_TEST(zero_string) {
  char src[] = "\0";
  char s21_dest[10] = "";
  char dest[10] = "";
  s21_size_t n_byte = 2;

  ck_assert_pstr_eq(s21_strncpy(s21_dest, src, n_byte),
                    strncpy(dest, src, n_byte));
}
END_TEST

START_TEST(long_with_diff_dt_1) {
  char src[] = "hi stranger228))))))0\n\0 it's been a while$";
  char s21_dest[87] = "hi stranger228))))))0\n\0 it's been a while$";
  char dest[87] = "hi stranger228))))))0\n\0 it's been a while$";
  s21_size_t n_byte = 43;

  ck_assert_pstr_eq(s21_strncpy(s21_dest, src, n_byte),
                    strncpy(dest, src, n_byte));
}
END_TEST

START_TEST(long_with_diff_dt_2) {
  char src[] = "hi stranger228))))))0\n\0 it's been a while$";
  char s21_dest[50] = "\0\0\0";
  char dest[50] = "\0\0\0";
  s21_size_t n_byte = 43;

  ck_assert_pstr_eq(s21_strncpy(s21_dest, src, n_byte),
                    strncpy(dest, src, n_byte));
}
END_TEST

START_TEST(long_with_diff_dt_3) {
  char src[] = "hi stranger228))))))0\n\0 it's been a while$";
  char s21_dest[40] = "\0hello";
  char dest[40] = "\0hello";
  s21_size_t n_byte = 30;

  ck_assert_pstr_eq(s21_strncpy(s21_dest, src, n_byte),
                    strncpy(dest, src, n_byte));
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, regular_test_1);
  tcase_add_test(tc, regular_test_2);
  tcase_add_test(tc, line_break);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, zero_string);
  tcase_add_test(tc, long_with_diff_dt_1);
  tcase_add_test(tc, long_with_diff_dt_2);
  tcase_add_test(tc, long_with_diff_dt_3);

  suite_add_tcase(s, tc);
  return s;
}