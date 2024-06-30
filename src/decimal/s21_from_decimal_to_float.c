#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int err_code = OK;
  unsigned int exp = 0;
  unsigned int sign = -1;
  long double big_dst = 0;
  for (int i = 0; i < SIZE_DECIMAL; i++) {
    big_dst += s21_get_bit(src.bits[i / BYTE], i % BYTE) * pow(2, i);
  }
  exp = (src.bits[3] << 8) >> 24;
  while (exp--) {
    big_dst /= 10;
  }
  sign = src.bits[3] >> 31;
  *dst = big_dst;
  if (sign) {
    *dst *= (-1);
  }
  return err_code;
}