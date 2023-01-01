#include "header.h"


int create_matrix(matrix *mtr)
{
    int row, column;
    printf("\nEnter the number of rows of the matrix: ");
    
    if (scanf("%d", &row) == 1)
        mtr->rows = row;
    else
    {
        printf("\nThe number of rows of the matrix was entered incorrectly.\n");
        return ERR_ROWS;
    }

    if (row < MIN_SIZE || row > MAX_SIZE)
    {
        printf("\nThe number of rows of the matrix was entered incorrectly.\n");
        return ERR_ROWS;
    }

    printf("\nEnter the number of columns in the matrix: ");

    if (scanf("%d", &column) == 1)
        mtr->cols = column;
    else
    {
        printf("\nThe number of columns of the matrix was entered incorrectly.\n");
        return ERR_COLS;
    }

    if (column < MIN_SIZE || column > MAX_SIZE)
    {
        printf("\nThe number of columns of the matrix was entered incorrectly.\n");
        return ERR_COLS;
    }

    mtr->matrix = calloc(mtr->rows, sizeof(int*));

    if (!mtr->matrix)
    {
        printf("\nERROR ALLOCATE.\n");
        return ERR_ALLOCATE;
    }

    for (int i = 0; i < mtr->rows; i++)
    {
        mtr->matrix[i] = calloc(mtr->cols, sizeof(int));
    
        if (!mtr->matrix[i])
        {
            free_matrix(mtr, mtr->rows);
            return ERR_ALLOCATE;
        }
    }

    return OK;
}



int sparse_convert(matrix mtr, sparse_matrix *sparse)
{
    sparse->num = calloc(sparse->non_zero, sizeof(int));

    if (!sparse->num)
        return ERR_ALLOCATE;

    int k = 0;

    sparse->rows = calloc(sparse->non_zero, sizeof(int));

    if (!sparse->rows)
        return ERR_ALLOCATE;

    sparse->cols = calloc(mtr.cols, sizeof(int));

    if (!sparse->cols)
        return ERR_ALLOCATE;


    // điền element vào sparse
    for (int j = 0; j < mtr.cols; ++j)
    {
        for (int i = 0; i < mtr.rows; ++i)
        {
            if (*(*(mtr.matrix + i) + j) != 0)
            {
                *(sparse->num + k) = *(*(mtr.matrix + i) + j);
                *(sparse->rows + k) = i;
                k++;
            }
        }
    }

    int now_count = 0;

    for (int j = 0; j < mtr.cols; j++)
    {
        int column = 0;

        for (int i = 0; i < mtr.rows; i++)
        {
            if (*(*(mtr.matrix + i) + j) != 0)
            {
                now_count++;
                column++;
            }
        }

        *(sparse->cols + j) = now_count - column;
    }

    return OK;
}



int classic_add(matrix matrix_A, matrix matrix_B, matrix *result)
{
    if (!matrix_A.matrix)
    {
        {
            printf("\nMatrix A not exist.\n");
            return ERR_ALLOCATE;
        }
    }

    if (!matrix_B.matrix)
    {
        {
            printf("\nMatrix B not exist.\n");
            return ERR_ALLOCATE;
        }
    }

    result->rows = matrix_A.rows;
    result->cols = matrix_A.cols;

    result->matrix = malloc(result->rows * sizeof(int*));

    if (!result->matrix)
        return ERR_ALLOCATE;

    for (int i = 0; i < result->rows; i++)
    {
        result->matrix[i] = malloc(result->cols * sizeof(int));
    
        if (!result->matrix[i])
        {
            free_matrix(result, result->rows);
            return ERR_ALLOCATE;
        }
    }


    for (int i = 0; i < matrix_A.rows; i++)
        for (int j = 0; j < matrix_A.cols; j++)
            *(*(result->matrix + i) + j) = *(*(matrix_A.matrix + i) + j) + *(*(matrix_B.matrix + i) + j);

    return OK;
}


int count_result_non_zero(sparse_matrix sparse_a, sparse_matrix sparse_b, const int column, int *result_count)
{
    if (sparse_a.num == NULL || sparse_b.num == NULL || column <= 0)
    {
        printf("ERROR PARAMETER.\n");
        return ERR_PARAM;
    }
    for (int j = 0; j < column; ++j)
    {
        int *a_arr, *b_arr;
        int a_ind = 0, b_ind = 0;
        int cur_a, cur_b;

        if (j + 1 != column)
        {
            cur_a = *(sparse_a.cols + j + 1);
            cur_b = *(sparse_b.cols + j + 1);
        }
        else
        {
            cur_a = sparse_a.non_zero;
            cur_b = sparse_b.non_zero;
        }

        int a_column = cur_a - *(sparse_a.cols + j);
        int b_column = cur_b - *(sparse_b.cols + j);
        a_arr = (int *)calloc(a_column, sizeof(int));
        b_arr = (int *)calloc(b_column, sizeof(int));

        for (int a_col = *(sparse_a.cols + j); a_col < cur_a; a_col++)
        {
            *(a_arr + a_ind) = *(sparse_a.rows + a_col);
            a_ind++;
        }

        for (int b_col = *(sparse_b.cols + j); b_col < cur_b; b_col++)
        {
            *(b_arr + b_ind) = *(sparse_b.rows + b_col);
            b_ind++;
        }

        int matches = 0;

        for (int i = 0; i < a_column; ++i)
            for (int k = i; k < b_column; k++)
                if (*(a_arr + i) == *(b_arr + k))
                    matches++;

        *result_count += a_column + b_column - matches;

        free(a_arr);
        free(b_arr);
    }

    return OK;
}




