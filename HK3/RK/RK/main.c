#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "matrix.h"
#include "input.h"
#include "error.h"

int main(int argc, char** argv)
{
    
    
    int** matrix = NULL;
    int row, col;
    int rc;
    if (argc != ARGS)
    {
        show_error(ARG_ERROR);
        return ARG_ERROR;
    }
    else
    {
        FILE* f = fopen(argv[1], "r");
        if (f == NULL)
        {
            show_error(FILE_OPEN_ERROR);
            return FILE_OPEN_ERROR;
        }
        if ((rc = input_matrix(&matrix, &row, &col, f)) != EXIT_SUCCESS)
            return show_error(rc);
        
        int max_elem;
        if ((rc = find_max_end_5(matrix, row, &max_elem)) != TRUE)
        {
            free_matrix(matrix, row);
            return show_error(NO_ELEMENT_FOUND);
        }
        else
            printf("Max element end with 5: %d", max_elem);
        free_matrix(matrix, row);
    }

    return EXIT_SUCCESS;
}