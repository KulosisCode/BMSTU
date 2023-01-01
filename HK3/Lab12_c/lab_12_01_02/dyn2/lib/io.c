#include "io.h"
// #include "constan.h"

IO_DLL int IO_DECL read_file(FILE *file, size_t *count)
{
    int x;
    int rc = 0;
    while (!feof(file))
    {
        if ((rc = fscanf(file, "%d", &x)) == 1)
            (*count)++;
        else if (rc != 1 && rc != EOF)
            return ERR_READ_FILE;
    }
    if (*count == 0)
        return ERR_EMPTY;
    rewind(file);
    return OK;
}

IO_DLL void IO_DECL write_to_array(FILE *file, int *arr)
{
    int x, rc;
    while ((rc = fscanf(file, "%d", &x)) == 1)
    {
        *arr = x;
        arr++; 
    }
}

IO_DLL void IO_DECL write_to_file(int *p_e, int len, FILE *f_out)
{
    int *p = p_e;
    while (len)
    {
        fprintf(f_out, "%d ", *p);
        p++;
        len--;
    }
}