#include "../s21_decimal.h"

void s21_truncate_res(s21_decimal value, s21_decimal *result, int pow) {
  unsigned long long current_num = 0;
  if ((value.bits[2] != 0 && value.bits[1] != 0 && value.bits[0] != 0) ||
      (value.bits[2] == 0 && value.bits[1] != 0 && value.bits[0] != 0)) {
    while (pow != 0) {
      s21_div_10(&value);
      pow--;
    }
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
  } else if (value.bits[2] == 0 && value.bits[1] == 0 && value.bits[0] != 0) {
    current_num = value.bits[0];
    for (int i = 0; i < pow; i++) current_num /= 10;
    result->bits[0] = current_num;
  } else {
    result->bits[0] = 0;
  }
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int flag = OK;
  s21_init_zero(result);
  int exp = s21_degree(value);
  int sign = s21_is_negative(value);
  if (exp == 0) {
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    result->bits[3] = value.bits[3];
  } else {
    s21_truncate_res(value, result, exp);
  }
  if (sign == 1) {
    result->bits[3] |= 2147483648;
  }
  return flag;
}