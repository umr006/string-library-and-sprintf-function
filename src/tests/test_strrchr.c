#include "../tests_includes/s21_tests.h"

START_TEST(no_matches_test) {
  char str[] = "testcase";
  int target_byte = 'q';

  ck_assert_ptr_eq(s21_strrchr(str, target_byte), strrchr(str, target_byte));
}
END_TEST

START_TEST(symbol_at_the_beginning) {
  char str[] = "Testcase";
  int target_byte = 'T';

  ck_assert_ptr_eq(s21_strrchr(str, target_byte), strrchr(str, target_byte));
}
END_TEST

START_TEST(symbol_at_the_end) {
  char str[] = "testcasE";
  int target_byte = 'E';

  ck_assert_ptr_eq(s21_strrchr(str, target_byte), strrchr(str, target_byte));
}
END_TEST

START_TEST(number_in_the_middle) {
  char str[] = "test123321\0\0\0\0case";
  int target_byte = '3';

  ck_assert_ptr_eq(s21_strrchr(str, target_byte), strrchr(str, target_byte));
}
END_TEST

START_TEST(zero_in_the_middle) {
  char str[] = "test123321\0\0\0\0case";
  int target_byte = '\0';

  ck_assert_ptr_eq(s21_strrchr(str, target_byte), strrchr(str, target_byte));
}
END_TEST

START_TEST(empty_string) {
  char str[] = "";
  int target_byte = '\0';

  ck_assert_ptr_eq(s21_strrchr(str, target_byte), strrchr(str, target_byte));
}
END_TEST

START_TEST(search_for_n) {
  char str[] = "testcase\n\ntestcase\0";
  int target_byte = '\n';

  ck_assert_ptr_eq(s21_strrchr(str, target_byte), strrchr(str, target_byte));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, no_matches_test);
  tcase_add_test(tc, symbol_at_the_beginning);
  tcase_add_test(tc, symbol_at_the_end);
  tcase_add_test(tc, number_in_the_middle);
  tcase_add_test(tc, zero_in_the_middle);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, search_for_n);

  suite_add_tcase(s, tc);
  return s;
}