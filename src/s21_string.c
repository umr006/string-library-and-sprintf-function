#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src != s21_NULL && trim_chars != s21_NULL) {
    int flag = 1;
    int len = s21_strlen(src);
    res = malloc(len * sizeof(char));
    int i = 0, t = 0, j = 0, l = len - 1, f = 0;
    while (flag) {
      flag = 0;
      for (j = 0; trim_chars[j]; j++) {
        if (src[i] == trim_chars[j]) {
          flag = 1;
          i++;
          break;
        }
      }
    }
    flag = 1;
    while (flag) {
      flag = 0;
      for (t = 0; trim_chars[t] && l; t++) {
        if (src[l] == trim_chars[t]) {
          flag = 1;
          l--;
          break;
        }
      }
    }
    for (f = 0; i <= l; f++, i++) {
      res[f] = src[i];
    }
    res[f] = 0;
  } else if (trim_chars == s21_NULL) {
    res = (char *)src;
  }
  return res;
}

void *s21_insert(const char *dest, const char *src, size_t start_index) {
  char *res = s21_NULL;
  s21_size_t src_len = s21_strlen(src);
  s21_size_t dest_len = s21_strlen(dest);
  s21_size_t len = src_len + dest_len;
  if ((src != s21_NULL && dest != s21_NULL) && dest_len != 0 &&
      ((start_index <= dest_len) && start_index > 0)) {
    res = malloc(len * sizeof(char));
    s21_size_t i = 0, y = 0, j = 0, str_cnt = 0;
    for (; i < len; i++, j++) {
      if (i == start_index) {
        for (y = i; src[str_cnt]; y++, str_cnt++) {
          res[y] = src[str_cnt];
          i++;
        }
      }
      res[i] = dest[j];
    }
    res[i] = 0;
  }
  return res;
}

void *s21_to_upper(const char *str) {
  char *res = s21_NULL;
  if (str != s21_NULL) {
    int len = s21_strlen(str);
    int i = 0;
    res = malloc(len * sizeof(char));
    for (; str[i]; i++) {
      if (str[i] >= 97 && str[i] <= 122) {
        res[i] = str[i] - 32;
      } else {
        res[i] = str[i];
      }
    }
    res[i] = '\0';
  }
  return res;
}

void *s21_to_lower(const char *str) {
  char *res = s21_NULL;
  if (str != s21_NULL) {
    int len = s21_strlen(str);
    int i = 0;
    res = malloc(len * sizeof(char));
    for (; str[i]; i++) {
      if (str[i] >= 65 && str[i] <= 90) {
        res[i] = str[i] + 32;
      } else {
        res[i] = str[i];
      }
    }
    res[i] = '\0';
  }
  return res;
}

void *s21_memchr(const void *arr, int c, s21_size_t n) {
  const char *str = arr;
  char k = (char)c;
  for (s21_size_t i = 0; i < n; i++) {
    if (str[i] == k) {
      return (char *)str + i;
    }
  }
  return s21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;
  int ret = 0;
  while (n--) {
    ret = *s1 - *s2;
    if (*s1 != *s2) break;
    s1++;
    s2++;
  }
  return ret;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *s1 = (char *)dest;
  char *s2 = (char *)src;
  if (s1 != s21_NULL && s2 != s21_NULL) {
    for (s21_size_t i = 0; i < n; i++) {
      *(s1 + i) = *(s2 + i);
    }
  }
  return s1;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *s1 = (char *)dest;
  char *s2 = (char *)src;

  if (dest != s21_NULL && src != s21_NULL) {
    s21_size_t i;
    if (s1 > s2) {
      i = n;
      while (i--) *(s1 + i) = *(s2 + i);
    } else {
      i = 0;
      while (i++ < n) *(s1 + (i - 1)) = *(s2 + (i - 1));
    }
  }
  return s1;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *s1 = str;
  while (n--) *s1++ = c;
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  char *s1 = dest;
  const char *s2 = src;
  s21_size_t len_s1 = s21_strlen(s1);
  s21_size_t len_s2 = s21_strlen(s2);
  for (s21_size_t i = 0; i <= len_s2; i++) {
    s1[len_s1] = s2[i];
    len_s1++;
  }
  s1[len_s1] = '\0';
  return s1;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *s1 = dest;
  const char *s2 = src;
  s21_size_t len_s1 = s21_strlen(s1);
  s21_size_t i = 0;
  for (i = 0; i < n; i++) {
    s1[len_s1] = s2[i];
    len_s1++;
  }
  s1[len_s1] = '\0';
  return s1;
}

