#include "../tests_includes/s21_tests.h"

START_TEST(regular_test) {
  char str1[200] = "";
  char str2[200] = "";
  char *test_str = "%d hi %d stranger %d";
  int num1 = 63, num2 = 100, num3 = 12;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3),
                   s21_sprintf(str2, test_str, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(zero_num) {
  char str1[200] = "";
  char str2[200] = "";

  char *test_str = "%d hi %d stranger %d";
  int sym1 = 0;

  ck_assert_int_eq(sprintf(str1, test_str, sym1, sym1, sym1),
                   s21_sprintf(str2, test_str, sym1, sym1, sym1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test) {
  char str1[200] = "";
  char str2[200] = "";
  char *test_str = "%d hi %d stranger %d";
  int num1 = 0063, num2 = +100, num3 = -12;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3),
                   s21_sprintf(str2, test_str, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_2) {
  char str1[200] = "";
  char str2[200] = "";
  char *test_str = "%5d hi %3d stranger %10d";
  int num1 = -63, num2 = 300, num3 = -256;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3),
                   s21_sprintf(str2, test_str, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_3) {
  char str1[200] = "";
  char str2[200] = "";
  char *test_str = "i %6.5d believe %.23d i %3.d can %.d fly %.6d";
  int num1 = -63, num2 = 300, num3 = -256, num4 = 2, num5 = 228;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3, num4, num5),
                   s21_sprintf(str2, test_str, num1, num2, num3, num4, num5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_4) {
  char str1[200] = "";
  char str2[200] = "";
  char *test_str = "i %0.0d believe %.0d i %0.d can %.d fly";
  int num1 = -63, num2 = 300, num3 = -256, num4 = 2;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3, num4),
                   s21_sprintf(str2, test_str, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_5) {
  char str1[200] = "";
  char str2[200] = "";
  char *test_str = "i %+6.5d believe %-.23d i %-3.d can %.d fly %+.6d";
  int num1 = -63, num2 = 300, num3 = -256, num4 = 2, num5 = 228;

  ck_assert_int_eq(sprintf(str1, test_str, num1, num2, num3, num4, num5),
                   s21_sprintf(str2, test_str, num1, num2, num3, num4, num5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_6) {
  char str1[200] = "";
  char str2[200] = "";
  char *test_str = "i %+6.5d believe %#.23d i %-3.d can %-.d fly %+.6d";
  int num = 0;

  ck_assert_int_eq(sprintf(str1, test_str, num, num, num, num, num),
                   s21_sprintf(str2, test_str, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_7) {
  char str1[200] = "";
  char str2[200] = "";
  char *test_str = "i % 6.5d believe %#.23d i % 3.d can %-.d fly % .6d";
  int num = 0;

  ck_assert_int_eq(sprintf(str1, test_str, num, num, num, num, num),
                   s21_sprintf(str2, test_str, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(signed_test_8) {
  char str1[200] = "";
  char str2[200] = "";
  char *test_str = "i %0.5d believe %#.23d i %3.0d can %0.0d fly %*.*d";
  int num = 0;
  int star = 5;

  ck_assert_int_eq(
      sprintf(str1, test_str, num, num, num, num, star, star, num),
      s21_sprintf(str2, test_str, num, num, num, num, star, star, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_sprintf_d(void) {
  Suite *s = suite_create("suite_sprintf_d");
  TCase *tc = tcase_create("sprintf_d_tc");

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