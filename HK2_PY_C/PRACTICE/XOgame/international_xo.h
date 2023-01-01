#ifndef _INTERNATIONAL_XO_H_
#define _INTERNATIONAL_XO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5
#define VOID 3
#define TIE 0
#define X 1
#define O -1
#define MUTIPLE_WAY 2
typedef struct
{
    int x;
    int y;
    int sc;
} score_t;

int xogame(char **bf, const int field_size, const char symb);
int check_winner(int board[MAX_SIZE][MAX_SIZE], const int field_size);
int next_turn(int turn);
int score(int board[MAX_SIZE][MAX_SIZE], int player, const int field_size, int count);
void copy_board(int board[MAX_SIZE][MAX_SIZE], int sub[MAX_SIZE][MAX_SIZE],const int field_size);
score_t find_best_turn(int board[MAX_SIZE][MAX_SIZE], int player,const int field_size, int count);
bool test_for_move(int board[MAX_SIZE][MAX_SIZE], int player, const int field_size, int x, int y);
score_t get_best_move(int board[MAX_SIZE][MAX_SIZE], int player, const int field_size);


#endif