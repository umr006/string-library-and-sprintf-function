#include "../tests_includes/s21_tests.h"

START_TEST(sprintf_1_g) {
  char str1[BUFSIZ];
  char str2[BUFSIZ];
  char *str3 = "%g water %.g water %4g water %4.g water %5.10g!";
  double num = -76.7565;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_g) {
  char str1[BUFSIZ];
  char str2[BUFSIZ];
  char *str3 = "%g water %.g water %4g water %4.g water %5.10g!";
  double num = -76.7565;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_g) {
  char str1[BUFSIZ];
  char str2[BUFSIZ];
  char *str3 = "%25.9g water\n%.3g water\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_g) {
  char str1[BUFSIZ];
  char str2[BUFSIZ];
  char *str3 = "%2g water\n%.3g water\n";
  double num = 838.6500000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_g) {
  char str1[BUFSIZ];
  char str2[BUFSIZ];
  char *str3 = "%.2g water %.3g water %4.g water %#5.9g";
  double num = 0.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_g) {
  char str1[BUFSIZ];
  char str2[BUFSIZ];
  char *str3 = "%.2g water %.3g water %4.g water %#5.9g";
  double num = -0.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_g) {
  char str1[BUFSIZ];
  char str2[BUFSIZ];
  char *str3 = "%.g water %.g water %4.g water %5.9g!";
  double num = 573429.56;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_g(void) {
  Suite *s = suite_create("suite_sprintf_g");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_g);
  tcase_add_test(tc, sprintf_2_g);
  tcase_add_test(tc, sprintf_3_g);
  tcase_add_test(tc, sprintf_4_g);
  tcase_add_test(tc, sprintf_5_g);
  tcase_add_test(tc, sprintf_6_g);
  tcase_add_test(tc, sprintf_7_g);

  suite_add_tcase(s, tc);
  return s;
}
