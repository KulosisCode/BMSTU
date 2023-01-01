#ifndef _INTERNATIONAL_TEEN48_H_
#define _INTERNATIONAL_TEEN48_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SEARCH_PER_MOVE 100
#define SEARCH_LEN 4
#define NUMBER_OF_MOVE 4
#define MAX_SIZE 10

typedef struct
{
    int rows;
    int columns;
    int **matrix;
} matrix_t;

void create_matrix(int **a, int *buf, int n);
bool push_board_right(matrix_t board);
bool merge_elements(matrix_t board, int *score);
void reverse(matrix_t board);
void transpose(matrix_t board);
bool move_up(matrix_t board, int *score);
bool move_down(matrix_t board, int *score);
bool move_right(matrix_t board, int *score);
bool move_left(matrix_t board, int *score);
bool random_move(matrix_t board, int *score);
void add_new_tile(matrix_t board);
char teen48game(matrix_t matrix);
#endif