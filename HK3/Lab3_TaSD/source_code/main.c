#include "header.h"

// viets them hamf check time
// chus y matrix_A.row owr ham sum 
int main(void)
{
    setbuf(stdout, NULL);
    matrix matrix_A, matrix_B, result;
    sparse_matrix sparse_A , sparse_B, sparse_result;
    matrix_A.matrix = NULL, matrix_B.matrix = NULL, result.matrix = NULL;
    sparse_A.num = NULL, sparse_B.num = NULL, sparse_result.num = NULL;
    int rows, cols, count;
    int command;

    conditions();
    int  run = 1;
    while (run)
    {
        menu();
        if (scanf("%d", &command) == 1 && command >= MIN_CHOICE && command <= MAX_CHOICE)
        {
            switch (command)
            {
                case 1:
                {
                    if (create_matrix(&matrix_A) == OK)
                    {
                        if (input_matrix_by_hand(&matrix_A, &sparse_A) == OK)
                        {
                            printf("\nMatrix A was created.\n");

                            sparse_convert(matrix_A, &sparse_A);
                        }
                        else
                            free_matrix(&matrix_A, matrix_A.rows);
                    }
                    break;
                }
                case 2:
                {
                    if (create_matrix(&matrix_B) == OK)
                    {
                        if (input_matrix_by_hand(&matrix_B, &sparse_B) == OK)
                        {
                            printf("\nMatrix B was created.\n");

                            sparse_convert(matrix_B, &sparse_B);
                        }
                        else
                            free_matrix(&matrix_B, matrix_B.rows);
                    }

                    break;
                }
                case 3:
                {
                    FILE *file = fopen("a.txt","r");
                    matrix_A.matrix =  file_input(&rows, &cols, &count, file);
                    if (matrix_A.matrix == NULL)
                        break;
                    matrix_A.rows = rows;
                    matrix_A.cols = cols;
                    sparse_A.non_zero = count;
                    fclose(file);
                    if (sparse_convert(matrix_A, &sparse_A) != OK)
                        printf("Failed to convert A.\n");
                    break;
                }
                case 4:
                {
                    FILE *file_2 = fopen("b.txt","r");
                    matrix_B.matrix =  file_input(&rows, &cols, &count, file_2);
                    matrix_B.rows = rows;
                    matrix_B.cols = cols;
                    sparse_B.non_zero = count;
                    fclose(file_2);
                    if (sparse_convert(matrix_B, &sparse_B) != OK)
                        printf("Failed to convert B.\n");
                    break;
                    
                }
                case 5:
                {
                    if (matrix_A.rows != matrix_B.rows || matrix_A.cols != matrix_B.cols)
                    {
                        printf("Wrong size of matrix!\n");
                        break;
                    }
                    else
                        classic_add(matrix_A, matrix_B, &result);
                    break;
                }
                case 6 :
                {
                    if (sparse_A.num == NULL || sparse_B.num == NULL || matrix_A.cols <= 0 ||  matrix_A.cols != matrix_B.cols)
                    {
                        printf("ERROR DATA!\n");
                        break;
                    }
                    else 
                    {
                        int result_count = 0;
                        if (count_result_non_zero(sparse_A, sparse_B, matrix_A.cols, &result_count) != OK)
                            break;
                        sparse_result.num = (int *)calloc(result_count, sizeof(int));
                        sparse_result.rows =  (int *)calloc(result_count, sizeof(int));
                        sparse_result.cols = (int *)calloc(matrix_A.cols, sizeof(int));
                        sparse_result.non_zero = result_count;

                        sparse_sum(sparse_A, sparse_B, &sparse_result, matrix_A.cols);
                    }
                    break;
                }
                case 7 :
                {
                    if (matrix_A.matrix != NULL)
                        print_matrix(matrix_A);
                    if (matrix_B.matrix != NULL)
                        print_matrix(matrix_B);
                    break;
                }
                case 8 :
                {
                    if (sparse_A.num != NULL)
                        print_sparse(sparse_A, matrix_A.cols);
                    if (sparse_B.num != NULL)
                        print_sparse(sparse_B, matrix_B.cols);
                    break;
                }
                case 9 :
                {
                    if (result.matrix != NULL)
                        print_matrix(result);
                    break;
                }
                case 10:
                {
                    if (sparse_result.num != NULL)
                        print_sparse(sparse_result, matrix_A.cols);
                    break;
                }
                case 11:
                {
                    test_time();
                    break;
                }
                case 0 :
                {
                    if (matrix_A.matrix != NULL)
                        free_matrix(&matrix_A, matrix_A.rows);
                    if (matrix_B.matrix != NULL)
                        free_matrix(&matrix_B, matrix_B.rows);
                    if (sparse_A.num != NULL)
                        free_sparse(&sparse_A);
                    if (sparse_B.num != NULL)
                        free_sparse(&sparse_B);
                    if (result.matrix != NULL)
                        free_matrix(&result, result.rows);
                    if (sparse_result.num != NULL)
                        free_sparse(&sparse_result);
                        
                    run = 0;
                    break;
                }
                default :
                    printf("ERROR COMMAND.\n");
            }
        }
        else
        {
            printf("ERROR COMMAND.\n");
            fgetc(stdin);
        }
        
    }
    return OK;
}