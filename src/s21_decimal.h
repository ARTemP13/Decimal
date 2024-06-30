#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR 1
#define NUMBER_LARGE 1
#define NUMBER_SMALL 2
#define DIVISION_ZERO 3

#define BITS_23 8388608
#define BITS_16 65536
#define BYTE 32
#define S21_INT_MAX 2147483647
#define SIZE_S21_bigdecimal BYTE * 8
#define EXP_MAX 28
#define SIZE_TETRAD 32
#define SIZE_BUFFER SIZE_TETRAD * 8
#define SIZE_DECIMAL 96
#define INDEX_SIGN (SIZE_DECIMAL - 1) + SIZE_TETRAD
#define INDEX_TETRAD(index) index / SIZE_TETRAD
#define INDEX_BIT(index) index % SIZE_TETRAD

#define EPS 1e-28
#define S21_POS_INF 1.0 / 0.0
#define S21_NEG_INF -1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define DEGREE_DECIMAL 28
#define OK 0
#define CONVERTATION_ERROR 1
#define CALCULATION_ERROR 1
#define POS_INFINITY 1
#define NEG_INFINITY 2

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
  int exp;
  bool sign;
} s21_bigdecimal;

typedef struct {
  unsigned int bits[8];
  int exp;
  bool sign;
} buffer;

#define SWAP(x, y, T) \
  do {                \
    T SWAP = x;       \
    x = y;            \
    y = SWAP;         \
  } while (0)
// base funcations
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int s21_is_less(s21_decimal first, s21_decimal second);
int s21_is_greater(s21_decimal first, s21_decimal second);
int s21_is_less_or_equal(s21_decimal first, s21_decimal second);
int s21_is_greater_or_equal(s21_decimal first, s21_decimal second);
int s21_is_equal(s21_decimal first, s21_decimal second);
int s21_is_not_equal(s21_decimal first, s21_decimal second);

// additional functions
int s21_is_less_mantissa(s21_bigdecimal value_1, s21_bigdecimal value_2);
int s21_is_equal_mantissa(s21_bigdecimal value_1, s21_bigdecimal value_2);
int s21_is_less_or_equal_mantissa(s21_bigdecimal value_1,
                                  s21_bigdecimal value_2);
int s21_is_greater_mantissa(s21_bigdecimal value_1, s21_bigdecimal value_2);
int s21_is_greater_or_equal_mantissa(s21_bigdecimal value_1,
                                     s21_bigdecimal value_2);
s21_bigdecimal s21_write_to_s21_bigdecimal(s21_decimal dec);
void s21_init_s21_bigdecimal(s21_bigdecimal *buff);
void s21_normalization(buffer *value_1, buffer *value_2);
int s21_adding_mantissa(buffer value_1, buffer value_2, buffer *result);
int s21_multiplication_mantissa(buffer value_1, buffer value_2, buffer *result);
void s21_from_bigdecimal_to_buffer(s21_bigdecimal *divisor, buffer *value_2);
int s21_get_bit_buff(buffer decimal, int index);
int s21_get_squared(s21_decimal decimal);
int s21_get_sign(s21_decimal decimal);
int get_bit(s21_decimal decimal, int index);
void s21_init_buffer(buffer *buff);
int s21_shift_left(buffer *value);
int s21_shift_left_by_power(buffer *value, int num);
int s21_shift_right_by_power(buffer *value, int num);
int s21_is_overflow_buffer(buffer *result);
void s21_set_sign(s21_decimal *decimal, bool sign);
void s21_set_bit_buff(buffer *decimal, int index, int bit);
int s21_shift_right(buffer *value);
typedef int s21_arithm_operation_extention(buffer, buffer, buffer *);
int s21_call_arithm_operation_extention(s21_arithm_operation_extention func,
                                        buffer *value_1, buffer value_2);
int s21_subtracting_mantissa(buffer value_1, buffer value_2, buffer *result);

