#include "../tests_includes/s21_tests.h"

START_TEST(regular_test) {
  char src[10] = "stranger!";
  char s21_dest[20] = "hi, ";
  char dest[20] = "hi, ";

  s21_strcat(s21_dest, src);
  strcat(dest, src);

  ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(empty_src) {
  char src[] = "";
  char s21_dest[10] = "test";
  char dest[10] = "test";

  s21_strcat(s21_dest, src);
  strcat(dest, src);

  ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(empty_dest) {
  char src[5] = "test";
  char s21_dest[6] = "";
  char dest[6] = "";

  s21_strcat(s21_dest, src);
  strcat(dest, src);

  ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(long_string_with_symbols) {
  char src[76] =
      "In heaven that's all they talk about - the ocean - and how wonderful it "
      "is.";
  char s21_dest[53 + 76] =
      "Don't you know how it is when you arrive in heaven? ";
  char dest[53 + 76] = "Don't you know how it is when you arrive in heaven? ";

  s21_strcat(s21_dest, src);
  strcat(dest, src);

  ck_assert_str_eq(s21_dest, dest);
}
END_TEST

Suite *suite_strcat(void) {
  Suite *s = suite_create("suite_strcat");
  TCase *tc = tcase_create("strcat_tc");

  tcase_add_test(tc, regular_test);
  tcase_add_test(tc, empty_src);
  tcase_add_test(tc, empty_dest);
  tcase_add_test(tc, long_string_with_symbols);

  suite_add_tcase(s, tc);
  return s;
}