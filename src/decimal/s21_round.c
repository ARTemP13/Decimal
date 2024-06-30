#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = OK;
  int flag_negative = 0;
  int degree = s21_degree(value);
  if (s21_is_negative(value) == 1) {
    flag_negative = 1;
  }
  int res = 0;
  while (degree != 0) {
    if (value.bits[0] == 0) {
      degree = 0;
    } else {
      if (value.bits[0] != 0 && value.bits[1] != 0 && value.bits[2] != 0) {
        int end_num = value.bits[0] - ((value.bits[0] / 10) * 10);
        res = 5 * 5 * end_num;
      } else if (value.bits[0] != 0 && value.bits[1] != 0 &&
                 value.bits[2] == 0) {
        int end_num = value.bits[0] - ((value.bits[0] / 10) * 10);
        res = 5 * end_num;
      } else {
        int end_num = value.bits[0] - ((value.bits[0] / 10) * 10);
        res = end_num;
      }
      s21_div_10(&value);
      degree--;
      res = res % 10;
      if (res >= 5) value.bits[0]++;
    }
  }

  s21_init_zero(result);
  result->bits[0] = value.bits[0];
  result->bits[1] = value.bits[1];
  result->bits[2] = value.bits[2];
  if (flag_negative == 1) {
    result->bits[3] |= 2147483648;
  }
  return flag;
}