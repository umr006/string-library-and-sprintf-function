#include "../tests_includes/s21_tests.h"

START_TEST(regular_test) {
  char src[BUFSIZ] = "hi stranger";
  s21_size_t n_byte = 12;
  char res[BUFSIZ];
  char expected[BUFSIZ];

  s21_memmove(res, src, n_byte);
  memmove(expected, src, n_byte);

  ck_assert_mem_eq(res, expected, n_byte);
}
END_TEST

START_TEST(zero_byte) {
  char src[BUFSIZ] = "hi stranger";
  s21_size_t n_byte = 0;
  char res[BUFSIZ];
  char expected[BUFSIZ];

  s21_memmove(res, src, n_byte);
  memmove(expected, src, n_byte);

  ck_assert_mem_eq(res, expected, n_byte);
}
END_TEST

START_TEST(empty_string) {
  char src[BUFSIZ] = "";
  s21_size_t n_byte = 0;
  char res[BUFSIZ];
  char expected[BUFSIZ];

  s21_memmove(res, src, n_byte);
  memmove(expected, src, n_byte);

  ck_assert_mem_eq(res, expected, n_byte);
}
END_TEST

START_TEST(long_with_diff_dt) {
  char src[BUFSIZ] = "hi stranger228))))))0 it's been a while$";
  s21_size_t n_byte = 41;
  char res[BUFSIZ];
  char expected[BUFSIZ];

  s21_memmove(res, src, n_byte);
  memmove(expected, src, n_byte);

  ck_assert_mem_eq(res, expected, n_byte);
}
END_TEST

START_TEST(rewrite_test1) {
  char check1[BUFSIZ] = "test string";
  char check2[BUFSIZ] = "test string";
  s21_size_t n_byte = 20;

  s21_memmove(check1 + 5, check1, n_byte);
  memmove(check2 + 5, check2, n_byte);

  ck_assert_str_eq(check1, check2);
}
END_TEST

START_TEST(rewrite_test2) {
  char check1[BUFSIZ] = "test string";
  char check2[BUFSIZ] = "test string";
  s21_size_t n_byte = 20;

  s21_memmove(check1 + 5, check1, n_byte);
  memmove(check2 + 5, check2, n_byte);

  ck_assert_str_eq(check1, check2);
}
END_TEST

Suite *suite_memmove(void) {
  Suite *s = suite_create("suite_memmove");
  TCase *tc = tcase_create("memmove_tc");

  tcase_add_test(tc, regular_test);
  tcase_add_test(tc, zero_byte);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, long_with_diff_dt);
  tcase_add_test(tc, rewrite_test1);
  tcase_add_test(tc, rewrite_test2);

  suite_add_tcase(s, tc);
  return s;
}

// #include "../tests_includes/s21_tests.h"

// START_TEST(memmove_1) {
//   char s1[] = "Hello, world!";
//   char s2[] = "Hello, world!";
//   char s3[] = "Good";
//   s21_size_t n = 4;
//   memmove(s1, s3, n);
//   s21_memmove(s2, s3, n);
//   ck_assert_mem_eq(s1, s2, n);
// }
// END_TEST

// START_TEST(memmove_2) {
//   char s1[] = "Hello, world!";
//   char s2[] = "Hello, world!";
//   char s3[] = "";
//   s21_size_t n = 0;
//   memmove(s1, s3, n);
//   s21_memmove(s2, s3, n);
//   ck_assert_mem_eq(s1, s2, n);
// }
// END_TEST

// START_TEST(memmove_3) {
//   char s1[] = "Hello, world!";
//   char s2[] = "Hello, world!";
//   char s3[] = "forward";
//   s21_size_t n = 0;
//   memmove(s1, s3, n);
//   s21_memmove(s2, s3, n);
//   ck_assert_mem_eq(s1, s2, n);
// }
// END_TEST

// START_TEST(memmove_4) {
//   char s1[] = "100: Checks: 780, Failures: 0, Errors: 0";
//   char s2[] = "100: Checks: 780, Failures: 0, Errors: 0";
//   s21_size_t n = 6;
//   memmove(s1, s1, n);
//   s21_memmove(s2, s2, n);
//   ck_assert_mem_eq(s1, s2, n);
// }
// END_TEST

// START_TEST(memmove_5) {
//   char s1[] = "H";
//   char s2[] = "H";
//   char s3[] = "Hi";
//   s21_size_t n = 2;
//   memmove(s1, s3, n);
//   s21_memmove(s2, s3, n);
//   ck_assert_mem_eq(s1, s2, n);
// }
// END_TEST

// START_TEST(memmove_6) {
//   char s1[] = "jijijij";
//   char s2[] = "jijijij";
//   char s3[] = "\0";
//   s21_size_t n = 1;
//   memmove(s1, s3, n);
//   s21_memmove(s2, s3, n);
//   ck_assert_mem_eq(s1, s2, n);
// }
// END_TEST

// START_TEST(memmove_7) {
//   char s1[] = "           ";
//   char s2[] = "           ";
//   char s3[] = "new_string";
//   s21_size_t n = strlen(s3);
//   memmove(s1, s3, n);
//   s21_memmove(s2, s3, n);
//   ck_assert_mem_eq(s1, s2, n);
// }
// END_TEST

// START_TEST(memmove_8) {
//   char s1[] = "699\017020";
//   char s2[] = "699\017020";
//   char s3[] = "com";
//   s21_size_t n = 3;
//   memmove(s1, s3, n);
//   s21_memmove(s2, s3, n);
//   ck_assert_mem_eq(s1, s2, n);
// }
// END_TEST

// START_TEST(memmove_9) {
//   char s1[] = "69917020";
//   char s2[] = "69917020";
//   char s3[] = "c";
//   s21_size_t n = 1;
//   memmove(s1, s3, n);
//   s21_memmove(s2, s3, n);
//   ck_assert_mem_eq(s1, s2, n);
// }
// END_TEST

// START_TEST(memmove_10) {
//   char s1[] = "69917020";
//   char s2[] = "69917020";
//   char s3[] = "com";
//   s21_size_t n = 4;
//   memmove(s1, s3, n);
//   s21_memmove(s2, s3, n);
//   ck_assert_mem_eq(s1, s2, n);
// }
// END_TEST

// Suite *test_memmove(void) {
//   Suite *s = suite_create("suite_memmove");
//   TCase *tc = tcase_create("memove_tc");

//   tcase_add_test(tc, memmove_1);
//   tcase_add_test(tc, memmove_2);
//   tcase_add_test(tc, memmove_3);
//   tcase_add_test(tc, memmove_4);
//   tcase_add_test(tc, memmove_5);
//   tcase_add_test(tc, memmove_6);
//   tcase_add_test(tc, memmove_7);
//   tcase_add_test(tc, memmove_8);
//   tcase_add_test(tc, memmove_9);
//   tcase_add_test(tc, memmove_10);

//   suite_add_tcase(s, tc);
//   return s;
// }