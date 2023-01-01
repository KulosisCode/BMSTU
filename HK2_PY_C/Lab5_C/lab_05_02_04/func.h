#ifndef _FUNC_H_
#define _FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERR_INPUT -1
#define ERR_DATA -2
#define FILE_NOT_EXIST -3
#define ERR_FILE -4

int find_min_max(FILE *file, int  *pos_1, int *pos_2);
int process(FILE *file, float *avg);

#endif