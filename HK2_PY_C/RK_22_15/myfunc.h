#ifndef _MYFUNC_H
#define _MYFUNC_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define OK 0
#define NO_INPUT_DATA -1
#define ERR_UPPER -2
#define ERR_LETTER -3
#define ERR_NOFILE -4

int count_vowel_consonant(FILE *f, int *nguyen_am, int *phu_am);
void print_file(FILE* f);
void print_new_file(FILE* f);


#endif
