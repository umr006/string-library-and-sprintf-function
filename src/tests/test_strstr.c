#include "../tests_includes/s21_tests.h"

START_TEST(empty_both) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_haystack) {
  char haystack[] = "";
  char needle[] = "some word";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_needle) {
  char haystack[] = "some word";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(regular_test) {
  char haystack[] = "running up that hill";
  char needle[] = "up";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(no_matches) {
  char haystack[] = "running up that hill";
  char needle[] = "placebo";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(search_symbol) {
  char haystack[] = "over \n\n my \t\0 head";
  char needle[] = "\t";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(repeating_pattern) {
  char haystack[] = "mad mad world";
  char needle[] = "mad";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_at_the_end) {
  char haystack[] = "running up that hill";
  char needle[] = "hill";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(full_matching) {
  char haystack[] = "a";
  char needle[] = "a";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(one_symbol_needle) {
  char haystack[] = "where is my mind";
  char needle[] = " ";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(one_symbol_haystack) {
  char haystack[] = "e";
  char needle[] = "to build a home";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s = suite_create("suite_strstr");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, empty_both);
  tcase_add_test(tc, empty_haystack);
  tcase_add_test(tc, empty_needle);
  tcase_add_test(tc, regular_test);
  tcase_add_test(tc, no_matches);
  tcase_add_test(tc, search_symbol);
  tcase_add_test(tc, repeating_pattern);
  tcase_add_test(tc, test_at_the_end);
  tcase_add_test(tc, full_matching);
  tcase_add_test(tc, one_symbol_needle);
  tcase_add_test(tc, one_symbol_haystack);

  suite_add_tcase(s, tc);
  return s;
}