#include "../tests_includes/s21_tests.h"

START_TEST(regular_test) {
  char str1[300];
  char str2[300];
  char *test_str = "%f hi %f stranger %f";
  double num1 = 63.234567345, num2 = 132456.345, num3 = 34567.45345;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3),
                   s21_sprintf(str2, test_str, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(zero_num) {
  char str1[300] = "";
  char str2[300] = "";
  char *test_str = "%f hi %f stranger %f";
  double num1 = 0., num2 = .0, num3 = 0.3456789;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3),
                   s21_sprintf(str2, test_str, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test) {
  char str1[300] = "";
  char str2[300] = "";
  char *test_str = "%f hi %f stranger %f";
  double num1 = 063.34567897654, num2 = +.100, num3 = -12.87654456789;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3),
                   s21_sprintf(str2, test_str, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_2) {
  char str1[300] = "";
  char str2[300] = "";
  char *test_str = "%5f hi %3f stranger %10f";
  double num1 = -63.2333, num2 = 300.0, num3 = -256.234567877;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3),
                   s21_sprintf(str2, test_str, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_3) {
  char str1[400] = "";
  char str2[400] = "";
  char *test_str = "i %6.5f believe %.23f i %3.f can %.f fly %.6f";
  double num1 = -63.2333, num2 = 300.0, num3 = -256.234567877,
         num4 = -.2345678767543, num5 = +32456.;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3, num4, num5),
                   s21_sprintf(str2, test_str, num1, num2, num3, num4, num5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_4) {
  char str1[400] = "";
  char str2[400] = "";
  char *test_str = "i %0.0f believe %.0f i %0.f can %.f fly";
  double num1 = -63.2333, num2 = 300.0, num3 = -256.234567877,
         num4 = -.2345678767543;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3, num4),
                   s21_sprintf(str2, test_str, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_5) {
  char str1[400] = "";
  char str2[400] = "";
  char *test_str = "i %+6.5f believe %-.23f i %-3.f can %.f fly %+.6f";
  double num1 = -63.2333, num2 = 300.0, num3 = -256.234567877,
         num4 = -.2345678767543;
  double num5 = 87654567.9876543456789;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3, num4, num5),
                   s21_sprintf(str2, test_str, num1, num2, num3, num4, num5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_6) {
  char str1[400] = "";
  char str2[400] = "";
  char *test_str = "i %+6.5f believe %-.23f i %-3.f can %.f fly %+.6f";
  double num = 0.0;

  ck_assert_int_eq(sprintf(str1, test_str, num, num, num, num, num),
                   s21_sprintf(str2, test_str, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_7) {
  char str1[600] = "";
  char str2[600] = "";
  char *test_str = "i % 6.4f believe %#.15f i % 3.f can %-.f fly % .6f";
  double num = 9876546890765.765435;

  ck_assert_int_eq(sprintf(str1, test_str, num, num, num, num, num),
                   s21_sprintf(str2, test_str, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_8) {
  char str1[600] = "";
  char str2[600] = "";
  char *test_str = "i %0.4f believe %#.15f i %3.0f can %0.0f fly %10.13f";
  double num = 9876546890765.765435;

  ck_assert_int_eq(sprintf(str1, test_str, num, num, num, num, num),
                   s21_sprintf(str2, test_str, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_sprintf_f(void) {
  Suite *s = suite_create("suite_sprintf_f");
  TCase *tc = tcase_create("sprintf_f_tc");

  tcase_add_test(tc, regular_test);
  tcase_add_test(tc, zero_num);
  tcase_add_test(tc, signed_test);
  tcase_add_test(tc, signed_test_2);
  tcase_add_test(tc, signed_test_3);
  tcase_add_test(tc, signed_test_4);
  tcase_add_test(tc, signed_test_5);
  tcase_add_test(tc, signed_test_6);
  tcase_add_test(tc, signed_test_7);
  tcase_add_test(tc, signed_test_8);

  suite_add_tcase(s, tc);
  return s;
}
