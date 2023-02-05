#include "../tests_includes/s21_tests.h"

START_TEST(regular_test) {
  char str[100] = "";
  char s21_str[100] = "";

  char *test_str = "%c hi %c stranger %c";
  int sym1 = 63, sym2 = 100, sym3 = 12;

  ck_assert_int_eq(sprintf(str, test_str, sym1, sym2, sym3),
                   s21_sprintf(s21_str, test_str, sym1, sym2, sym3));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(zero_symbol) {
  char str[100] = "";
  char s21_str[100] = "";

  char *test_str = "%c hi %c stranger %c";
  int sym1 = 48;

  ck_assert_int_eq(sprintf(str, test_str, sym1, sym1, sym1),
                   s21_sprintf(s21_str, test_str, sym1, sym1, sym1));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(diff_specificators) {
  char str[100] = "";
  char s21_str[100] = "";

  char *test_str = "%5c how % 5c are %c you";
  int sym1 = 65;
  int sym2 = 65;

  ck_assert_int_eq(sprintf(str, test_str, sym1, sym2, sym2),
                   s21_sprintf(s21_str, test_str, sym1, sym2, sym2));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(diff_specificators_2) {
  char str[100] = "";
  char s21_str[100] = "";

  char *test_str = "i %+10.5c believe % +10.5c i %-10c can %-10c fly %+10c";
  int sym1 = 90;
  int sym2 = 98;

  ck_assert_int_eq(
      sprintf(str, test_str, sym1, sym2, sym2, sym1, sym1),
      s21_sprintf(s21_str, test_str, sym1, sym2, sym2, sym1, sym1));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(sharp_spec) {
  char str[100] = "";
  char s21_str[100] = "";

  char *test_str = "i %#c believe %#c i %#c can %#c fly %#c";
  ck_assert_int_eq(sprintf(str, test_str, ' ', 'n', '7', '%', '\\'),
                   s21_sprintf(s21_str, test_str, ' ', 'n', '7', '%', '\\'));

  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(special_sym) {
  char str[100] = "";
  char s21_str[100] = "";

  char *test_str = "i %c believe %c i %c can %c fly %c";
  ck_assert_int_eq(
      sprintf(str, test_str, '\n', '\n', '\t', '\n', '\n'),
      s21_sprintf(s21_str, test_str, '\n', '\n', '\t', '\n', '\n'));

  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(special_sym_2) {
  char str[100] = "";
  char s21_str[100] = "";

  char *test_str = "i %#c believe %#c i %#c can %#c fly %#c";
  ck_assert_int_eq(sprintf(str, test_str, '4', 'N', '\n', '0', '_'),
                   s21_sprintf(s21_str, test_str, '4', 'N', '\n', '0', '_'));

  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(long_test) {
  char str[400] = "";
  char s21_str[400] = "";

  char *test_str = "%.7c Test %-7c Test %-50c Test % 54c Test %188c";
  ck_assert_int_eq(sprintf(str, test_str, '4', 'N', '\n', '0', '_'),
                   s21_sprintf(s21_str, test_str, '4', 'N', '\n', '0', '_'));

  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *suite_sprintf_c(void) {
  Suite *s = suite_create("suite_sprintf_c");
  TCase *tc = tcase_create("sprintf_c_tc");

  tcase_add_test(tc, regular_test);
  tcase_add_test(tc, zero_symbol);
  tcase_add_test(tc, diff_specificators);
  tcase_add_test(tc, diff_specificators_2);
  tcase_add_test(tc, sharp_spec);
  tcase_add_test(tc, special_sym);
  tcase_add_test(tc, special_sym_2);
  tcase_add_test(tc, long_test);

  suite_add_tcase(s, tc);
  return s;
}