#include <stdio.h>
#include <string.h>

#include "s21_string.h"

int main() {
  char str1[200];
  char str2[200];
  char *str3 = "%.g water %.g water %4.g water %5.9g!";
  double num = 573429.56;
  int or = sprintf(str1, str3, num, num, num, num);
  int re = s21_sprintf(str2, str3, num, num, num, num);
  printf("or = %s\n", str1);
  printf("re = %s\n", str2);
  printf("%d\n", or);
  printf("%d\n", re);
}
