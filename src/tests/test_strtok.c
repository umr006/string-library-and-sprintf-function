#include "../tests_includes/s21_tests.h"

START_TEST(empty_strings) {
  char s1[1] = "";
  char s2[1] = "";
  char s3[1] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(zero_symbol) {
  char s1[] = "hi stranger";
  char s2[] = "hi stranger";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(zero_symbol_2) {
  char s1[] = "\0hi stranger";
  char s2[] = "\0hi stranger";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(empty_symbol) {
  char s1[] = "hi stranger";
  char s2[] = "hi stranger";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(full_match) {
  char s1[] = "hi stranger";
  char s2[] = "hi stranger";
  char s3[] = "hi stranger";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(no_matches) {
  char s1[] = "hi stranger";
  char s2[] = "hi stranger";
  char s3[] = "find something";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_sep) {
  char s1[] = "test test test test test test test";
  char s2[] = "test test test test test test test";
  char s3[] = " ";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(expanded_test) {
  char s1[] = "test test";
  char s2[] = "test test";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(expanded_test_2) {
  char s1[] = "test112345678";
  char s2[] = "test112345678";
  char s3[] = "test4";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(s21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(s21_NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST

START_TEST(different_patterns) {
  char s1[] = "test test test test test";
  char s2[] = "test test test test test";
  char s3[] = "chel chel";
  char s4[] = "chel chel";
  char s5[] = " ";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, empty_strings);
  tcase_add_test(tc, zero_symbol);
  tcase_add_test(tc, zero_symbol_2);
  tcase_add_test(tc, empty_symbol);
  tcase_add_test(tc, full_match);
  tcase_add_test(tc, no_matches);
  tcase_add_test(tc, test_sep);
  tcase_add_test(tc, expanded_test);
  tcase_add_test(tc, expanded_test_2);
  tcase_add_test(tc, different_patterns);

  suite_add_tcase(s, tc);
  return s;
}