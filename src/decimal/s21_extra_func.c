#include "../s21_decimal.h"

int s21_get_bit(unsigned int dpt,
                int position) {  // возращает какой бит на данной позиции
  bool g = (bool)(dpt & (1 << position));
  return g;
}

int s21_length_bit(s21_decimal value1) {  // количество битов
  int length = 0;
  int current_lenght = 0;
  int flag = 0;
  if (value1.bits[2] != 0) {
    length = 64;
    flag = 2;
  } else if (value1.bits[1] != 0) {
    length = 32;
    flag = 1;
  } else {
    length = 0;
    flag = 0;
  }
  for (int i = 0; i < BYTE; i++) {
    if (s21_get_bit(value1.bits[flag], i)) current_lenght = i;
  }
  if (current_lenght == 0 && flag == 0)
    length = 0;
  else
    length += current_lenght + 1;

  return length;
}
int s21_is_negative(s21_decimal value1) {  // негативное ли число
  int negative = 0;
  if (value1.bits[3] > BITS_23) negative = 1;
  return negative;
}

int s21_degree(s21_decimal value1) {  // определяет степень
  int degree = 0;
  value1.bits[3] = value1.bits[3] >> 16;
  for (int i = 0; i < 5; i++) {
    degree += (s21_get_bit(value1.bits[3], i) * pow(2, i));
  }
  return degree;
}
void s21_delete_negative(s21_decimal *value1) {  // убирает отрицание
  (*value1).bits[3] = (*value1).bits[3] << 1;
  (*value1).bits[3] = (*value1).bits[3] >> 1;
}
void s21_init_zero(s21_decimal *value) {  // инициализация нулями
  (*value).bits[0] = 0;
  (*value).bits[1] = 0;
  (*value).bits[2] = 0;
  (*value).bits[3] = 0;
}
void set_bit(s21_decimal *decl, int index, int bit) {
  int ind32 = index / 32, num32 = index % 32;
  if (bit == 1) {
    decl->bits[ind32] |= (1u << num32);
  } else {
    decl->bits[ind32] &= (~((1u) << num32));
  }
}

void s21_set_bit(unsigned int *src, int bit, int position) {
  unsigned int tmp_value = bit;
  *src |= (tmp_value << position);
}

int s21_get_exp_decimal(s21_decimal *value) {
  return ((int)value->bits[3] << 1) >> 17;
}

int s21_get_float_scale(float src) {
  unsigned int *p = (void *)&src;
  unsigned int bit = *p;
  return ((bit << 1) >> 24) - 127;
}

int s21_div_10(s21_decimal *value) {
  char *res = (char *)malloc(110);
  int res_i = 0;
  int flag_i = 0;
  char *buf = (char *)malloc(20);
  int k = 0;
  int count_bit = 31;
  int c_bit = s21_length_bit(*value);
  int j = 0;
  count_bit = (c_bit % 32);
  if (c_bit == 32 || c_bit == 64) count_bit = 31;
  if (c_bit > 32 && c_bit < 65) {
    k = 1;
  } else if (c_bit > 64) {
    k = 2;
  }
  while (s21_get_bit(value->bits[k], count_bit) != 1) {
    count_bit--;
  }
  for (int i = 96 - c_bit; i < 96; i++) {
    int bit = s21_get_bit(value->bits[k], count_bit);
    if (j != 0 || bit != 0) {
      buf[j] = bit + 48;
      j++;
    }
    if (flag_i == 1 && j < 4) {
      res[res_i] = 48;
      res_i++;
    }
    s21_div10_man(&j, buf, res, &res_i, &flag_i);
    if (count_bit == 0) {
      count_bit = 32;
      k--;
    }
    count_bit--;
  }
  s21_refresh_value(value, res_i, res);
  free(buf);
  free(res);
  return 1;
}

void s21_div10_man(int *j, char *buf, char *res, int *res_i, int *flag_i) {
  if (*j >= 4) {
    if (*j == 4) {
      int buf_dec = ((buf[3] - 48) * pow(2, 0)) + ((buf[2] - 48) * pow(2, 1)) +
                    ((buf[1] - 48) * pow(2, 2)) + ((buf[0] - 48) * pow(2, 3));
      if (buf_dec >= 10) {
        s21_div_res(j, buf_dec, buf, res, res_i, flag_i, 3);
      } else {
        if (*flag_i == 1) {
          res[*res_i] = 48;
          (*res_i)++;
        }
      }
    } else {
      int buf_dec = ((buf[4] - 48) * pow(2, 0)) + ((buf[3] - 48) * pow(2, 1)) +
                    ((buf[2] - 48) * pow(2, 2)) + ((buf[1] - 48) * pow(2, 3)) +
                    ((buf[0] - 48) * pow(2, 4));
      s21_div_res(j, buf_dec, buf, res, res_i, flag_i, 4);
    }
  }
}

void s21_div_res(int *j, int buf_dec, char *buf, char *res, int *res_i,
                 int *flag_i, int index) {
  (*j) = 0;
  buf_dec -= 10;
  memset(buf, ' ', 20);
  int bit = s21_get_bit((unsigned int)buf_dec, index);
  if (bit != 0) {
    buf[(*j)] = bit + 48;
    (*j)++;
  }
  index--;
  for (int h = index; h >= 0; h--) {
    bit = s21_get_bit((unsigned int)buf_dec, h);
    if (bit != 0 || (*j) != 0) {
      buf[(*j)] = bit + 48;
      (*j)++;
    }
  }
  res[(*res_i)] = 49;
  (*res_i)++;
  (*flag_i) = 1;
}
void s21_refresh_value(s21_decimal *value, int res_i, char *res) {
  value->bits[0] = 0;
  value->bits[1] = 0;
  value->bits[2] = 0;
  int k = 0;
  int count_bit = 0;
  for (int i = 0; i < res_i; i++) {
    int bit = res[res_i - 1 - i] - 48;
    value->bits[k] |= (bit << count_bit);
    if (count_bit == 31) {
      count_bit = -1;
      k++;
    }
    count_bit++;
  }
}