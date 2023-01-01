#ifndef  _MYFUNC_H
#define _MYFUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 100
#define LENGTH 15
#define OK 0
#define TRUE 1
#define FALSE 0
#define NO_INPUT_FILE -1
#define NO_INPUT_DATA -2
#define OUT_OF_LENGTH -3
#define NO_VALID_WORD -4
#define TWO_WORDS_IN_A_LINE -5
#define NOT_ENOUGH_ARG -6
#define OO 1000


int get_data_from_file_text(FILE* f, int* count, char arr[N][LENGTH + 1]);
int first_equal_last(char word[LENGTH + 1]);

#endif
