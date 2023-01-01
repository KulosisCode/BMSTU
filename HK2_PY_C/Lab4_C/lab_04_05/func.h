#ifndef _func_h_
#define _func_h_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 257
#define NO_INPUT_DATA -1
#define NO_WORD -2
#define NOFILE -3
#define ERR_INPUT -4


int read(char str[STR_LEN]);
void del_begin(char str[STR_LEN]);
int check(char str[STR_LEN], char delims[10]);

#endif 
