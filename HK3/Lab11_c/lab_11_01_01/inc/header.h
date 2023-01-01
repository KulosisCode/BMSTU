#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <stdarg.h>

#define OK 0
#define FAIL 1
#define FORMAT_S 1
#define FORMAT_HX 2
#define NONE 0
#define END '\0'

#define ERR -1

int my_snprintf(char *restrict s, int n, const char *restrict format, ...);
int my_strlen(const char *s);
int my_strcmp(char *s1, char *s2);
int get_type_format(const char *s, int ind);
void write_c_type(char *buff, int *buff_count, char c, int *remain, int *able_all);
void write_s_type(char *buff, int *buff_count, char *s, int *remain, int *able_all);
void write_x_type(char *buff, int *buff_count, int x, int *remain, int *able_all);
char digit_to_char(int num);
char *from_int_to_16(uint16_t num, int *len);
int get_length(int num, int base);
#endif 