#include "../inc/constan.h"
#include "../inc/io.h"
#include "../inc/sort.h"
#include "../inc/key.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int *arr = NULL;
    int *pb_dst = NULL, *pe_dst = NULL;
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
    if (file == NULL)
    {
        printf("ERROR NO FILE!");
        return ERR_OPEN_FILE;
    }
    
    size_t count = 0;
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
        n = key(arr, arr + count, &pb_dst, &pe_dst);
        if (n != OK)
        {
            printf("ERROR FILLTER FUNCTION!");
            free(arr);
            free_copy_arr(&pb_dst, &pe_dst);
            return n;
        }
        else
        {
            if (mysort(pb_dst, (size_t)(pe_dst - pb_dst), sizeof(int), compare) != OK)
                return ERR_INVALID_PARAM;
            write_to_file(pb_dst, pe_dst, fileout); 
        }
    }
    else
    {
        if (mysort(arr, count, sizeof(int), compare) != OK)
            return ERR_INVALID_PARAM;
        write_to_file(arr, arr + count, fileout);
    }

    free(arr);
    if (fclose(fileout) != OK)
    {
        printf("ERROR CLOSE FILE!");
        free(arr);
        free_copy_arr(&pb_dst, &pe_dst);
        return ERR_CLOSE;
    }

    free_copy_arr(&pb_dst, &pe_dst);

    return OK;
}