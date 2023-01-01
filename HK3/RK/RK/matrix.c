#include "matrix.h"
#include "define.h"

int find_max_end_5(int** matrix, int row_col, int* result)
{
	int max = DEFAULT_VALUE;
	int is_exist = FALSE;
	for (int i = 0; i < row_col; i++)
	{
		for (int j = 0; j < row_col; j++)
		{
			if (i + j > row_col - 1 && matrix[i][j] % 10 == 5)
			{
				is_exist = TRUE;
				if (max == DEFAULT_VALUE)
					max = matrix[i][j];
				else
					max = (matrix[i][j] > max) ? matrix[i][j] : max;
			}
		}
	}
	if (is_exist) *result = max;
	return is_exist;
}