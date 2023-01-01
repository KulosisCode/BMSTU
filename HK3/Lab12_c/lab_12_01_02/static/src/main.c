#include "constan.h"
#include "io.h"
#include "sort.h"
#include "key.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int *arr = NULL;
    int *dst = NULL;
    int filter = 0;

    if (argc == 3)
        filter = 0;
    else if (argc == 4 && (strcmp(argv[3], "f") == 0))
        filter = 1;
    else
    {
        printf("ERROR ARGS!");
        return ERR_ARGS;
    }

    FILE *file = NULL;
    file = fopen(argv[1], "r");
    if (file != NULL)
    {
        size_t count = 0;
        int len_dst = 0;
        int n = read_file(file, &count);
        if (n == ERR_READ_FILE)
        {
            printf("ERROR READING!");
            return ERR_READ_FILE;
        }
        else if (n == ERR_EMPTY)
        {
            printf("ERROR ERR_EMPTY!");
            return ERR_EMPTY;
        }

        arr = malloc(count * sizeof(int));
        if (!arr)
        {
            printf("ERROR MEMORY!");
            return MEMORY_ERR;
        }
        write_to_array(file, arr);
        if (fclose(file) != OK)
        {
            printf("ERROR CLOSE FILE!");
            free(arr);
            return ERR_CLOSE;
        }

        FILE *fileout = NULL;
        fileout = fopen(argv[2], "w");
        if (fileout == NULL)
        {
            printf("ERROR OPEN FILE!");
            free(arr);
            return ERR_OPEN_FILE;
        }
        
        if (filter)
        {
            n = key(arr, count, &dst, &len_dst);
            if (n != OK)
            {
                printf("ERROR FILLTER FUNCTION!");
                free(arr);
                free_copy_arr(&dst);
                return n;
            }
            else
            {
                dst = malloc (len_dst * sizeof(int));
                key(arr, count, &dst, &len_dst);
                if (mysort(dst, len_dst, sizeof(int), compare) != OK)
                    return ERR_INVALID_PARAM;
                write_to_file(dst, len_dst, fileout); 
            }
        }
        else
        {
            if (mysort(arr, count, sizeof(int), compare) != OK)
                return ERR_INVALID_PARAM;
            write_to_file(arr, count, fileout);
        }

        free(arr);
        free_copy_arr(&dst);
        if (fclose(fileout) != OK)
        {
            printf("ERROR CLOSE FILE!");
            return ERR_CLOSE;
        }
    }
    else
    {
        printf("ERROR NO FILE!");
        return ERR_OPEN_FILE;
    }
    

    return OK;
}