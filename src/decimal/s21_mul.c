#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  s21_bigdecimal first = to_big(value_1), second = to_big(value_2),
                 result_big = {0};
  error = s21_mul_big(first, second, &result_big);
  error = normalize_to_usual(result_big, result);
  if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0)
    result->bits[3] = 0;
  return error;
}