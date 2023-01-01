#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_SIZE 1
#define MAX_SIZE 1000
#define MIN_CHOICE 0
#define MAX_CHOICE 11
#define OK 0
#define ERR_IO -1
#define ERR_READ -2
#define ERR_DATA -3
#define ERR_ALLOCATE -4
#define ERROR_NON_ZERO -5
#define ERR_ROWS -5
#define ERR_COLS -6
#define ERR_PARAM -7

typedef struct
{
    int **matrix;
    int rows;
    int cols;
} matrix;

typedef struct
{
    int *num;
    int *rows;
    int *cols;
    int non_zero;
} sparse_matrix;

void conditions(void);
void menu(void);

void free_matrix(matrix *mtr, int n);
void free_sparse(sparse_matrix *mtr);
void free_matrix_only(int **matrix, int n);

int create_matrix(matrix *mtr);
int input_matrix_by_hand(matrix *mtr, sparse_matrix *sparse);
int print_matrix(matrix mtr);
int print_sparse(sparse_matrix matrix, const int count);

int **file_input(int *rows,int *cols, int *count, FILE *file);
void random_matrix(matrix *mtr, const int size);

int sparse_convert(matrix mtr, sparse_matrix *sparse);

int classic_add(matrix matrix_A, matrix matrix_B, matrix *result);


int count_result_non_zero(sparse_matrix sparse_a, sparse_matrix sparse_b, const int column, int *result_count);
int sparse_sum(sparse_matrix sparse_a, sparse_matrix sparse_b, sparse_matrix *result, const int column);

int create(matrix *mtr, int const size);
void test_time();


#endif