s21_bigdecimal to_big(s21_decimal value);
int s21_get_signed(s21_bigdecimal value);
int s21_get_expen(s21_bigdecimal value);
void set_experence(s21_decimal *result, int new_exp);
int s21_is_less_big(s21_bigdecimal first, s21_bigdecimal second);
int s21_is_less_or_equal_big(s21_bigdecimal first, s21_bigdecimal second);
int s21_is_greater_big(s21_bigdecimal first, s21_bigdecimal second);
int s21_is_greater_or_equal_big(s21_bigdecimal first, s21_bigdecimal second);
int s21_is_equal_big(s21_bigdecimal first, s21_bigdecimal second);
int s21_is_not_equal_big(s21_bigdecimal first, s21_bigdecimal second);
int basic_compare(s21_bigdecimal first, s21_bigdecimal second);
int s21_get_bit1(s21_bigdecimal value, int bit);
int normalize_exp(s21_bigdecimal *first, s21_bigdecimal *second, int to_big);
void s21_set_exp1(s21_bigdecimal *result, int new_exp);
void s21_set_sign1(s21_bigdecimal *value);
int s21_mul_big(s21_bigdecimal first, s21_bigdecimal second,
                s21_bigdecimal *result);
void s21_shift_left1(s21_bigdecimal *origin, int shift);
int s21_add_big(s21_bigdecimal first, s21_bigdecimal second,
                s21_bigdecimal *result);
void s21_set_bit1(s21_bigdecimal *result, int bit, int value);
int s21_add_accurance(s21_bigdecimal first, s21_bigdecimal *result);
int s21_div_big(s21_bigdecimal first, s21_bigdecimal second,
                s21_bigdecimal *result);
int get_pos_of(s21_bigdecimal temp);
s21_bigdecimal clean_up();
int s21_sub_big(s21_bigdecimal first, s21_bigdecimal second,
                s21_bigdecimal *result);
void s21_shift_right1(s21_bigdecimal *origin, int shift);
int is_zero1(s21_decimal value);
int get_last(s21_bigdecimal value);
int not_normal(s21_bigdecimal value);
int big_is_zero(s21_bigdecimal value);
int normalize_to_usual(s21_bigdecimal result_big, s21_decimal *result);

void scale_equalize(s21_decimal *value1, s21_decimal *value2);
int scale_increase(s21_decimal *value);
void scale_decrease(s21_decimal *value);
s21_decimal abs_dec(s21_decimal value);
void dec_copy(s21_decimal og, s21_decimal *res);
int is_zero(s21_decimal value);
void bit_addition(s21_decimal value1, s21_decimal value2, s21_decimal *res);
int first_bit(s21_decimal value);
int set_pow(s21_decimal value, s21_decimal *result, int int_pow);
int s21_is_less_mantissa(s21_bigdecimal value_1, s21_bigdecimal value_2);
void left(s21_decimal *value);
void bit_substraction(s21_decimal value1, s21_decimal value2, s21_decimal *res);

int s21_get_bit(unsigned int dpt, int position);
int s21_length_bit(s21_decimal value1);
int s21_is_negative(s21_decimal value1);
int s21_degree(s21_decimal value1);
void s21_delete_negative(s21_decimal *value1);
void s21_init_zero(s21_decimal *value);
void set_bit(s21_decimal *decl, int index, int bit);
int s21_get_exp_decimal(s21_decimal *value);
void s21_set_bit(unsigned int *src, int bit, int position);
void s21_truncate_res(s21_decimal value, s21_decimal *result, int pow);
void s21_div_res(int *j, int buf_dec, char *buf, char *res, int *res_i,
                 int *flag_i, int index);
void s21_refresh_value(s21_decimal *value, int res_i, char *res);
int s21_div_10(s21_decimal *value);
int s21_get_float_scale(float src);
void s21_write_to_the_decimal(int sign, int count, int tmp_src,
                              s21_decimal *dst);
void s21_div10_man(int *j, char *buf, char *res, int *res_i, int *flag_i);

#endif