char *s21_strchr(const char *str, int c) {
  char *temp = (char *)str;
  s21_size_t i;
  char ch = c;
  char *outcome;
  for (i = 0; i < s21_strlen(temp) + 1; i++) {
    if (temp[i] == ch) {
      outcome = &temp[i];
      break;
    } else {
      outcome = NULL;
    }
  }
  return outcome;
}

int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  while (*str1 == *str2 && (*str1 != '\0' || *str2 != '\0')) {
    str1 += 1;
    str2 += 1;
  }
  if (*str1 != *str2) res = *str1 - *str2;
  return res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (s21_size_t i = 0; *str1 == *str2 && i < n - 1; i++) {
    str1++;
    str2++;
  }
  return n == 0 ? 0 : (*str1 - *str2);
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i;
  s21_size_t len_src = s21_strlen(src);
  for (i = 0; i < len_src; i++) {
    dest[i] = src[i];
  }
  dest[len_src] = '\0';
  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  for (; i < n; i++) {
    dest[i] = src[i];
  }
  dest[s21_strlen(dest)] = '\0';
  return dest;
}

size_t s21_strcspn(const char *str1, const char *str2) {
  char *temp_str_1 = (char *)str1;
  char *temp_str_2 = (char *)str2;
  int i, j;
  int result = 0;
  int flag = 0;
  for (i = 0; temp_str_1[i]; i++) {
    for (j = 0; temp_str_2[j]; j++) {
      if (temp_str_1[i] == temp_str_2[j]) flag = 1;
    }
    if (flag == 1) break;
    result++;
  }
  return result;
}

