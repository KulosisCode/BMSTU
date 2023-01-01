#include "constan.h"
#include "io.h"
#include "sort.h"
#include "key.h"
#include <windows.h>

typedef int (__cdecl *fn_mysort_t)(void *, size_t, size_t, int(*compare)(const void*, const void*));

typedef int (__cdecl *fn_key_t)(const int *, int, int **, int *);

typedef int (__cdecl *fn_read_file_t)(FILE *, size_t *);

typedef void (__cdecl *fn_write_to_array_t)(FILE *, int *);

typedef void (__cdecl *fn_write_to_file_t)(int *, int, FILE *);

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    HMODULE hlib;
	fn_mysort_t mysort;
	fn_key_t key;
	fn_read_file_t read_file;
	fn_write_to_array_t write_to_array;
	fn_write_to_file_t write_to_file;

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

        hlib = LoadLibrary("dyn2.dll");
        if (!hlib)
        {
            printf("ERROR: Can't load library dyn2.dll!\n");
            fclose(file);
            return ERR_LIBRARY;
        }


        read_file = (fn_read_file_t) GetProcAddress(hlib, "read_file");
        if (!read_file)
        {
            printf("ERROR: Can't load function read_file!\n");
            fclose(file);
            FreeLibrary(hlib);
            return ERR_LIBRARY;
        }

        int n = read_file(file, &count);
        if (n == ERR_READ_FILE)
        {
            printf("ERROR READING!");
            fclose(file);
            FreeLibrary(hlib);
            return ERR_READ_FILE;
        }
        else if (n == ERR_EMPTY)
        {
            printf("ERROR ERR_EMPTY!");
            fclose(file);
            FreeLibrary(hlib);
            return ERR_EMPTY;
        }

        arr = malloc(count * sizeof(int));
        if (!arr)
        {
            printf("ERROR MEMORY!");
            fclose(file);
            FreeLibrary(hlib);
            return MEMORY_ERR;
        }

        write_to_array = (fn_write_to_array_t) GetProcAddress(hlib, "write_to_array");
        if (!write_to_array)
        {
            printf("ERROR: Can't load function write_to_array!\n");
            fclose(file);
            FreeLibrary(hlib);
            return ERR_LIBRARY;
        }
        write_to_array(file, arr);
        if (fclose(file) != OK)
        {
            printf("ERROR CLOSE FILE!");
            free(arr);
            FreeLibrary(hlib);
            return ERR_CLOSE;
        }

        FILE *fileout = NULL;
        fileout = fopen(argv[2], "w");
        if (fileout == NULL)
        {
            printf("ERROR OPEN FILE!");
            free(arr);
            FreeLibrary(hlib);
            return ERR_OPEN_FILE;
        }
        
        if (filter)
        {

            key = (fn_key_t) GetProcAddress(hlib, "key");
            if (!key)
            {
                printf("ERROR: Can't load function key!\n");
                free(arr);
                FreeLibrary(hlib);
                return ERR_LIBRARY;
            }

            n = key(arr, count, &dst, &len_dst);
            if (n != OK)
            {
                printf("ERROR FILLTER FUNCTION!");
                free(arr);
                FreeLibrary(hlib);
                return n;
            }
            else
            {
                dst = malloc (len_dst * sizeof(int));
                key(arr, count, &dst, &len_dst);

                mysort = (fn_mysort_t) GetProcAddress(hlib, "mysort");
                if (!mysort)
                {
                    printf("ERROR: Can't load function mysort!\n");
                    free(arr);
                    free(dst);
                    FreeLibrary(hlib);
                    return ERR_LIBRARY;
                }

                if (mysort(dst, len_dst, sizeof(int), compare) != OK)
                    return ERR_INVALID_PARAM;
                
                write_to_file = (fn_write_to_file_t) GetProcAddress(hlib, "write_to_file");
                if (!write_to_file)
                {
                    printf("ERROR: Can't load function write_to_file!\n");
                    free(arr);
                    free(dst);
                    FreeLibrary(hlib);
                    return ERR_LIBRARY;
                }

                write_to_file(dst, len_dst, fileout); 
            }
        }
        else
        {
            mysort = (fn_mysort_t) GetProcAddress(hlib, "mysort");
            if (!mysort)
            {
                printf("ERROR: Can't load function mysort!\n");
                free(arr);
                free(dst);
                FreeLibrary(hlib);
                return ERR_LIBRARY;
            }
            if (mysort(arr, count, sizeof(int), compare) != OK)
                return ERR_INVALID_PARAM;
            
            write_to_file = (fn_write_to_file_t) GetProcAddress(hlib, "write_to_file");
            if (!write_to_file)
            {
                printf("ERROR: Can't load function write_to_file!\n");
                free(arr);
                free(dst);
                FreeLibrary(hlib);
                return ERR_LIBRARY;
            }

            write_to_file(arr, count, fileout);
        }

        free(arr);
        free(dst);
        FreeLibrary(hlib);
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