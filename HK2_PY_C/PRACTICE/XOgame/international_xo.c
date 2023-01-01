#include "international_xo.h"

int xogame(char **bf, const int field_size, const char symb)
{
    int player;
    if (symb == 'X')
        player = X;
    else player = O;
    int board[MAX_SIZE][MAX_SIZE] = {0};
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
            {
                if (bf[i][j] == 'X')
                    board[i][j] = X;
                else if (bf[i][j] == 'O')
                    board[i][j] = O;
                else
                    board[i][j] = VOID;
            }
    score_t best;
    if (field_size < MAX_SIZE)
        best = find_best_turn(board, player, field_size, 0);
    else
        best = get_best_move(board, player, field_size);
    int move = best.x * field_size + best.y;
    return move;
}

int check_winner(int board[MAX_SIZE][MAX_SIZE], const int field_size)
{
    bool check = true;
    //ROWS
    for (int j = 0; j < field_size; j++)
    {
        check = true;
        for (int i =  1; i < field_size; i++)
            if (board[i][j] == VOID || board[i][j] != board[i - 1][j])
            {
                check = false;
                break;
            }
                
        if (check)
            return board[0][j];
    }
    //COLUMNS
    for (int i = 0; i < field_size; i++)
    {
        check = true;
        for (int j = 1; j < field_size; j++)
            if (board[i][j] == VOID || board[i][j] != board[i][j - 1])
            {
                check = false;
                break;
            }    
        if (check)
            return board[i][0];
    }
    //diagonals
    check = true;
    for (int i = 1; i < field_size; i++)
        if ((board[i][i] == VOID || board[i][i] != board[i - 1][i - 1]))
        {
            check = false;
            break;
        }    
    if (check)
        return board[0][0];
    check = true;
    int x = field_size - 1;
    for (int i = 1; i < field_size; i++)
        if ((board[i][x - i] == VOID || board[i][x - i] != board[i - 1][x - i + 1]))
        {
            check = false;
            break;
        }        
    if (check)
        return board[0][x];
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
            if (board[i][j] == VOID)
                return VOID;
    return TIE; // game draw
}

int next_turn(int turn)
{
    if (turn == O)
        return X;
    else 
        return O;
}

int score(int board[MAX_SIZE][MAX_SIZE], int player, const int field_size, int count)
{
    int winner = check_winner(board, field_size);
    if (winner  != VOID)
        return winner;
    score_t next = find_best_turn(board, next_turn(player), field_size, count + 1);
    return next.sc;
}

void copy_board(int board[MAX_SIZE][MAX_SIZE], int sub[MAX_SIZE][MAX_SIZE],const int field_size)
{
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
            sub[i][j] = board[i][j];
}

// func to find the best move(in case 3 * 3)
score_t find_best_turn(int board[MAX_SIZE][MAX_SIZE], int player, const int field_size, int count)
{
    int sub[MAX_SIZE][MAX_SIZE];
    copy_board(board, sub, field_size);
    bool max = (player == X);
    score_t best;
    score_t curr;
    best.x = -1;
    best.y = -1;
    best.sc = 2;
    if (max)
        best.sc = -2;
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
        {
            if (sub[i][j] == VOID)
            {
                sub[i][j] = player;
                curr.x = i;
                curr.y = j;
                curr.sc = score(sub, player, field_size, count);
                if (max)
                {
                    if (curr.sc > best.sc)
                        best = curr;
                }
                else
                {
                    if (curr.sc < best.sc)
                        best = curr;
                }
                sub[i][j] = VOID;
            }
        }
    return best;    
}

// func just for check that can make multiple win opportunities(in case 5*5)
bool test_for_move(int board[MAX_SIZE][MAX_SIZE], int player, const int field_size, int x, int y)
{
    int sub[MAX_SIZE][MAX_SIZE];
    copy_board(board, sub, field_size);
    sub[x][y] = player;
    int winning_moves = 0;
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
        {
            if (sub[i][j] == VOID)
            {
                sub[i][j] = player;
                if (check_winner(sub, field_size) == player)
                    winning_moves++;
                sub[i][j] = VOID;
            }
        }
    return (winning_moves >= MUTIPLE_WAY);    
}
// func just for tic tac toe 5 * 5
score_t get_best_move(int board[MAX_SIZE][MAX_SIZE], int player, const int field_size)
{
    int sub[MAX_SIZE][MAX_SIZE];
    copy_board(board, sub, field_size);
    score_t best;
    best.x = -1;
    best.y = -1;
    best.sc = 0;
    int anti;
    if (player == X)
        anti = O;
    else
        anti = X;
    // Check if the player can make a move that leads to a direct win
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
            if (sub[i][j] == VOID)
            {
                sub[i][j] = player;
                if (check_winner(sub, field_size) == player)
                {
                    best.x = i;
                    best.y = j;
                    return best;
                }
                sub[i][j] = VOID;
            }
    // Check if the computer can make a move that leads to a direct win
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
            if (sub[i][j] == VOID)
            {
                sub[i][j] = anti;
                if (check_winner(sub, field_size) == anti)
                {
                    best.x = i;
                    best.y = j;
                    return best;
                }
                sub[i][j] = VOID;
            }
    // Check if the player can make multiple win opportunities
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
            if (sub[i][j] == VOID)
            {
                sub[i][j] = player;
                if (test_for_move(sub, player, field_size, i, j))
                {
                    best.x = i;
                    best.y = j;
                    return best;
                }
                sub[i][j] = VOID;
            }
    // Check if the computer can make multiple win opportunities
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
            if (sub[i][j] == VOID)
            {
                sub[i][j] = anti;
                if (test_for_move(sub, anti, field_size, i, j))
                {
                    best.x = i;
                    best.y = j;
                    return best;
                }
                sub[i][j] = VOID;
            }
    //play in a corner
    int step = field_size - 1;
    for (int i = 0; i < field_size; i += step)
        for (int j = 0; j < field_size; j += step)
            if (sub[i][j] == VOID)
            {
                best.x = i;
                best.y = j;
                return best;
            }
    // Play one of the centers of the board
    for (int i = 1; i < field_size - 1; i++)
        for (int j = 1; j < field_size - 1; j++)
            if (sub[i][j] == VOID)
            {
                best.x = i;
                best.y = j;
                return best;
            }
    for (int i = 0; i < field_size; i++)
        for (int j = 0; j < field_size; j++)
            if (sub[i][j] == VOID)
            {
                best.x = i;
                best.y = j;
                return best;
            }
    return best;
}           