char *s21_strerror(int errnum) {
  static char massError[1024];
  char *result = massError;
  if (errnum < 0 || errnum >= MAX_NUM) {
    char str[80];
    s21_sprintf(str, "%d", errnum);
    s21_strcpy(result, "Unknown error");
#if defined(__APPLE__)
    s21_strcat(result, ":");
#endif
    s21_strcat(result, " ");
    s21_strcat(result, str);
  } else {
    char *mass[MAX_NUM] = ERRLIST;
    s21_strcpy(result, mass[errnum]);
  }
  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *temp_str_1 = (char *)str1;
  char *temp_str_2 = (char *)str2;
  char *result = s21_NULL;
  for (int i = 0; temp_str_1[i]; i++) {
    for (int l = 0; temp_str_2[l]; l++) {
      if (temp_str_1[i] == temp_str_2[l]) {
        result = &temp_str_1[i];
        break;
      }
    }
    if (result != s21_NULL) {
      break;
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *temp = (char *)str;
  char *res = s21_NULL;
  int len = s21_strlen(temp);
  while (len >= 0) {
    if (temp[len] == c) {
      res = &temp[len];
      break;
    }
    len--;
  }
  return res;
}

s21_size_t s21_strspn(const char *s, const char *accept) {
  const char *s1;
  const char *s2;
  s21_size_t count = 0;
  for (s1 = s; *s1 != '\0'; ++s1) {
    for (s2 = accept; *s2 != '\0'; ++s2) {
      if (*s1 == *s2) {
        count++;
        break;
      }
    }
    if (*s2 == '\0') return count;
  }
  return count;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *s1 = (char *)haystack;
  char *s2 = (char *)needle;
  char *res = s21_NULL;
  s21_size_t i = 0, j = 0, flag = 0;
  if (*s2 == 0) res = s1;
  while (s1[i]) {
    j = 0;
    flag = 1;
    while (s2[j]) {
      if (s1[i + j] != s2[j]) {
        flag = 0;
        break;
      }
      j++;
    }
    if (flag) {
      res = s1 + i;
      break;
    }
    i++;
  }
  return res;
}

char *s21_strtok(char *str, char *delim) {
  static char *ptr;
  char *ret = s21_NULL;
  if (!str) str = ptr;
  int flag;
  if (str) {
    flag = 0;
    while (flag == 0) {
      if (del_check(*str, delim)) {
        str++;
        continue;
      }
      if (*str == '\0') flag = 1;
      break;
    }
    char *inter = str;
    while (1 && flag == 0) {
      if (*str == '\0') {
        ptr = str;
        ret = inter;
        flag = 1;
      }
      if (del_check(*str, delim)) {
        *str = '\0';
        ptr = str + 1;
        ret = inter;
        flag = 1;
      }
      str++;
    }
  }
  return ret;
}

int del_check(char c, const char *delim) {
  int res = 0;
  while (*delim != '\0') {
    if (c == *delim) res++;
    delim++;
  }
  return res;
}

int s21_sprintf(char *str, const char *format, ...) {
  flags f = {0};
  char *start = str;
  va_list ap;
  va_start(ap, format);
  while (*format) {
    if (*format != '%') {
      *str = *format;
      str++;
      format++;
      continue;
    } else {
      s21_memset(&f, 0, sizeof(flags));
      format++;
      while (*format == '+' || *format == '-' || *format == ' ' ||
             *format == '#' || *format == '0') {
        if (*format == '+') f.plus = 1;
        if (*format == '-') f.minus = 1;
        if (*format == ' ') f.space = 1;
        if (*format == '#') f.sharp = 1;
        if (*format == '0') f.zero = 1;
        format++;
      }
      while ((*format >= '0' && *format <= '9') || *format == '*') {
        if (*format >= '0' && *format <= '9') {
          f.width = f.width * 10 + (*format - '0');
        } else if (*format == '*') {
          f.width = va_arg(ap, int);
        }
        format++;
      }
      if (*format == '.') {
        f.dot = 1;
        format++;
        while ((*format >= '0' && *format <= '9') || *format == '*') {
          if (*format >= '0' && *format <= '9') {
            f.accuracy = f.accuracy * 10 + (*format - '0');
          } else if (*format == '*') {
            f.accuracy = va_arg(ap, int);
          }
          format++;
        }
      }
      if (*format == 'h' || *format == 'l' || *format == 'L') {
        f.lenght = *format;
        format++;
      }
      if (*format == 'c' || *format == 'd' || *format == 'i' ||
          *format == 'e' || *format == 'E' || *format == 'f' ||
          *format == 'g' || *format == 'G' || *format == 'o' ||
          *format == 's' || *format == 'u' || *format == 'x' ||
          *format == 'X' || *format == 'p' || *format == 'n' ||
          *format == '%') {
        f.specifier = *format;
        format++;
      }
    }
    char buff[BUFF_SIZE] = {0};
    sprintf_case(f, buff, ap);
    for (int i = 0; buff[i]; i++, str++) {
      *str = buff[i];
    }
    if (f.specifier == 'n') {
      n_case(str, start, va_arg(ap, int *));
    }
  }
  *str = '\0';
  va_end(ap);
  return str - start;
}

void sprintf_case(flags f, char *buff, va_list ap) {
  if (f.specifier == 'd' || f.specifier == 'i') {
    int_case(f, buff, ap);
  } else if (f.specifier == 'u')
    unsigned_case(f, buff, ap);
  else if (f.specifier == 'f')
    float_case(f, buff, ap);
  else if (f.specifier == 'c')
    char_case(f, buff, ap);
  else if (f.specifier == 's')
    str_case(f, buff, ap);
  else if (f.specifier == '%')
    buff[0] = '%';
  else if (f.specifier == 'o') {
    buff[0] = '0';
    num_to_str(va_arg(ap, long long), f.sharp ? buff + 1 : buff, 8);
    set_precision(f, buff);
    width_and_flags(buff, f);
  } else if (f.specifier == 'x' || f.specifier == 'X') {
    hex_case(f, buff, ap);
    set_precision(f, buff);
    width_and_flags(buff, f);
  } else if (f.specifier == 'p') {
    unsigned long long arg = va_arg(ap, unsigned long long);
    buff[0] = '0';
    buff[1] = 'x';
    unsigned_to_str(arg, buff + 2, 16, f);
    set_precision(f, buff);
    width_and_flags(buff, f);
  } else if (f.specifier == 'e' || f.specifier == 'E') {
    exp_case(f, buff, ap);
  } else if (f.specifier == 'g') {
    g_case(f, buff, ap);
  }
}

void g_case(flags f, char *buff, va_list ap) {
  long double arg = 0;
  if (f.lenght == 'L')
    arg = va_arg(ap, long double);
  else
    arg = va_arg(ap, double);
  int exp = 0;
  long long tmp_arg = arg;
  if (arg < 0) tmp_arg *= -1;
  while (tmp_arg > 0) {
    exp++;
    tmp_arg /= 10;
  }
  if ((f.dot && arg >= 9.5 && exp >= f.accuracy) ||
      ((f.dot && arg <= -9.5 && exp >= f.accuracy)))
    arg = roundl(arg);
  if ((f.dot && arg >= 10 && f.accuracy < exp) ||
      (f.dot && arg <= -10 && f.accuracy <= exp) || arg >= 1000000 ||
      (arg <= 0.00001 && arg > 0)) {
    f.dot = 1;
    expg_case(f, buff, arg);
    width_and_flags(buff, f);
  } else {
    fg_case(f, buff, arg);
  }
}

void fg_case(flags f, char *buff, long double arg) {
  if (!f.dot) f.accuracy = 4;
  if (f.accuracy == 0) f.accuracy = 1;
  fg_process(f, buff, arg);
  delete_zero(buff);
  width_and_flags(buff, f);
}

void fg_process(flags f, char *buff, long double arg) {
  char tmp[BUFF_SIZE] = {'\0'};
  int index = BUFF_SIZE - 2;
  int flag_minus = 0;
  int acc = f.accuracy, acc_1 = f.accuracy;
  if (arg < 0) {
    arg *= -1;
    flag_minus = 1;
  }
  long double l, r = 0;
  r = modfl(arg, &l);
  if (f.dot == 1 && f.accuracy == 0) {
    l = roundl(arg);
    r = 0;
  }
  while (acc--) {
    r = r * 10;
  }
  long long right = roundl(r), left = l;
  char ri[128] = {0};
  int rigth_mass = right;
  int i = 0;
  while (rigth_mass > 0) {
    char num[11] = "0123456789";
    ri[i] = num[rigth_mass % 10];
    rigth_mass /= 10;
    i++;
  }
  s21_size_t acc_len = f.accuracy;
  if (right % 10 == 0 && acc_len < s21_strlen(ri) && f.dot) {
    right = 0, left = l + 1;
  }
  if (right) {
    while (acc_1--) {
      tmp[index] = '0';
      index--;
    }
  }
  if (right) {
    for (int i = f.accuracy; right || i > 0; right /= 10, index--, i--)
      tmp[index] = (int)(right % 10) + '0';
  }
  if ((f.dot && f.accuracy != 0) || (int)r || (!f.dot && arg == 0) || !f.dot)
    tmp[index--] = '.';
  if (!left)
    tmp[index--] = '0';
  else {
    while (left) {
      tmp[index] = (int)(left % 10) + '0';
      left /= 10;
      index--;
    }
  }
  for (int i = 0; tmp[index + 1]; index++, i++) {
    if (flag_minus && i == 0) buff[i++] = '-';

    buff[i] = tmp[index + 1];
  }
}

void delete_zero(char *buff) {
  s21_size_t len = (s21_strlen(buff) - 1);
  while (len) {
    if (buff[len] == '0') {
      buff[len] = '\0';
    } else if (buff[len] != '0') {
      break;
    }
    len--;
  }
  len = (s21_strlen(buff) - 1);
  if (buff[len] == '.') {
    buff[len] = '\0';
  }
}

void expg_case(flags f, char *buff, long double arg) {
  char plus_or_minus = (int)arg == 0 ? '-' : '+';
  int exp = 0;
  if (arg == 0) {
    char plus_or_minus = '+';
    float_process(f, buff, arg);
    exp_pro(buff, exp, plus_or_minus, f);
    width_and_flags(buff, f);
  } else {
    if (plus_or_minus == '-') {
      while ((int)arg == 0) {
        exp++;
        arg *= 10;
      }
    }
    if (plus_or_minus == '+') {
      while ((int)arg / 10 != 0) {
        exp++;
        arg /= 10;
      }
    }
    ge_process(f, buff, arg);
    exp_pro(buff, exp, plus_or_minus, f);
    width_and_flags(buff, f);
  }
}

void ge_process(flags f, char *buff, long double arg) {
  f.dot = 1;
  char tmp[BUFF_SIZE] = {'\0'};
  int index = BUFF_SIZE - 2;
  int flag_minus = 0;
  if (arg < 0) {
    arg *= -1;
    flag_minus = 1;
  }
  long double l, r = 0;
  r = modfl(arg, &l);
  if (f.accuracy == 0)
    if (f.accuracy == 0 && f.dot == 1) {
      l = roundl(arg);
      r = 0;
    }
  long long right = roundl(r), left = l;
  char ri[128] = {0};
  int rigth_mass = right;
  int i = 0;
  while (rigth_mass > 0) {
    char num[11] = "0123456789";
    ri[i] = num[rigth_mass % 10];
    rigth_mass /= 10;
    i++;
  }
  s21_size_t acc_len = f.accuracy;
  if (right % 10 == 0 && acc_len < s21_strlen(ri) && f.accuracy != 0) {
    right = 0, left = l + 1;
  }
  if (right) {
    for (int i = f.accuracy; right || i > 0; right /= 10, index--, i--)
      tmp[index] = (int)(right % 10) + '0';
  }
  if ((f.dot && f.accuracy != 0) || (int)r || (!f.dot && arg == 0) || !f.dot ||
      f.sharp)
    tmp[index--] = '.';
  if (!left)
    tmp[index--] = '0';
  else {
    while (left) {
      tmp[index] = (int)(left % 10) + '0';
      left /= 10;
      index--;
    }
  }
  for (int i = 0; tmp[index + 1]; index++, i++) {
    if (flag_minus && i == 0) buff[i++] = '-';

    buff[i] = tmp[index + 1];
  }
}

void n_case(char *str, char *start, int *res) { *res = str - start; }

void exp_case(flags f, char *buff, va_list ap) {
  long double arg = 0;
  if (f.lenght == 'L')
    arg = va_arg(ap, long double);
  else
    arg = va_arg(ap, double);
  char plus_or_minus = (int)arg == 0 ? '-' : '+';
  int exp = 0;
  if (arg == 0) {
    char plus_or_minus = '+';
    float_process(f, buff, arg);
    exp_pro(buff, exp, plus_or_minus, f);
    width_and_flags(buff, f);
  } else {
    if (plus_or_minus == '-') {
      while ((int)arg == 0) {
        exp++;
        arg *= 10;
      }
    }
    if (plus_or_minus == '+') {
      while ((int)arg / 10 != 0) {
        exp++;
        arg /= 10;
      }
    }
    float_process(f, buff, arg);
    exp_pro(buff, exp, plus_or_minus, f);
    width_and_flags(buff, f);
  }
}

void exp_pro(char *buff, int exp, char plus_or_minus, flags f) {
  s21_size_t len = s21_strlen(buff);
  buff[len] = f.specifier == 'e' || f.specifier == 'g' ? 'e' : 'E';
  buff[len + 1] = plus_or_minus;
  buff[len + 3] = exp % 10 + '0';
  exp /= 10;
  buff[len + 2] = exp % 10 + '0';
  buff[len + 4] = '\0';
}

void hex_case(flags f, char *buff, va_list ap) {
  long long arg = va_arg(ap, long long);
  if (f.lenght == 'h')
    arg = (short)arg;
  else if (f.lenght == 0)
    arg = (int)arg;

  if (f.sharp && f.specifier == 'X') {
    buff[0] = '0';
    buff[1] = 'X';
  } else if (f.sharp) {
    buff[0] = '0';
    buff[1] = 'x';
  }
  unsigned_to_str(arg, f.sharp ? buff + 2 : buff, 16, f);
}

void str_case(flags f, char *buff, va_list ap) {
  char *sp = va_arg(ap, char *);
  str_pro(f, buff, sp);
}

void str_pro(flags f, char *buff, char *s) {
  char tmp[BUFF_SIZE] = {0};
  s21_strcpy(tmp, s);
  if (f.dot) {
    tmp[f.accuracy] = '\0';
  }

  int len = s21_strlen(tmp);
  int gap = f.width - s21_strlen(tmp);

  if (f.minus && gap > 0) {
    s21_strcpy(buff, tmp);
    s21_memset(buff + len, ' ', gap);
  } else if (gap > 0) {
    s21_memset(buff, ' ', gap);
    s21_strcpy(buff + gap, tmp);
  } else {
    s21_strcpy(buff, tmp);
  }
}

void char_case(flags f, char *buff, va_list ap) {
  if (f.lenght == 'l') {
    wchar_t long_char;
    long_char = va_arg(ap, wchar_t);
    char_process(f, buff, long_char);
  } else {
    char ch;
    ch = va_arg(ap, int);
    char_process(f, buff, ch);
  }
}

void char_process(flags f, char *buff, char ch) {
  if (f.width && f.minus) {
    int y;
    buff[0] = ch;
    for (y = 1; y < (f.width); y++) buff[y] = ' ';
  } else if (f.width) {
    int i;
    for (i = 0; i < (f.width - 1); i++) {
      buff[i] = ' ';
    }
    buff[i] = ch;
  } else {
    buff[0] = ch;
  }
}

void int_case(flags f, char *buff, va_list ap) {
  long long arg = va_arg(ap, long long);
  if (f.lenght == 'h')
    arg = (short)arg;
  else if (f.lenght == 0)
    arg = (int)arg;
  num_to_str(arg, buff, 10);
  set_precision(f, buff);
  width_and_flags(buff, f);
}

void unsigned_case(flags f, char *buff, va_list ap) {
  unsigned long long arg = va_arg(ap, long long);
  if (f.lenght == 'h')
    arg = (unsigned short)arg;
  else if (f.lenght == 0)
    arg = (unsigned int)arg;
  unsigned_to_str(arg, buff, 10, f);
  set_precision(f, buff);
  width_and_flags(buff, f);
}

void float_case(flags f, char *buff, va_list ap) {
  double arg = va_arg(ap, double);
  if (f.lenght == 'L') arg = va_arg(ap, long double);
  float_process(f, buff, arg);
  width_and_flags(buff, f);
}

void num_to_str(long long arg, char *buff, int num_system) {
  char tmp[BUFF_SIZE] = {'\0'};
  int index = BUFF_SIZE - 2;
  int flag_minus = 0;
  if (arg < 0) {
    arg *= -1;
    flag_minus = 1;
  }
  if (arg == 0) {
    tmp[index] = '0';
  }
  while (arg > 0) {
    --index;
    char num[11] = "0123456789";
    tmp[index] = num[arg % num_system];
    arg /= num_system;
  }
  for (int j = 0; tmp[index]; j++, index++) {
    if (flag_minus && j == 0) {
      buff[j] = '-';
      flag_minus = 0;
      j++;
    }
    buff[j] = tmp[index];
  }
}

void unsigned_to_str(long long arg, char *buff, int num_system, flags f) {
  char tmp[BUFF_SIZE] = {'\0'};
  int index = BUFF_SIZE - 2;
  if (arg == 0) {
    tmp[index] = '0';
  }
  while (arg > 0) {
    --index;
    char num[17] = "0123456789abcdef";
    char numX[17] = "0123456789ABCDEF";
    tmp[index] =
        f.specifier == 'X' ? numX[arg % num_system] : num[arg % num_system];
    arg /= num_system;
  }
  for (int j = 0; tmp[index]; j++, index++) {
    buff[j] = tmp[index];
  }
}

void set_precision(flags f, char *buff) {
  char tmp[BUFF_SIZE] = {'\0'};
  int neg = 0;
  int len = s21_strlen(buff);
  int i;
  if (buff[0] == '-') {
    tmp[0] = '-';
    neg = 1;
    len--;
  }
  for (i = neg; i < f.accuracy - len + neg; i++) {
    tmp[i] = '0';
  }
  for (int j = neg; buff[j]; i++, j++) {
    tmp[i] = buff[j];
  }
  s21_strcpy(buff, tmp);
  if (f.dot && f.accuracy == 0 && buff[0] == '0' &&
      (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'o' ||
       f.specifier == 'u' || f.specifier == 'x' || f.specifier == 'X')) {
    buff[0] = '\0';
  }
}

void width_and_flags(char *buff, flags f) {
  char tmp[BUFF_SIZE + 1] = {'\0'};
  if (f.plus && f.specifier != 'u' && f.specifier != 'o' &&
      f.specifier != 'x' && f.specifier != 'X') {
    tmp[0] = buff[0] == '-' ? '-' : '+';
    s21_strcpy(tmp + 1, buff[0] == '-' ? buff + 1 : buff);
    s21_strcpy(buff, tmp);
  } else if (f.space && buff[0] != '-' && f.specifier != 'u') {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, buff);
    s21_strcpy(buff, tmp);
  }
  if (f.width > (int)s21_strlen(buff)) {
    int idx = f.width - s21_strlen(buff);
    if (!f.minus) {
      s21_memset(tmp, f.zero ? '0' : ' ', idx);
      s21_strcpy(tmp + idx, buff);
    } else {
      s21_strcpy(tmp, buff);
      s21_memset(tmp + s21_strlen(tmp), ' ', idx);
    }
    s21_strcpy(buff, tmp);
  }
}

void float_process(flags f, char *buff, long double arg) {
  if (!f.dot) f.accuracy = 6;
  char tmp[BUFF_SIZE] = {'\0'};
  int index = BUFF_SIZE - 2;
  int flag_minus = 0;
  int acc = f.accuracy, acc_1 = f.accuracy;
  if (arg < 0) {
    arg *= -1;
    flag_minus = 1;
  }
  long double l, r = 0;
  r = modfl(arg, &l);
  if (f.accuracy == 0 && f.dot == 1) {
    l = roundl(arg);
    r = 0;
  }
  while (acc--) {
    r = r * 10;
  }
  long long right = roundl(r), left = l;
  char ri[128] = {0};
  long long rigth_mass = right;
  int i = 0;
  while (rigth_mass > 0) {
    char num[11] = "0123456789";
    ri[i] = num[rigth_mass % 10];
    rigth_mass /= 10;
    i++;
  }
  s21_size_t acc_len = f.accuracy;
  if (right % 10 == 0 && acc_len < s21_strlen(ri) && f.accuracy != 0) {
    right = 0, left = l + 1;
  }
  if (!right) {
    while (acc_1--) {
      tmp[index] = '0';
      index--;
    }
  }
  if (right) {
    for (int i = f.accuracy; right || i > 0; right /= 10, index--, i--)
      tmp[index] = (int)(right % 10) + '0';
  }
  if ((f.dot && f.accuracy != 0) || (int)r || (!f.dot && arg == 0) || !f.dot ||
      f.sharp)
    tmp[index--] = '.';
  if (!left)
    tmp[index--] = '0';
  else {
    while (left) {
      tmp[index] = (int)(left % 10) + '0';
      left /= 10;
      index--;
    }
  }
  for (int i = 0; tmp[index + 1]; index++, i++) {
    if (flag_minus && i == 0) buff[i++] = '-';

    buff[i] = tmp[index + 1];
  }
}