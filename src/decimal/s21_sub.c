#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  memset(result, 0, sizeof(s21_decimal));
  int res = 0, sign1 = get_bit(value_1, 127), sign2 = get_bit(value_2, 127);
  int scale1 = s21_degree(value_1), scale2 = s21_degree(value_2);
  if (scale1 != scale2) {
    scale_equalize(&value_1, &value_2);
    scale1 = s21_degree(value_1);
  }
  if (sign1 != sign2) {
    set_bit(&value_2, 127, sign1);
    res = s21_add(value_1, value_2, result);
  } else {
    if (s21_is_greater_or_equal(abs_dec(value_1), abs_dec(value_2))) {
      bit_substraction(value_1, value_2, result);
      set_bit(result, 127, sign1);
    } else {
      bit_substraction(value_2, value_1, result);
      set_bit(result, 127, sign2 == 0 ? 1 : 0);
    }
  }
  set_pow(*result, result, scale1);
  return res;
}
void bit_substraction(s21_decimal value1, s21_decimal value2,
                      s21_decimal *res) {
  int bit1, bit2, tmp = 0, sub;
  for (int i = 0; i < 96; i++) {
    bit1 = get_bit(value1, i);
    bit2 = get_bit(value2, i);
    sub = bit1 - bit2;
    switch (sub) {
      case (-1): {
        set_bit(res, i, 1);
        tmp = 1;
        break;
      }
      case (0): {
        set_bit(res, i, 0);
        break;
      }
      case (1): {
        set_bit(res, i, 1);
        break;
      }
    }
    if (tmp == 1) {
      for (int j = i; j < 96; j++) {
        if (get_bit(value1, j) == 1) {
          set_bit(&value1, j, 0);
          break;
        } else {
          set_bit(&value1, j, 1);
        }
      }
      tmp = 0;
    }
  }
}