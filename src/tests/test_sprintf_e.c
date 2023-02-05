#include "../tests_includes/s21_tests.h"

START_TEST(regular_test) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *test_str = "%e hi %5e stranger %5.e";
  double num = -765400.11;

  ck_assert_int_eq(sprintf(str1, test_str, num, num, num),
                   s21_sprintf(str2, test_str, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(special_sym) {
  char str1[1024];
  char str2[1024];
  char *test_str = "%e\n%.e\n%4e\n%4.e\n%5.10e!";
  double num = -880055535.35;

  ck_assert_int_eq(sprintf(str1, test_str, num, num, num, num, num),
                   s21_sprintf(str2, test_str, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(zero_test) {
  char str1[1024];
  char str2[1024];
  char *test_str = "%e\n%.e\n%0e\n%0.e\n%0.0e";
  double num = 5.;

  ck_assert_int_eq(sprintf(str1, test_str, num, num, num, num, num),
                   s21_sprintf(str2, test_str, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators) {
  char str1[1024];
  char str2[1024];
  char *test_str = "%6.4e  %#.7e  %03.e  %.e  %.6e";
  double num = 555555.5;

  ck_assert_int_eq(sprintf(str1, test_str, num, num, num, num, num),
                   s21_sprintf(str2, test_str, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators_2) {
  char str1[1024];
  char str2[1024];
  char *test_str = "%6.4e  %#.7e\n  %03.e  %#.e\t%.6e";
  double num1 = 555555.5, num2 = 123456789123456.789;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num1, num2, num1),
                   s21_sprintf(str2, test_str, num1, num2, num1, num2, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators_3) {
  char str1[1024];
  char str2[1024];
  char *test_str = "i %20.e believe %#.7e\n i %03.8e can %#.e\t fly\t%.6e";
  double num1 = 5.5555555555, num2 = 123456789123456.789;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num1, num2, num1),
                   s21_sprintf(str2, test_str, num1, num2, num1, num2, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators_4) {
  char str1[1024];
  char str2[1024];
  char *test_str = "i % 6.5e believe %5.7e\n i % 03.e can %#.e\t fly\t%10.6e";
  double num1 = 55555555555555555555555555555.5, num2 = 123456789123456.789;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num1, num2, num1),
                   s21_sprintf(str2, test_str, num1, num2, num1, num2, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators_5) {
  char str1[1024];
  char str2[1024];
  char *test_str = "%20.e";
  double num1 = 55555555555555555.5;

  ck_assert_int_eq(sprintf(str1, test_str, num1),
                   s21_sprintf(str2, test_str, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators_6) {
  char str1[1024];
  char str2[1024];
  char *test_str = "%3.15e";
  double num1 = 2134567891234567891234567891234567.5123456789;

  ck_assert_int_eq(sprintf(str1, test_str, num1),
                   s21_sprintf(str2, test_str, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators_7) {
  char str1[1024];
  char str2[1024];
  char *test_str = "%3.15e";
  double num1 = -2134567891234567891234567891234567.5123456789;

  ck_assert_int_eq(sprintf(str1, test_str, num1),
                   s21_sprintf(str2, test_str, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators_8) {
  char str1[1024];
  char str2[1024];
  char *test_str = "%.6e\n%.10e";
  double num1 = 44.51234;
  double num2 = 24.5678;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2),
                   s21_sprintf(str2, test_str, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators_9) {
  char str1[1024];
  char str2[1024];
  char *test_str = "%3.15e\n%3.15e\n";
  double num1 = -.2134567891234567891234567891234567;
  double num2 = -44.5123;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2),
                   s21_sprintf(str2, test_str, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators_10) {
  char str1[1024];
  char str2[1024];
  char *test_str = "\n%#20.E\n%- 20E\n";
  double num1 = 5329657567689928373474727375.273787825732159676631957;
  double num2 = 53296575676899283734747273752737878257.32159676631957;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2),
                   s21_sprintf(str2, test_str, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(diff_specificators_11) {
  char str1[1000];
  char str2[1000];
  double num1 = 12345678900000938217586.;
  double num2 = .12345678900000938217586;
  char *test_str = "\n%070.10E\n%-67.10E\n";

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2),
                   s21_sprintf(str2, test_str, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_sprintf_e(void) {
  Suite *s = suite_create("suite_sprintf_e");
  TCase *tc = tcase_create("sprintf_e_tc");

  tcase_add_test(tc, regular_test);
  tcase_add_test(tc, special_sym);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, diff_specificators);
  tcase_add_test(tc, diff_specificators_2);
  tcase_add_test(tc, diff_specificators_3);
  tcase_add_test(tc, diff_specificators_4);
  tcase_add_test(tc, diff_specificators_5);
  tcase_add_test(tc, diff_specificators_6);
  tcase_add_test(tc, diff_specificators_7);
  tcase_add_test(tc, diff_specificators_8);
  tcase_add_test(tc, diff_specificators_9);
  tcase_add_test(tc, diff_specificators_10);
  tcase_add_test(tc, diff_specificators_11);

  suite_add_tcase(s, tc);
  return s;
}
