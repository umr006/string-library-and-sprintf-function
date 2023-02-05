#include "../tests_includes/s21_tests.h"

START_TEST(no_matches_test) {
  s21_size_t n_byte = 8;
  char str[10] = "testcase";
  int target_byte = 'q';

  ck_assert_ptr_eq(s21_memchr(str, target_byte, n_byte),
                   memchr(str, target_byte, n_byte));
}
END_TEST

START_TEST(symbol_at_the_beginning) {
  s21_size_t n_byte = 8;
  char str[10] = "Testcase";
  int target_byte = 'T';

  ck_assert_ptr_eq(s21_memchr(str, target_byte, n_byte),
                   memchr(str, target_byte, n_byte));
}
END_TEST

START_TEST(symbol_at_the_end) {
  s21_size_t n_byte = 8;
  char str[10] = "testcasE";
  int target_byte = 'E';

  ck_assert_ptr_eq(s21_memchr(str, target_byte, n_byte),
                   memchr(str, target_byte, n_byte));
}
END_TEST

START_TEST(number_in_the_middle) {
  s21_size_t n_byte = 13;
  char str[14] = "test123321case";
  int target_byte = '3';

  ck_assert_ptr_eq(s21_memchr(str, target_byte, n_byte),
                   memchr(str, target_byte, n_byte));
}
END_TEST

START_TEST(empty_string) {
  s21_size_t n_byte = 0;
  char str[10] = "";
  int target_byte = '\0';

  ck_assert_ptr_eq(s21_memchr(str, target_byte, n_byte),
                   memchr(str, target_byte, n_byte));
}
END_TEST

START_TEST(search_for_zero) {
  s21_size_t n_byte = 8;
  char str[10] = "testcase";
  int target_byte = '\0';

  ck_assert_ptr_eq(s21_memchr(str, target_byte, n_byte),
                   memchr(str, target_byte, n_byte));
}
END_TEST

START_TEST(int_number_in_array) {
  int array[] = {8, 800, 555, 35, 35};
  s21_size_t n_byte = sizeof(int) * 5;
  int target_byte = 555;

  ck_assert_ptr_eq(s21_memchr(array, target_byte, n_byte),
                   memchr(array, target_byte, n_byte));
}
END_TEST

START_TEST(float_number_in_array) {
  float array[] = {8, 800, 555, 35, 35};
  s21_size_t n_byte = sizeof(float) * 5;
  int target_byte = 555;

  ck_assert_ptr_eq(s21_memchr(array, target_byte, n_byte),
                   memchr(array, target_byte, n_byte));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, no_matches_test);
  tcase_add_test(tc, symbol_at_the_beginning);
  tcase_add_test(tc, symbol_at_the_end);
  tcase_add_test(tc, number_in_the_middle);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, search_for_zero);
  tcase_add_test(tc, int_number_in_array);
  tcase_add_test(tc, float_number_in_array);

  suite_add_tcase(s, tc);
  return s;
}