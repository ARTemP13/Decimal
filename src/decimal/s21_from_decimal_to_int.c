#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = OK;
  int flag_negative = 0;
  int degree = 0;
  if (s21_is_negative(src)) {
    flag_negative = 1;
    s21_delete_negative(&src);
  }
  degree = s21_degree(src);
  int rem = 0;
  while (degree != 0) {
    if (src.bits[0] != 0 && src.bits[1] != 0 && src.bits[2] != 0) {
      int end_num = src.bits[0] - ((src.bits[0] / 10) * 10);
      rem = 5 * 5 * end_num;
    } else if (src.bits[0] != 0 && src.bits[1] != 0 && src.bits[2] == 0) {
      int end_num = src.bits[0] - ((src.bits[0] / 10) * 10);
      rem = 5 * end_num;
    } else {
      int end_num = src.bits[0] - ((src.bits[0] / 10) * 10);
      rem = end_num;
    }
    s21_div_10(&src);
    degree--;
    rem = rem % 10;
    if (rem >= 5) src.bits[0]++;
  }
  if (src.bits[2] != 0 || src.bits[1] != 0) {
    flag = ERROR;
  } else {
    unsigned int current_num = src.bits[0];

    long long num = 0;
    long long compare_num = S21_INT_MAX;
    compare_num += 1;
    if ((flag_negative == 0 && current_num <= S21_INT_MAX) ||
        (flag_negative == 1 && (long long)current_num <= compare_num)) {
      num = current_num;
      if (flag_negative == 1) num *= -1;
      *dst = (int)num;
    } else {
      flag = ERROR;
    }
  }
  return flag;
}
