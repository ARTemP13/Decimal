#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int err_code = OK;
  s21_init_zero(result);
  if (!(value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0)) {
    *result = value;
    int sign = s21_get_bit(value.bits[3], 31);
    int exp = s21_get_exp_decimal(result);
    result->bits[3] = (exp << 16) | (~sign << 31);
  }
  return err_code;
}