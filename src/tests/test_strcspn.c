#include "../tests_includes/s21_tests.h"

START_TEST(first_letter) {
  char str1[12] = "hi stranger";
  char str2[2] = "h";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(first_letter_upper_case) {
  char str1[12] = "hi strangerH";
  char str2[2] = "H";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(last_letter) {
  char str1[12] = "hi stranger";
  char str2[2] = "r";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(zero_string_1) {
  char str1[10] = "";
  char str2[2] = "h";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(zero_string_2) {
  char str1[12] = "hi stranger";
  char str2[1] = "";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(a_couple_of_letters) {
  char str1[12] = "hi stranger";
  char str2[3] = "ai";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(no_matches) {
  char str1[12] = "hi stranger";
  char str2[4] = "wow";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(full_match) {
  char str1[12] = "hi stranger";
  char str2[12] = "hi stranger";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, first_letter);
  tcase_add_test(tc, first_letter_upper_case);
  tcase_add_test(tc, last_letter);
  tcase_add_test(tc, zero_string_1);
  tcase_add_test(tc, zero_string_2);
  tcase_add_test(tc, a_couple_of_letters);
  tcase_add_test(tc, no_matches);
  tcase_add_test(tc, full_match);

  suite_add_tcase(s, tc);
  return s;
}