#include "../s21_decimal.h"

int s21_is_less(s21_decimal a, s21_decimal b) {
  if (is_zero1(a)) set_experence(&a, 0);
  if (is_zero1(b)) set_experence(&b, 0);
  s21_bigdecimal first = to_big(a), second = to_big(b);
  int value = 0;
  if (first.sign != second.sign)
    value = (first.sign == 1) ? 1 : 0;
  else if (first.sign == 0)
    value = s21_is_less_big(first, second);
  else
    value = s21_is_less_big(second, first);
  return value;
}

int s21_is_greater(s21_decimal a, s21_decimal b) {
  if (is_zero1(a)) set_experence(&a, 0);
  if (is_zero1(b)) set_experence(&b, 0);
  s21_bigdecimal first = to_big(a), second = to_big(b);
  int value = 0;
  if (first.sign != second.sign)
    value = (first.sign == 1) ? 0 : 1;
  else if (first.sign == 0)
    value = s21_is_greater_big(first, second);
  else
    value = s21_is_greater_big(second, first);
  return value;
}

int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
  if (is_zero1(a)) set_experence(&a, 0);
  if (is_zero1(b)) set_experence(&b, 0);
  s21_bigdecimal first = to_big(a), second = to_big(b);
  int value = 0;
  if (first.sign != second.sign)
    value = (first.sign == 1) ? 1 : 0;
  else if (first.sign == 0)
    value = s21_is_less_or_equal_big(first, second);
  else
    value = s21_is_less_or_equal_big(second, first);
  return value;
}

int s21_is_greater_or_equal(s21_decimal a, s21_decimal b) {
  if (is_zero1(a)) set_experence(&a, 0);
  if (is_zero1(b)) set_experence(&b, 0);
  s21_bigdecimal first = to_big(a), second = to_big(b);
  int value = 0;
  if (first.sign != second.sign)
    value = (first.sign == 1) ? 0 : 1;
  else if (first.sign == 0)
    value = s21_is_greater_or_equal_big(first, second);
  else
    value = s21_is_greater_or_equal_big(second, first);
  return value;
}
/// @brief
/// @param value
/// @return
s21_bigdecimal to_big(s21_decimal value) {
  s21_bigdecimal export = {0};
  for (int i = 0; i < 3; i++) export.bits[i] = value.bits[i];
  export.bits[7] = value.bits[3];
  export.exp = s21_get_expen(export);
  export.sign = s21_get_signed(export);
  return export;
}

int s21_get_signed(s21_bigdecimal value) {
  unsigned int mask = value.bits[7] >> 31;
  return (mask) ? 1 : 0;
}
int s21_get_expen(s21_bigdecimal value) {
  unsigned int mask = 255 << 16;
  mask = value.bits[7] & mask;
  mask = mask << 1;
  mask = mask >> 17;
  return mask;
}

void set_experence(s21_decimal* result, int new_exp) {
  unsigned int mask = new_exp;
  mask = mask << 16;
  result->bits[3] = 0;
  result->bits[3] |= mask;
}

int s21_is_less_big(s21_bigdecimal first, s21_bigdecimal second) {
  return basic_compare(first, second) == 1 ? 1 : 0;
}

int s21_is_less_or_equal_big(s21_bigdecimal first, s21_bigdecimal second) {
  return basic_compare(first, second) >= 0 ? 1 : 0;
}

int s21_is_greater_big(s21_bigdecimal first, s21_bigdecimal second) {
  return basic_compare(first, second) == -1 ? 1 : 0;
}

int s21_is_greater_or_equal_big(s21_bigdecimal first, s21_bigdecimal second) {
  return basic_compare(first, second) <= 0 ? 1 : 0;
}
int s21_is_equal_big(s21_bigdecimal first, s21_bigdecimal second) {
  return basic_compare(first, second) == 0 ? 1 : 0;
}
int s21_is_not_equal_big(s21_bigdecimal first, s21_bigdecimal second) {
  return basic_compare(first, second) != 0 ? 1 : 0;
}

