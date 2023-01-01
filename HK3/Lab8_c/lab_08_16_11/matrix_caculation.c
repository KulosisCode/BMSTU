#include "io.h"

void matrix_addition(double **mtr1, double **mtr2, double **result, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            result[i][j] = mtr1[i][j] + mtr2[i][j];
}

void matrix_multi(double **mtr1, double **mtr2, double **result, int n, int m, int m2)
{
    double temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            temp = 0;
            for (int k = 0; k < m; k++)
            {
                temp += mtr1[i][k] * mtr2[k][j];
            }
            result[i][j] = temp;
        }
    }
}

double gauss_caculation(double **mtr, int n)
{
    double det = 1;
    int check_col;
    double flag;
    double mult = 1;

    for (int index = 0; index < n; index++)
    {
        check_col = -1;
        flag = 0;
        for (int i = index; i < n; i++)
            if ((fabs(mtr[i][index]) - fabs(flag)) > EPS)
            {
                check_col = i;
                flag = mtr[i][index];
            }
        if (check_col == -1)
            return 0;
        if (check_col != index)
        {
            double *temp = mtr[index];
            mtr[index] = mtr[check_col];
            mtr[check_col] = temp;
            det *= -1;
        }
        for (int j = index + 1; j < n; j++)
            if (fabs(mtr[j][index] - 0) > EPS)
            {
                mult = mtr[j][index] / mtr[index][index];

                for (int k = index; k < n; k++)
                    mtr[j][k] -= mtr[index][k] * mult;
            }

        det *= mtr[index][index];
    }
    return det;
}