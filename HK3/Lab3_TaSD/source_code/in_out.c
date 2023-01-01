#include "header.h"

void conditions(void)
{
    printf("%s",
           "\nProgram for adding matrix A and matrix B.\n"
           "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
           "Command entry order:\n\n"
           "Enter the command number from the menu k - integer\n"
           "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
           "The order of entering a matrix N by M elements manually:\n\n"
           "1. Enter the number of rows in the matrix N ([1, 1000]) - integer\n"
           "2. Enter the number of columns in the matrix M ([1, 1000]) - integer\n"
           "3. Enter the number of non-zero elements of the matrix ([1; 1000]) - integer\n"
           "4. Enter the elements of the matrix:\n"
           "    1) Enter the row of element n - integer\n"
           "    2) Enter a space\n"
           "    3) Enter the column of element m - integer\n"
           "    4) Enter a space\n"
           "    5)Enter element a - integer\n"
           "Input type:\n\n"    
           "n m a\n"
           "The dimensions of the matrices must match.\n");
}

void menu(void)
{
    printf("%s",
           "\nSelect menu number:\n"
           "1) Enter matrix A manually\n"
           "2) Enter matrix B manually\n"
           "3) Fill matrix A from file\n"
           "4) Fill matrix B from file\n"
           "5) Add matrices using the classical storage method\n"
           "6) Add matrices using sparse columnar storage\n"
           "7) Print original matrices in the classical form\n"
           "8) Print original matrices in sparse columnar form\n"
           "9) Print the resulting matrix in the classic form\n"
           "10) Print the resulting matrix in sparse columnar form\n"
           "11) Test result\n"
           "0) Exit\n\n"
           "Enter the command: ");
}

int input_matrix_by_hand(matrix *mtr, sparse_matrix *sparse)
{
    if (!mtr->matrix)
        return ERR_ALLOCATE;
    int count, row, column, element;

    printf("\nEnter the number of non-zero : ");
    
    if (scanf("%d", &count) != 1 || count > mtr->cols * mtr->rows)
    {
        printf("\nThe number of non-zero elements was entered incorrectly.\n");
        return ERROR_NON_ZERO;
    }
    else
        sparse->non_zero = count;
    
    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < count; i++)
    {
        if (scanf("%d %d %d", &row, &column, &element) != 3 || row < 0 || row >= mtr->rows || column < 0 || column >= mtr->cols)
        {
            printf("\nThe element was entered incorrectly.\n");
            return ERR_IO;
        }
        else
        {
            *(*(mtr->matrix + row) + column) = element;
        }
    }

    return OK;
}

int **file_input(int *rows,int *cols, int *count, FILE *file)
{
	int row, col, num;
	if (fscanf(file, "%d %d %d\n", rows, cols, count) == 3)
    {
        if (*rows < MIN_SIZE || *rows > MAX_SIZE || *cols < MIN_SIZE || *cols > MAX_SIZE || *count > (*cols) * (*rows) || *count < 0)
        {
            printf("ERROR INPUT!\n");
            return NULL;
        }
    }
    else
    {
        printf("ERROR INPUT!\n");
        return NULL;
    }
	int **mtr = (int**)calloc((*rows), sizeof(int*));
	if (mtr != NULL)
	{
		int i = 0;
		for (; i < *rows; i++)
		{
			mtr[i] = (int*)calloc((*cols), sizeof(int));
			if (mtr[i] == NULL)
			{
				free_matrix_only(mtr, *rows);
                printf("ERROR ALLOCATE.\n");
                return NULL;
			}
		}
	}
	for (int i = 0; i < *count; i++)
	{
		if (fscanf(file, "%d %d %d\n", &row, &col, &num) == 3)
        {
            if (row < (MIN_SIZE - 1) || row > (MAX_SIZE - 1) || col < (MIN_SIZE - 1) || col > (MAX_SIZE - 1))
            {
                free_matrix_only(mtr, *rows);
                printf("ERROR INPUT!\n");
                return NULL;
            }
            else
                mtr[row][col] = num;
        }
		else
        {
            printf("ERROR INPUT!\n");
            return NULL;
        }
	}
	return mtr;
}

int print_matrix(matrix mtr)
{
    if (!mtr.matrix)
    {
        printf("\nERROR PARAMETER.\n");
        return ERR_PARAM;
    }

    for (int i = 0; i < mtr.rows; i++)
    {
        for (int j = 0; j < mtr.cols; j++)
            printf("%3d ", *(*(mtr.matrix + i) + j));
        printf("\n");
    }
    printf("\n");
    return OK;
}


int print_sparse(sparse_matrix matrix, const int count)
{
    if (!matrix.cols || !matrix.num || !matrix.rows)
    {
        printf("\nERROR PARAMETER.\n");        
        return ERR_PARAM;
    }

    printf("\nArray with nonzero elements\n");
    for (int i = 0; i < matrix.non_zero; i++)
        printf("%5d ", *(matrix.num + i));
    
    printf("\n");

    printf("\nArray with row numbers\n");
    for (int i = 0; i < matrix.non_zero; i++)
        printf("%5d ", *(matrix.rows + i) + 1);

    printf("\n");

    printf("\nArray with the connected numbers of elements of first vector (which the column begins)\n");
    for (int i = 0; i < count; i++)
        printf("%5d ", *(matrix.cols + i) + 1);

    printf("\n\n");

    return OK;
}