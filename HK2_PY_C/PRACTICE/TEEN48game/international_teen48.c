#include "international_teen48.h"

char teen48game(matrix_t matrix)
{
    matrix_t board;
    board.rows = matrix.rows;
    board.columns = matrix.columns;
    int *a[MAX_SIZE];
    int mtr[MAX_SIZE][MAX_SIZE] = {0};
    create_matrix(a, *mtr, MAX_SIZE);
    board.matrix = a;
    char possible_first_move[4] = {'u', 'r', 'l', 'd'};
    int first_move_score[NUMBER_OF_MOVE] = {0, 0, 0, 0};
    for (int index = 0; index < NUMBER_OF_MOVE; index++)
    {
        char first_move = possible_first_move[index];
        bool first_move_made = false;
        int score = 0;
        // make a copy of matrix name board
        for (int row = 0; row < board.rows; row++)
            for (int col = 0; col < board.columns; col++)
                board.matrix[row][col] = matrix.matrix[row][col];
        if (first_move == 'u')
            first_move_made = move_up(board, &score);
        else if (first_move == 'r')
            first_move_made = move_right(board, &score);
        else if (first_move == 'l')
            first_move_made = move_left(board, &score);
        else
            first_move_made = move_down(board, &score);
        if (first_move_made)
            first_move_score[index] += score;
        else 
            continue;
        for(int k = 0; k < SEARCH_PER_MOVE; k++)
        {
            int move_number = 1;
            matrix_t search_board;
            search_board.rows = matrix.rows;
            search_board.columns = matrix.columns;
            int *b[MAX_SIZE];
            int mtr1[MAX_SIZE][MAX_SIZE] = {0};
            create_matrix(b, *mtr1, MAX_SIZE);
            search_board.matrix = b;
            // make a copy of board name search board
            for (int row = 0; row < search_board.rows; row++)
                for (int col = 0; col < search_board.columns; col++)
                    search_board.matrix[row][col] = board.matrix[row][col];
            bool game_valid = true;
            while (game_valid && move_number < SEARCH_LEN)
            {
                int turn_score = 0; 
                game_valid = random_move(search_board, &turn_score);
                if (game_valid)
                {
                    add_new_tile(search_board);
                    first_move_score[index] += turn_score;
                    move_number++;
                }
            }
        }
    }
    int best_move_index = 0;
    for (int i = 0; i < NUMBER_OF_MOVE; i++)
    {
        if (first_move_score[best_move_index] < first_move_score[i])
            best_move_index = i;
    }
    int score = 0;
    char swipe = possible_first_move[best_move_index];
    if (swipe == 'u')
            move_up(matrix, &score);
        else if (swipe == 'r')
            move_right(matrix, &score);
        else if (swipe == 'l')
            move_left(matrix, &score);
        else
            move_down(matrix, &score);
    return swipe;
}

void create_matrix(int **a, int *matrix, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = matrix + n * i;
}

bool push_board_right(matrix_t board)
{
    matrix_t new;
    new.rows = board.rows;
    new.columns = board.columns;
    int *a[MAX_SIZE];
    int mtr[MAX_SIZE][MAX_SIZE] = {0};
    create_matrix(a, *mtr, MAX_SIZE);
    new.matrix = a;
    bool done = false;
    for (int row = 0; row < new.rows; row++)
    {
        int count = new.rows - 1;
        for (int col = new.columns - 1; col > - 1; col--)
        {
            if (board.matrix[row][col] != 0)
            {
                new.matrix[row][count] = board.matrix[row][col];
                if (col != count)
                    done = true;
                count -= 1;
            }
        }
    }
    for (int i = 0; i < new.rows; i++)
        for (int j = 0; j < new.columns; j++)
            board.matrix[i][j] = new.matrix[i][j];
    return done;
}

bool merge_elements(matrix_t board, int *score)
{
    bool done = false;
    for (int row = 0; row < board.rows; row++)
        for (int col = board.columns - 1; col > 0; col--)
            if ((board.matrix[row][col] == board.matrix[row][col - 1]) && (board.matrix[row][col] != 0))
            {
                board.matrix[row][col] *= 2;
                *score += board.matrix[row][col];
                board.matrix[row][col - 1] = 0;
                done  = true;
            }
    return done;
}

