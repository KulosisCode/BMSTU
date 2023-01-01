#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGS 2 

#define OK 0
#define ERR_IO -1
#define ERR_READ -2
#define ERR_DATA -3
#define ERR_ALLOCATE -4
#define ERR_PARAM -5
#define ERR_ARGS -6
#define ERR_EXIST -7

int read_file(FILE *file, int **mtr, int *a, int *b);
int process(int **mtr, int const *rows, int const *cols);
void free_mtr(int **mtr, int row);

#endif