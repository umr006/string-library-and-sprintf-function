#include "../tests_includes/s21_tests.h"

START_TEST(regular_test) {
  char str[] = "Hello, world!";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(zero_test_1) {
  char str[] = "\0Hello, world!";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(zero_test_2) {
  char str[] = "   \0   ";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(symbols_test) {
  char str[] = "\t\t\t\t\n\n\n\n\\0\0\t";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(two_string_test) {
  char str[] =
      "hi"
      "stranger";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(long_string_test) {
  char str[] = "122333\n4444\t55555\n666666\07777777\n88888888\n\n";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s = suite_create("suite_strlen");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, regular_test);
  tcase_add_test(tc, zero_test_1);
  tcase_add_test(tc, zero_test_2);
  tcase_add_test(tc, symbols_test);
  tcase_add_test(tc, two_string_test);
  tcase_add_test(tc, long_string_test);

  suite_add_tcase(s, tc);
  return s;
}