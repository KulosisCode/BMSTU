#include "header.h"
#include <time.h>
#include <inttypes.h>
#include <sys/time.h>

void random_matrix(matrix *mtr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        int ir= 0;
        int jr = 0;

        while (*(*(mtr->matrix + ir) + jr) != 0)
        {
            ir = rand() % mtr->rows;
            jr = rand() % mtr->cols;
        }

        *(*(mtr->matrix + ir) + jr) = rand() % 100 + 1;
    }
}

int create(matrix *mtr, int const size)
{
    mtr->rows = size;
    mtr->cols = size;
    mtr->matrix = calloc(size, sizeof(int*));
    if (!mtr->matrix)
        return ERR_ALLOCATE;
    for (int i = 0; i < size; i++)
    {
        mtr->matrix[i] = calloc(mtr->cols, sizeof(int));
        if (!mtr->matrix[i])
        {
            free_matrix(mtr, size);
            return ERR_ALLOCATE;
        }
    }
    return OK;
}
void test_time()
{
    matrix A, B, result;
    sparse_matrix S_A, S_B, S_result;
    A.matrix = NULL, B.matrix = NULL, result.matrix = NULL;
    S_A.num = NULL, S_B.num = NULL, S_result.num = NULL;

    struct timeval tv_start, tv_stop;
    int64_t s_1 = 0, s_2 = 0, mem_1 = 0, mem_2 = 0;
    srand((int)time(0));

    int size;
    printf("Enter size matrix: ");
    if (scanf("%d", &size) == 1 && size > MIN_SIZE && size <= MAX_SIZE)
    {
        int non_zeros = 0;
        printf("Enter number of non_zero: ");
        if (scanf("%d", &non_zeros) == 1 && non_zeros > 0 && non_zeros <= size * size)
        {

            if (create(&A, size) == OK && create(&B, size) == OK)
            {
                random_matrix(&A, non_zeros);
                random_matrix(&B, non_zeros);
                S_A.non_zero = non_zeros;
                S_B.non_zero = non_zeros;
                if (sparse_convert(A, &S_A) == OK && sparse_convert(B, &S_B) == OK)
                {
                    if (A.rows != B.rows || A.cols != B.cols)
                        return;
                    gettimeofday(&tv_start, NULL);
                    classic_add(A, B, &result);
                    gettimeofday(&tv_stop, NULL);
                    s_1 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                            (tv_stop.tv_usec - tv_start.tv_usec);

                    int result_count = 0;
                    count_result_non_zero(S_A, S_B, size, &result_count);
                    S_result.num = (int *)malloc(result_count * sizeof(int));
                    S_result.rows =  (int *)malloc(result_count * sizeof(int));
                    S_result.cols = (int *)malloc(size * sizeof(int));
                    S_result.non_zero = result_count;


                    gettimeofday(&tv_start, NULL);
                    sparse_sum(S_A, S_B, &S_result, size);
                    gettimeofday(&tv_stop, NULL);
                    s_2 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                            (tv_stop.tv_usec - tv_start.tv_usec);
                    
                    printf("Adding time classic : %10ld\n", s_1);
                    printf("Adding time sparse: %10ld\n", s_2);
                    mem_1 = sizeof(int **) + sizeof(int *) * result.rows +
                            sizeof(int) * result.rows * result.cols + 2 *sizeof(int);
                    mem_2 = sizeof(int *) *3 + sizeof(int) * S_result.non_zero * 2 +
                            sizeof(int) * result_count + sizeof(int);
                    printf("Adding classic memory: %10ld\n", mem_1);
                    printf("Adding sparse memory: %10ld\n", mem_2);
                    free_matrix(&A, A.rows);
                    free_matrix(&B, B.rows);
                    free_sparse(&S_A);
                    free_sparse(&S_B);
                    free_matrix(&result, result.rows);
                    free_sparse(&S_result);
                }
                else
                {
                    printf("Convert matrix failed.\n");
                }
            }
            else 
            {
                printf("Create matrix failed.\n");
            }
        }
        else
            printf("Input non_zero error.\n");
    }
    else
    {
        printf("Wrong input size!\n");
    }
}