#include "../s21_decimal.h"

typedef union {
  int src_int;
  float src_float;
} bits_float;

void s21_write_to_the_decimal(int sign, int count, int tmp_src,
                              s21_decimal *dst) {
  bits_float mantissa;
  mantissa.src_float = tmp_src;
  int scale = s21_get_float_scale(mantissa.src_float);
  dst->bits[scale / 32] |= 1 << scale % 32;
  int j = 22;
  for (int i = scale - 1; j >= 0; i--) {
    if ((mantissa.src_int & (1 << j)) != 0) {
      dst->bits[i / 32] |= 1 << i % 32;
    }
    j -= 1;
  }
  s21_set_bit(&dst->bits[3], sign, 31);
  dst->bits[3] |= (count << 16);
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int err_code = OK;
  s21_init_zero(dst);
  if (src == S21_POS_INF || src == S21_NEG_INF) {
    err_code = CONVERTATION_ERROR;
  } else if (__builtin_isnan(src)) {
    err_code = CONVERTATION_ERROR;
  } else if (fabs(src) > 0 && fabs(src) < EPS) {
    err_code = CONVERTATION_ERROR;
  } else {
    unsigned int *p = (void *)&src;
    unsigned int bit = *p;
    unsigned int sign = bit >> 31;
    int scale = s21_get_float_scale(src);
    int count = 0;
    double dbl_src = fabs(src);
    while (!((int)dbl_src / (int)pow(2, 21)) && count < EXP_MAX) {
      count += 1;
      dbl_src *= 10;
    }
    dbl_src = (int)(dbl_src + 0.5);
    if (count <= EXP_MAX && (scale >= -93 && scale <= 95)) {
      int tmp_src = dbl_src;
      while (tmp_src % 10 == 0 && count > 0) {
        count -= 1;
        tmp_src /= 10;
      }
      s21_write_to_the_decimal(sign, count, tmp_src, dst);
    }
  }
  return err_code;
}