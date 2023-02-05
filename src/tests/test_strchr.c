#include "../tests_includes/s21_tests.h"

START_TEST(regular_test) {
  char src[36] = "There is a house built out of stone";
  int c = 'e';

  ck_assert_pstr_eq(s21_strchr(src, c), strchr(src, c));
}
END_TEST

START_TEST(empty_src) {
  char src[36] = "There is a house built out of stone";
  int c = 'e';

  ck_assert_pstr_eq(s21_strchr(src, c), strchr(src, c));
}
END_TEST

START_TEST(zero_c) {
  char src[36] = "There is a house built out of stone";
  int c = 0;

  ck_assert_pstr_eq(s21_strchr(src, c), strchr(src, c));
}
END_TEST

START_TEST(upper_case_test) {
  char src[36] = "There is a house built out of stone";
  int c = 't';

  ck_assert_pstr_eq(s21_strchr(src, c), strchr(src, c));
}
END_TEST

START_TEST(no_matches) {
  char src[36] = "There is a house built out of stone";
  int c = '$';

  ck_assert_pstr_eq(s21_strchr(src, c), strchr(src, c));
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("strchr_tc");

  tcase_add_test(tc, regular_test);
  tcase_add_test(tc, empty_src);
  tcase_add_test(tc, zero_c);
  tcase_add_test(tc, upper_case_test);
  tcase_add_test(tc, no_matches);

  suite_add_tcase(s, tc);
  return s;
}