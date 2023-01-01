#ifndef _IO_H_
#define _IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPS 1e-7
#define OK 0

#define ERR_EMPTY -1
#define ERR_ARGS -2
#define ERR_ALLOCATE -3
#define ERR_OPEN -4
#define ERR_DATA -5
#define ERR_READ -6
#define ERR_SIZE -7

double **allocate_matrix(int n, int m);
void free_matrix(double **matrix, int n);

int read_from_file(char *filename, double ***mtr, int *n, int *m);
void write_to_file(FILE *file, int n, int m, double **mtr);

void matrix_addition(double **mtr1, double **mtr2, double **result, int n, int m);
void matrix_multi(double **mtr1, double **mtr2, double **result, int n, int m, int m2);
double gauss_caculation(double **mtr, int n);
#endif