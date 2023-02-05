#include "../tests_includes/s21_tests.h"

START_TEST(first_symbol_case) {
  char str1[] = "chel";
  char str2[] = "Chel";

  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(last_symbol) {
  char str1[] = "chel";
  char str2[] = "check";

  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(string_of_numbers) {
  char str1[] = "1234567890";
  char str2[] = "1234557890";

  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(first_number_in_string) {
  char str1[] = "12345";
  char str2[] = "02345";

  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(long_string_equal) {
  char str1[] = "Don't you know how it is when you arrive in heaven?";
  char str2[] = "Don't you know how it is when you arrive in heaven?";

  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(long_string_not_equal) {
  char str1[] = "Don't you know how it is when you arrive in heaven?";
  char str2[] = "Don't you know how it is when you arrive in heaven!";

  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

Suite *suite_strcmp(void) {
  Suite *s = suite_create("suite_strcmp");
  TCase *tc = tcase_create("strcmp_tc");

  tcase_add_test(tc, first_symbol_case);
  tcase_add_test(tc, last_symbol);
  tcase_add_test(tc, string_of_numbers);
  tcase_add_test(tc, first_number_in_string);
  tcase_add_test(tc, long_string_equal);
  tcase_add_test(tc, long_string_not_equal);

  suite_add_tcase(s, tc);
  return s;
}