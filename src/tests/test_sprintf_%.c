#include "../tests_includes/s21_tests.h"

START_TEST(test1) {
  char str[100] = "";
  char s21_str[100] = "";

  char *test_str = "%%c hi %%c stranger %%c";
  char sym = '%';
  ck_assert_int_eq(sprintf(str, test_str, sym, sym, sym),
                   s21_sprintf(s21_str, test_str, sym, sym, sym));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

START_TEST(test2) {
  char str[100] = "";
  char s21_str[100] = "";

  char *test_str = "%% %c %% %c %%";
  int sym1 = 48;

  ck_assert_int_eq(sprintf(str, test_str, sym1, sym1, sym1),
                   s21_sprintf(s21_str, test_str, sym1, sym1, sym1));
  ck_assert_pstr_eq(str, s21_str);
}
END_TEST

Suite *suite_sprintf_procent(void) {
  Suite *s = suite_create("suite_sprintf_procent");
  TCase *tc = tcase_create("sprintf_c_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);

  suite_add_tcase(s, tc);
  return s;
}