void reverse(matrix_t board)
{
    matrix_t new;
    new.rows = board.rows;
    new.columns = board.columns;
    int *a[MAX_SIZE];
    int mtr[MAX_SIZE][MAX_SIZE] = {0};
    create_matrix(a, *mtr, MAX_SIZE);
    new.matrix = a;
    for (int i = 0; i < new.rows; i++)
        for (int j = 0; j < new.columns; j++)
            new.matrix[i][j] = board.matrix[i][new.columns - j - 1];
    for (int i = 0; i < new.rows; i++)
        for (int j = 0; j < new.columns; j++)
            board.matrix[i][j] = new.matrix[i][j];
}

void transpose(matrix_t board)
{
    matrix_t new;
    new.rows = board.rows;
    new.columns = board.columns;
    int *a[MAX_SIZE];
    int mtr[MAX_SIZE][MAX_SIZE] = {0};
    create_matrix(a, *mtr, MAX_SIZE);
    new.matrix = a;
    for (int i = 0; i < new.rows; i++)
        for (int j = 0; j < new.columns; j++)
            new.matrix[i][j] = board.matrix[j][i];
    for (int i = 0; i < new.rows; i++)
        for (int j = 0; j < new.columns; j++)
            board.matrix[i][j] = new.matrix[i][j];
}

bool move_up(matrix_t board, int *score)
{
    transpose(board);
    reverse(board);
    bool has_pushed = push_board_right(board);
    bool has_merge = merge_elements(board, score);
    push_board_right(board);
    reverse(board);
    transpose(board);
    bool move_made = has_merge || has_pushed;
    return move_made;
}

bool move_down(matrix_t board, int *score)
{
    transpose(board);
    bool has_pushed = push_board_right(board);
    bool has_merge = merge_elements(board, score);
    push_board_right(board);
    transpose(board);
    bool move_made = has_merge || has_pushed;
    return move_made;
}

bool move_right(matrix_t board, int *score)
{
    bool has_pushed = push_board_right(board);
    bool has_merge = merge_elements(board, score);
    push_board_right(board);
    bool move_made = has_merge || has_pushed;
    return move_made;
}

bool move_left(matrix_t board, int *score)
{
    reverse(board);
    bool has_pushed = push_board_right(board);
    bool has_merge = merge_elements(board, score);
    push_board_right(board);
    reverse(board);
    bool move_made = has_merge || has_pushed;
    return move_made;
}

bool random_move(matrix_t board, int *score)
{
    bool move_made = false;
    char move_order[4] = {'u', 'r', 'l', 'd'};
    int len = 4;
    //srand(time(NULL));
    while (!move_made && len > 0)
    {
        int move_index = rand() % len;
        char move = move_order[move_index];
        bool move_made = false;
        if (move == 'u')
            move_made = move_up(board, score);
        else if (move == 'r')
            move_made = move_right(board, score);
        else if (move == 'l')
            move_made = move_left(board, score);
        else
            move_made = move_down(board, score);
        if (move_made)
            return true;
        for (int i = move_index + 1; i < len; i++)
        {
            move_order[i - 1] = move_order[i];
        }
        len--;
    }
    return false;
}

void add_new_tile(matrix_t board)
{
    //srand(time(NULL));
    int new_tile[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 4};
    int tile_value = new_tile[rand() % 10];
    int position[1000];
    int pos = 0;
    for (int row = 0; row < board.rows; row++)
        for (int col = 0; col < board.columns; col++)
            if (board.matrix[row][col] == 0)
            {
                position[pos++] = row;
                position[pos++] = col; 
            }
    if (pos != 0)
    {
        int r_pos = rand() % pos;
        int a, b;
        if (r_pos % 2 == 0)
        {
            a = position[r_pos];
            b = position[pos + 1];    
        }   
        else
        {
            a = position[r_pos - 1];
            b = position[r_pos];
        }  
        board.matrix[a][b] = tile_value;
    }
}