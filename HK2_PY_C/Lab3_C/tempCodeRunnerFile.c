
                cnt++;
            }
}

int main(void)
{
    int array[ROW_MAX][COLUMN_MAX], m, n;
    int rc = matrix_input(array, &m, &n);
    int ar[ROW_MAX * COLUMN_MAX], cnt;
    if (rc == OK)
    {