#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../s21_string.h"

Suite *suite_sprintf(void);
Suite *suite_memchr(void);
Suite *suite_memcmp(void);
Suite *suite_memcpy(void);
Suite *suite_memmove(void);
Suite *suite_memset(void);
Suite *suite_strcat(void);
Suite *suite_strncat(void);
Suite *suite_strchr(void);
Suite *suite_strcmp(void);
Suite *suite_strncmp(void);
Suite *suite_strcpy(void);
Suite *suite_strncpy(void);
Suite *suite_strcspn(void);
Suite *suite_strerror(void);
Suite *suite_strlen(void);
Suite *suite_strpbrk(void);
Suite *suite_strrchr(void);
Suite *suite_strspn(void);
Suite *suite_strstr(void);
Suite *suite_strtok(void);

Suite *suite_sprintf_c(void);
Suite *suite_sprintf_d(void);
Suite *suite_sprintf_e(void);
Suite *suite_sprintf_f(void);
Suite *test_sprintf_hex(void);
Suite *test_sprintf_HEX(void);
Suite *test_sprintf_octal(void);
Suite *test_sprintf_string(void);
Suite *test_sprintf_unsigned(void);
Suite *test_sprintf_pointer(void);
Suite *test_sprintf_n(void);
Suite *suite_sprintf_procent(void);
Suite *test_sprintf_g(void);
Suite *test_trim(void);
Suite *test_insert(void);
Suite *test_to_upper(void);
Suite *test_to_lower(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_
