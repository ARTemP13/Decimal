#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = OK;
  int negative = s21_is_negative(value);
  s21_truncate(value, result);
  if (negative == 1 && result->bits[0] != 0) {
    result->bits[0]++;
  }
  return flag;
}