int sparse_sum(sparse_matrix sparse_a, sparse_matrix sparse_b, sparse_matrix *result, const int column)
{
    if (!sparse_a.num || !sparse_b.num)
    {
        printf("\nERROR PARAMETER.\n");
        return ERR_DATA;
    }
    int cur_el = 0;
    int a_glob = 0;
    int b_glob = 0;

    for (int j = 0; j < column; j++)
    {
        int *a_arr = NULL, *b_arr = NULL;
        int cur_a, cur_b;

        if (j + 1 != column)
        {
            cur_a = *(sparse_a.cols + j + 1);
            cur_b = *(sparse_b.cols + j + 1);
        }
        else
        {
            cur_a = sparse_a.non_zero;
            cur_b = sparse_b.non_zero;
        }

        int a_column = cur_a - *(sparse_a.cols + j);
        int b_column = cur_b - *(sparse_b.cols + j);
        // check neue a_arr hoac b_arr == NULL
        if (a_column > 0)
            a_arr = calloc(a_column, sizeof(int));
        if (b_column > 0)
            b_arr = calloc(b_column, sizeof(int));

        int *t_a = a_arr;
        int *t_b = b_arr;

        for (int a_col = *(sparse_a.cols + j); a_col < cur_a; ++a_col)
        {
            *(a_arr) = *(sparse_a.rows + a_col);
            a_arr++;
        }

        for (int b_col = *(sparse_b.cols + j); b_col < cur_b; ++b_col)
        {
            *(b_arr) = *(sparse_b.rows + b_col);
            b_arr++;
        }
        a_arr = t_a;
        b_arr = t_b;

        int matches = 0;

        for (int i = 0; i < a_column; ++i)
            for (int j = i; j < b_column; ++j)
                if (*(a_arr + i) == *(b_arr + j))
                    matches++;

        int range = a_column + b_column - matches;

        int flag = 0;
        
        for (int i = 0; i < range; ++i)
        {
            
            
            if (a_arr != NULL && b_arr ==  NULL)
            {
                *(result->num + cur_el) = *(sparse_a.num + a_glob);
                *(result->rows + cur_el) = *(sparse_a.rows + a_glob);
                cur_el++;
                a_glob++;
                a_arr++;
            }
            else if (a_arr == NULL && b_arr != NULL)
            {
                *(result->num + cur_el) = *(sparse_b.num + b_glob);
                *(result->rows + cur_el) = *(sparse_b.rows + b_glob);
                cur_el++;
                b_glob++;
                b_arr++;
            }
            else if (a_column != 0 && b_column == 0)
            {
                *(result->num + cur_el) = *(sparse_a.num + a_glob);
                *(result->rows + cur_el) = *(sparse_a.rows + a_glob);
                cur_el++;
                a_glob++;
                a_arr++;
                a_column--;
            }
            else if (b_column != 0 && a_column == 0)
            {
                *(result->num + cur_el) = *(sparse_b.num + b_glob);
                *(result->rows + cur_el) = *(sparse_b.rows + b_glob);
                cur_el++;
                b_glob++;
                b_arr++;
                b_column--;
            }
            else if (*(a_arr) < *(b_arr))
            {
                *(result->num + cur_el) = *(sparse_a.num + a_glob);
                *(result->rows + cur_el) = *(sparse_a.rows + a_glob);
                cur_el++;
                a_glob++;
                a_arr++;
                a_column--;
            }

            else if (*(a_arr) > *(b_arr))
            {
                *(result->num + cur_el) = *(sparse_b.num + b_glob);
                *(result->rows + cur_el) = *(sparse_b.rows + b_glob);
                cur_el++;
                b_glob++;
                b_arr++;
                b_column--;
            }

            else if (*(a_arr) == *(b_arr))
            {
                *(result->num + cur_el) = *(sparse_a.num + a_glob) + *(sparse_b.num + b_glob);
                *(result->rows + cur_el) = *(sparse_a.rows + a_glob);
                cur_el++;
                a_glob++;
                b_glob++;
                a_arr++;
                a_column--;
                b_arr++;
                b_column--;
            }
            if (flag == 0)
            {
                *(result->cols + j) = cur_el - 1;
            }
            flag++;
        }
        if (t_a != NULL)
            free(t_a);
        if (t_b != NULL)
            free(t_b);
    }

    return OK;
}