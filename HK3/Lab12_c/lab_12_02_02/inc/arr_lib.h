#ifndef _ARR_LIB_H_
#define _ARR_LIB_H_

#include <stdio.h>
#include <math.h>

int is_repeat(int *array, int index);

void fibonacci_fill(int size, int *array);

void get_first_meet(int *src, int size_src, int *dst, int *dst_len);

#endif