/// @brief universal function for comparing;
/// @param first
/// @param second
/// @return -1 - first is greater, 0- equal, 1-second is greater;
int basic_compare(s21_bigdecimal first, s21_bigdecimal second) {
  normalize_exp(&first, &second, 1);
  int flag = 0;
  for (int i = 7 * 32 - 1; i >= 0; i--) {
    if (s21_get_bit1(first, i) ^ s21_get_bit1(second, i)) {
      if (s21_get_bit1(first, i)) {
        flag = -1;
      } else {
        flag = 1;
      }
      i = 0;
    }
  }
  return flag;
}

int s21_get_bit1(s21_bigdecimal value, int bit) {
  unsigned int mask = 1u << (bit % 32);
  return (value.bits[bit / 32] & mask) ? 1 : 0;
}

int normalize_exp(s21_bigdecimal* first, s21_bigdecimal* second, int to_big) {
  s21_bigdecimal a = *first, b = *second, temp = {0};
  temp.bits[0] = 10u;

  int exp1 = a.exp, exp2 = b.exp, sign1 = a.sign, sign2 = b.sign;
  int shift = exp1 - exp2;

  if (shift == 0) {
    return 1;
  }
  if (shift < 0) {
    exp1 += 1;
    s21_set_exp1(first, s21_get_expen(temp));
    s21_mul_big(*first, temp, &a);
  } else if (shift > 0) {
    exp2 += 1;
    s21_set_exp1(second, s21_get_expen(temp));
    s21_mul_big(*second, temp, &b);
  }

  s21_set_exp1(&a, exp1);
  s21_set_exp1(&b, exp2);
  if (sign1) s21_set_sign1(&a);
  if (sign2) s21_set_sign1(&b);
  *first = a;
  *second = b;
  return normalize_exp(first, second, to_big);
}

void s21_set_exp1(s21_bigdecimal* result, int new_exp) {
  unsigned int mask = new_exp;
  int sign = s21_get_signed(*result);
  mask = mask << 16;
  result->bits[7] = 0;
  result->bits[7] |= mask;
  if (sign) s21_set_sign1(result);
  result->exp = s21_get_expen(*result);
}

void s21_set_sign1(s21_bigdecimal* value) {
  unsigned int mask = 1u << 31;
  value->bits[7] |= mask;
  value->sign = 1;
}

int s21_mul_big(s21_bigdecimal first, s21_bigdecimal second,
                s21_bigdecimal* result) {
  s21_bigdecimal temp_result = {0};
  int new_sign = s21_get_signed(first) + s21_get_signed(second);
  int new_exp = s21_get_expen(first) + s21_get_expen(second);
  s21_set_exp1(&temp_result, new_exp);
  if (new_sign % 2 == 1) s21_set_sign1(&temp_result);

  for (int i = 0; i < 7 * 32; i++) {
    s21_bigdecimal temp = {0};
    temp = second;
    int bit = s21_get_bit1(first, i);
    if (bit) {
      s21_shift_left1(&temp, i);
      s21_add_big(temp_result, temp, &temp_result);
    }
  }
  *result = temp_result;
  return 1;
}

void s21_shift_left1(s21_bigdecimal* origin, int shift) {
  s21_bigdecimal value = *origin;
  int last = 7 * 32 - 1;
  for (; last >= shift; last--) {
    s21_set_bit1(&value, last, s21_get_bit1(value, last - shift));
  }
  for (int i = 0; i < shift; i++) {
    s21_set_bit1(&value, i, 0);
  }
  *origin = value;
}

int s21_add_big(s21_bigdecimal first, s21_bigdecimal second,
                s21_bigdecimal* result) {
  int sign = s21_get_signed(first);
  unsigned int keeper = 0;
  for (int i = 0; i < 7 * 32; i++) {
    unsigned int value =
        s21_get_bit1(second, i) + keeper + s21_get_bit1(first, i);
    keeper = value / 2;
    s21_set_bit1(result, i, value % 2);
  }
  s21_set_exp1(result, s21_get_expen(first));
  if (sign) s21_set_sign1(result);
  return 0;
}

