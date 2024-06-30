#include "../s21_decimal.h"

void scale_equalize(s21_decimal *value1, s21_decimal *value2) {
  s21_decimal *min = NULL, *max = NULL;
  int flag = 0;
  int scale1 = s21_degree(*value1), scale2 = s21_degree(*value2);
  if (scale1 > scale2) {
    min = value2;
    max = value1;
  } else {
    SWAP(scale1, scale2, int);
    min = value1;
    max = value2;
  }
  for (int i = scale1 - scale2; (i > 0 && flag == 0); i--) {
    flag = scale_increase(min);
  }
  scale1 = s21_degree(*value1);
  scale2 = s21_degree(*value2);
  while (scale1 != scale2) {
    scale_decrease(max);
    scale2++;
  }
}

int scale_increase(s21_decimal *value) {
  int res = 0;
  int scale = s21_degree(*value);
  if (first_bit(*value) < 93 && scale < 28) {
    s21_decimal tmp8 = {0}, tmp2 = {0};
    dec_copy(*value, &tmp2);
    dec_copy(*value, &tmp8);
    for (int i = 0; i < 3; i++) left(&tmp8);
    left(&tmp2);
    bit_addition(tmp8, tmp2, value);
    set_pow(*value, value, scale + 1);
  } else {
    res = 1;
  }
  return res;
}

void scale_decrease(s21_decimal *value) {
  int scale = s21_degree(*value);
  s21_div_10(value);
  set_pow(*value, value, scale - 1);
}

s21_decimal abs_dec(s21_decimal value) {
  if (get_bit(value, 127) != 0) set_bit(&value, 127, 0);
  return value;
}
int is_zero(s21_decimal value) {
  int error = 0;
  s21_decimal zero_value = {{0, 0, 0, 0}};
  for (int i = 2; i > -1; i--) {
    if (value.bits[i] != zero_value.bits[i]) error++;
  }
  return error == 0 ? 1 : 0;
}
void dec_copy(s21_decimal og, s21_decimal *res) {
  for (int i = 0; i < 128; i++) {
    set_bit(res, i, get_bit(og, i));
  }
}
void bit_addition(s21_decimal value1, s21_decimal value2, s21_decimal *res) {
  int tmp = 0, sum = 0;
  for (int i = 0; i < 96; i++) {
    sum = get_bit(value1, i) + get_bit(value2, i);
    if (sum == 2) {
      if (tmp == 1) {
        set_bit(res, i, 1);
      } else {
        set_bit(res, i, 0);
        tmp = 1;
      }
    } else if (sum == 1) {
      if (tmp == 1) {
        set_bit(res, i, 0);
      } else {
        set_bit(res, i, 1);
      }
    } else if (sum == 0) {
      if (tmp == 1) {
        set_bit(res, i, 1);
        tmp = 0;
      } else {
        set_bit(res, i, 0);
      }
    }
  }
}
int first_bit(s21_decimal value) {
  int bit = 95;
  for (; bit >= 0 && get_bit(value, bit) == 0; bit--) {
  }
  return bit;
}
int set_pow(s21_decimal value, s21_decimal *result, int int_pow) {
  int error = 0;
  *result = value;
  if (result == NULL) {
    error = 1;
  }
  if (int_pow <= 28) {
    for (int i = 112; i < 120; i++) {
      if (fmod(int_pow, 2))
        set_bit(result, i, 1);
      else
        set_bit(result, i, 0);
      int_pow = int_pow / 2;
    }
  } else {
    error = 1;
  }
  return error;
}

int s21_is_less_mantissa(s21_bigdecimal value_1, s21_bigdecimal value_2) {
  int high_bit = 0;
  for (int index_bit = SIZE_S21_bigdecimal - 1; index_bit >= 0; index_bit--) {
    buffer val1, val2;
    s21_from_bigdecimal_to_buffer(&value_1, &val1);
    s21_from_bigdecimal_to_buffer(&value_2, &val2);
    int bit_value_1 = s21_get_bit_buff(val1, index_bit);
    int bit_value_2 = s21_get_bit_buff(val2, index_bit);
    if (bit_value_1 ^ bit_value_2) {
      high_bit = bit_value_2;
      break;
    }
  }
  return high_bit;
}

void left(s21_decimal *value) {
  int bit31 = get_bit(*value, 31);
  int bit63 = get_bit(*value, 63);
  value->bits[0] <<= 1;
  value->bits[1] <<= 1;
  value->bits[2] <<= 1;
  if (bit31) set_bit(value, 32, 1);
  if (bit63) set_bit(value, 64, 1);
}

//////////////////////////

///////////////////////////

int is_zero1(s21_decimal value) {
  return (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0) ? 1
                                                                          : 0;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  *result = (s21_decimal){{0, 0, 0, 0}};
  if (is_zero1(value_2)) {
    error = 3;
  } else if (is_zero1(value_1)) {
    error = 0;
  } else {
    s21_bigdecimal first = to_big(value_1), second = to_big(value_2),
                   result_big = {0};
    s21_add_accurance(first, &first);
    s21_div_big(first, second, &result_big);
    error = normalize_to_usual(result_big, result);
  }
  return error;
}

int s21_add_accurance(s21_bigdecimal first, s21_bigdecimal *result) {
  int exp = first.exp, sign = s21_get_signed(first);
  s21_set_exp1(&first, 0);
  for (int i = 0; i < 35; i++) {
    s21_mul_big(first, (s21_bigdecimal){{10u, 0, 0, 0, 0, 0, 0}, 0, 0}, &first);
    exp++;
  }
  s21_set_exp1(&first, exp);
  if (sign) s21_set_sign1(&first);
  *result = first;
  return 0;
}

