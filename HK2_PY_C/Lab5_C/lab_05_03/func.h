#ifndef _FUNC_H_
#define _FUNC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define OK 0
#define ERR_FILE -1
#define ERR_INPUT -2
#define ERR_EXIST_FILE -3
#define ERR_NUMBER -5
#define ERR_WRITE -6
#define ERR_GET_SIZE -7
#define ERR_EMPTY_FILE -8
#define ERR_POS -9
#define ERR_GET_POS -10
#define ERR_PUT_POS -11

int is_number(char *str);
int write_to_file(FILE *file, char *number);
size_t check_size_file(FILE *file, int *err);
int read_from_file(FILE *file);
void err_mess(int err);
int get_amount(FILE *file, int *err);
int get_number_by_pos(FILE *file, const int pos, int *num, int *err);
int put_number_by_pos(FILE *file, const int pos, int num, int *err);
int sort_file(FILE*file);

#endif