void s21_set_bit1(s21_bigdecimal* result, int bit, int value) {
  unsigned int mask = 1u << (bit % 32);
  if (value)
    result->bits[bit / 32] |= mask;
  else
    result->bits[bit / 32] &= ~mask;
}
int s21_is_equal(s21_decimal first, s21_decimal second) {
  s21_bigdecimal f = s21_write_to_s21_bigdecimal(first);
  s21_bigdecimal s = s21_write_to_s21_bigdecimal(second);
  buffer f1, s1;
  s21_from_bigdecimal_to_buffer(&f, &f1);
  s21_from_bigdecimal_to_buffer(&s, &s1);
  s21_normalization(&f1, &s1);
  bool res = 1;
  if (f.sign == s.sign && f.exp == s.exp) {
    for (int i = 0; i < 8; i++) {
      if (f.bits[i] == s.bits[i]) {
        res *= 1;
      } else
        res = 0;
    }
  } else
    res = 0;
  return res;
}
int s21_is_not_equal(s21_decimal first, s21_decimal second) {
  return (!(s21_is_equal(first, second)));
}
s21_bigdecimal s21_write_to_s21_bigdecimal(s21_decimal dec) {
  s21_bigdecimal buff = {0};
  s21_init_s21_bigdecimal(&buff);
  for (int i = 0; i < 3; i++) buff.bits[i] = dec.bits[i];
  buff.exp = s21_get_squared(dec);
  buff.sign = s21_get_sign(dec);
  return buff;
}
void s21_init_s21_bigdecimal(s21_bigdecimal* buff) {
  for (int i = 0; i < 6; i++) buff->bits[i] = 0;
  buff->exp = 0;
  buff->sign = 0;
}

int s21_multiplication_mantissa(buffer value_1, buffer value_2,
                                buffer* result) {
  buffer tmp = {0};
  s21_init_buffer(&tmp);
  int bit_value_2;
  int is_overflow = 0;
  for (int index_bit = 0; index_bit < SIZE_BUFFER && !is_overflow;
       ++index_bit) {
    bit_value_2 = s21_get_bit_buff(value_2, index_bit);
    if (bit_value_2) {
      buffer temp = value_1;
      for (int i = 0; i < index_bit; i++) {
        if (s21_shift_left(&temp)) {
          is_overflow = 1;
          break;
        }
      }
      if (is_overflow || (is_overflow = s21_adding_mantissa(temp, tmp, &tmp)))
        break;
    }
  }
  is_overflow = s21_is_overflow_buffer(result);
  if (!is_overflow) *result = tmp;

  return is_overflow;
}

int s21_adding_mantissa(buffer value_1, buffer value_2, buffer* result) {
  int bit_value_1, bit_value_2;
  int carry = 0, is_overflow = OK;
  for (int index_bit = 0; index_bit < SIZE_BUFFER; ++index_bit) {
    bit_value_1 = s21_get_bit_buff(value_1, index_bit);
    bit_value_2 = s21_get_bit_buff(value_2, index_bit);
    int sum = bit_value_1 + bit_value_2 + carry;
    carry = sum >> 1;
    sum &= 1;
    s21_set_bit_buff(result, index_bit, sum);
  }
  is_overflow = s21_is_overflow_buffer(result);
  return is_overflow;
}

void s21_from_bigdecimal_to_buffer(s21_bigdecimal* divisor, buffer* value_2) {
  value_2->bits[0] = divisor->bits[0];
  value_2->bits[1] = divisor->bits[1];
  value_2->bits[2] = divisor->bits[2];
  value_2->bits[3] = divisor->bits[3];
  value_2->bits[4] = divisor->bits[4];
  value_2->bits[5] = divisor->bits[5];
  value_2->bits[6] = divisor->bits[6];
  value_2->bits[7] = divisor->bits[7];
  value_2->exp = divisor->exp;
  value_2->sign = divisor->sign;
}