int s21_div_big(s21_bigdecimal first, s21_bigdecimal second,
                s21_bigdecimal *result) {
  *result = clean_up();
  int new_exp = abs(s21_get_expen(first) - s21_get_expen(second));
  int new_sign = s21_get_signed(first) + s21_get_signed(second);
  s21_set_exp1(&first, 0);
  s21_set_exp1(&second, 0);
  int flag = 0;
  s21_bigdecimal temp = second;
  int temp_pos = get_pos_of(first) - get_pos_of(second);
  if (temp_pos > 0) s21_shift_left1(&temp, temp_pos);

  s21_set_exp1(&first, 0);
  s21_set_exp1(&second, 0);
  s21_set_exp1(&temp, 0);
  while (s21_is_greater_or_equal_big(temp, second)) {
    flag = 1;
    if (s21_is_greater_or_equal_big(first, temp)) {
      s21_set_bit1(result, temp_pos, 1);
      s21_sub_big(first, temp, &first);
    } else {
      s21_set_bit1(result, temp_pos, 0);
    }
    temp_pos--;
    s21_shift_right1(&temp, 1);
  }
  if (flag) {
    s21_set_exp1(result, new_exp);
    if (new_sign % 2 == 1) s21_set_sign1(result);
  }
  return flag;
}

int get_pos_of(s21_bigdecimal temp) {
  int temp_pos = 0;
  for (int i = 7 * 32 - 1; i >= 0; i--) {
    if (s21_get_bit1(temp, i)) {
      temp_pos = i;
      i = -1;
    }
  }
  return temp_pos;
}

s21_bigdecimal clean_up() {
  s21_bigdecimal new = {0};
  return new;
}

int s21_sub_big(s21_bigdecimal first, s21_bigdecimal second,
                s21_bigdecimal *result) {
  int sign = s21_get_signed(first);
  unsigned int keeper = 0;
  for (int i = 0; i < 7 * 32; i++) {
    int bit1 = s21_get_bit1(first, i);
    int bit2 = s21_get_bit1(second, i);
    bit1 += keeper;
    if (bit1 == 2) {
      bit1 = 0;
      keeper = 0;
    }
    if (bit2 > bit1) {
      bit1 = 2;
      keeper = 1;
    }
    s21_set_bit1(result, i, (bit1 - bit2));
  }
  if (sign) s21_set_sign1(result);
  s21_set_exp1(result, s21_get_expen(first));
  return 0;
}

void s21_shift_right1(s21_bigdecimal *origin, int shift) {
  s21_bigdecimal value = *origin;
  int i = 0;
  for (; i < (32 * 7) - shift; i++) {
    s21_set_bit1(&value, i, s21_get_bit1(value, i + shift));
  }
  for (; i < 32 * 7; i++) s21_set_bit1(&value, i, 0);
  *origin = value;
}

//

int get_last(s21_bigdecimal value) {
  s21_bigdecimal temp = value;
  s21_div_big(temp, (s21_bigdecimal){{100u, 0, 0, 0, 0, 0, 0, 0}, 0, 0}, &temp);
  s21_mul_big(temp, (s21_bigdecimal){{100u, 0, 0, 0, 0, 0, 0, 0}, 0, 0}, &temp);
  s21_sub_big(value, temp, &temp);
  return temp.bits[0];
}

int not_normal(s21_bigdecimal value) {
  int error = 0;
  for (int i = 3; i < 7; i++) {
    if (value.bits[i] != 0) error = 1;
  }
  return error;
}

int big_is_zero(s21_bigdecimal value) {
  int flag = 1;
  for (int i = 0; i < 7; i++) {
    if (value.bits[i] != 0) flag = 0;
  }
  return flag;
}

int normalize_to_usual(s21_bigdecimal result_big, s21_decimal *result) {
  int exp = result_big.exp, sign = result_big.sign, error = 0;
  s21_set_exp1(&result_big, 0);
  int flag = 0;
  if (not_normal(result_big) || (get_last(result_big) % 10 == 0 && exp > 0) ||
      exp > 28)
    flag = 1;
  while (flag && exp > 0) {
    int two_last = get_last(result_big);
    int remainder = two_last % 10, even = two_last / 10;
    s21_div_big(result_big, (s21_bigdecimal){{10u, 0, 0, 0, 0, 0, 0, 0}, 0, 0},
                &result_big);
    if (even % 2 == 0 && remainder == 5) remainder--;
    if (remainder >= 5)
      s21_add_big(result_big, (s21_bigdecimal){{1u, 0, 0, 0, 0, 0, 0, 0}, 0, 0},
                  &result_big);
    exp--;
    if (exp > 28 && big_is_zero(result_big))
      flag = 0;
    else if (not_normal(result_big))
      flag = 1;
    else if (get_last(result_big) % 10 == 0 && exp > 0)
      flag = 1;
    else if (exp > 28)
      flag = 1;
    else
      flag = 0;
  }
  if (!not_normal(result_big) && exp <= 28) {
    *result = (s21_decimal){{0, 0, 0, 0}};
    s21_set_exp1(&result_big, exp);
    if (sign) s21_set_sign1(&result_big);
    result->bits[0] = result_big.bits[0];
    result->bits[1] = result_big.bits[1];
    result->bits[2] = result_big.bits[2];
    result->bits[3] = result_big.bits[7];
  } else {
    if (exp == 0 && not_normal(result_big) && sign == 0)
      error = 1;
    else
      error = 2;
  }
  return error;
}
