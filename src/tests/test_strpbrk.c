#include "../tests_includes/s21_tests.h"

START_TEST(empty) {
  char str1[] = "";
  char str2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(half_empty_1) {
  char str1[] = "another test";
  char str2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(half_empty_2) {
  char str1[] = "";
  char str2[] = "another test";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(letter_g_test) {
  char str1[] = "knocking on heaven's door";
  char str2[] = "g";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(letter_o_test) {
  char str1[] = "knocking on heaven's door";
  char str2[] = "o";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(letter_k_test) {
  char str1[] = "knocking on heaven's door";
  char str2[] = "k";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(letter_O_test) {
  char str1[] = "knocking on heaven's dOor";
  char str2[] = "O";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(zero_test) {
  char str1[] = "knocking on heaven's door";
  char str2[] = "\0";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("strpbrk_tc");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, half_empty_1);
  tcase_add_test(tc, half_empty_2);
  tcase_add_test(tc, letter_g_test);
  tcase_add_test(tc, letter_o_test);
  tcase_add_test(tc, letter_k_test);
  tcase_add_test(tc, letter_O_test);
  tcase_add_test(tc, zero_test);

  suite_add_tcase(s, tc);
  return s;
}