void s21_normalization(buffer* value_1, buffer* value_2) {
  buffer* max_value = (value_1->exp > value_2->exp) ? value_1 : value_2;
  buffer* min_value = (value_1->exp < value_2->exp) ? value_1 : value_2;
  int e_max = max_value->exp;
  int e_min = min_value->exp;
  buffer ten = {0};
  s21_init_buffer(&ten);
  ten.bits[0] = 10;
  while (e_max != e_min) {
    if (e_min < EXP_MAX) {
      s21_call_arithm_operation_extention(&s21_multiplication_mantissa,
                                          min_value, ten);
      e_min++;
      min_value->exp = e_min;
    } else {
      e_max--;
      max_value->exp = e_max;
    }
  }
}
int s21_get_bit_buff(buffer decimal, int index) {
  return (decimal.bits[INDEX_TETRAD(index)] >> INDEX_BIT(index)) & 1;
}
int s21_get_squared(s21_decimal decimal) {
  int sign = s21_get_sign(decimal);
  s21_set_sign(&decimal, 0);
  int squared = decimal.bits[3] >> 16;
  s21_set_sign(&decimal, sign);
  return squared;
}
int s21_get_sign(s21_decimal decimal) { return get_bit(decimal, INDEX_SIGN); }
int get_bit(s21_decimal decimal, int index) {
  return (decimal.bits[INDEX_TETRAD(index)] >> INDEX_BIT(index)) & 1;
}
void s21_init_buffer(buffer* buff) {
  for (int i = 0; i < 6; i++) buff->bits[i] = 0;
  buff->exp = 0;
  buff->sign = 0;
}
int s21_shift_left(buffer* value) {
  int is_overflow = s21_get_bit_buff(*value, SIZE_BUFFER - 1);
  for (int i = SIZE_BUFFER - 1; i >= 0; i--) {
    if (i == 0)
      s21_set_bit_buff(value, i, 0);
    else
      s21_set_bit_buff(value, i, s21_get_bit_buff(*value, i - 1));
  }
  return is_overflow;
}
int s21_shift_left_by_power(buffer* value, int num) {
  int err = 0;
  for (; num - 1 >= 0; num--) err = s21_shift_left(value);
  return err;
}

int s21_shift_right_by_power(buffer* value, int num) {
  int err = 0;
  for (; num - 1 >= 0; num--) err = s21_shift_right(value);
  return err;
}
int s21_is_overflow_buffer(buffer* result) {
  return s21_get_bit_buff(*result, SIZE_BUFFER - 1);
}
void s21_set_sign(s21_decimal* decimal, bool sign) {
  set_bit(decimal, INDEX_SIGN, sign);
}
void s21_set_bit_buff(buffer* decimal, int index, int bit) {
  if (bit == 0)
    decimal->bits[INDEX_TETRAD(index)] &= ~(1 << INDEX_BIT(index));
  else
    decimal->bits[INDEX_TETRAD(index)] |= 1 << INDEX_BIT(index);
}
int s21_shift_right(buffer* value) {
  int is_overflow = s21_get_bit_buff(*value, 1);
  for (int i = 0; i < SIZE_BUFFER; i++) {
    if (i == SIZE_BUFFER - 1)
      s21_set_bit_buff(value, i, 0);
    else
      s21_set_bit_buff(value, i, s21_get_bit_buff(*value, i + 1));
  }
  return is_overflow;
}
int s21_call_arithm_operation_extention(s21_arithm_operation_extention func,
                                        buffer* value_1, buffer value_2) {
  int is_overflow = 0;
  buffer tmp_res = {0};
  s21_init_buffer(&tmp_res);
  is_overflow = func(*value_1, value_2, &tmp_res);
  tmp_res.exp = value_1->exp;
  tmp_res.sign = value_1->sign;
  *value_1 = tmp_res;

  return is_overflow;
}
int s21_subtracting_mantissa(buffer value_1, buffer value_2, buffer* result) {
  int bit_value_1, bit_value_2;
  int carry = 0;
  for (int index_bit = 0; index_bit < SIZE_BUFFER; ++index_bit) {
    bit_value_1 = s21_get_bit_buff(value_1, index_bit);
    bit_value_2 = s21_get_bit_buff(value_2, index_bit);
    int diff = bit_value_1 - bit_value_2 - carry;
    if (diff < 0) {
      diff += 2;
      carry = 1;
    } else
      carry = 0;

    s21_set_bit_buff(result, index_bit, diff);
  }
  return s21_is_overflow_buffer(result);
}