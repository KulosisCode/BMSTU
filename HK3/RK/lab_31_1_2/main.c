#include "header.h"

int main(int argc, char **argv)
{   
    int **mtr = NULL;
    int rows, cols;
    if (argc != ARGS)
    {
        printf("ERROR ARGS!");
        return ERR_ARGS;
    }
    else
    {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
            printf("FILE NOT FOUND!");
            return ERR_EXIST;
        }
        else
        {
            int rc = 0;
            rc = read_file(file, mtr, &rows, &cols);
            fclose(file);
            if (rc != OK)
            {
                return rc;
            }
            else
            {
                if (rows == cols)
                    process(mtr, &rows, &cols);
                else
                {
                    printf("MATRIX NOT SQUARE.\n");
                }
                free_mtr(mtr, rows);
            }
        }
    }
    return OK;
}