#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = OK;
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
  if (src < 0) {
    unsigned int tmp = 2147483648;
    dst->bits[3] = tmp;
    dst->bits[0] = -src;
  } else {
    dst->bits[0] = src;
  }
  return flag;
}