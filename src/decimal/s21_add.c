#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  s21_bigdecimal first = to_big(value_1), second = to_big(value_2),
                 result_big = {0};
  if (first.sign == second.sign) {
    if (first.exp != second.exp) normalize_exp(&first, &second, 1);
    error = s21_add_big(first, second, &result_big);
    if (!error) error = normalize_to_usual(result_big, result);
  } else {
    s21_negate(value_2, &value_2);
    s21_sub(value_1, value_2, result);
  }

  return error;
}