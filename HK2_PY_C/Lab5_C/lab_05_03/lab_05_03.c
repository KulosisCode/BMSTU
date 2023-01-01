#include "func.h"

int main(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
    {
        fprintf(stderr, "ERROR FILE!");
        return ERR_FILE;
    }
    int err = OK;
    //app.exe c number file
    if (strcmp(argv[1], "c") == 0)
    {
        FILE *file = fopen(argv[3], "wb");
        err = write_to_file(file, argv[2]);
        fclose(file);
        return err;
    }

    //app.exe p file
    if (strcmp(argv[1], "p") == 0)
    {
        FILE *file = fopen(argv[2], "rb");
        err = read_from_file(file);
        fclose(file);
        return err;
    }

    //app.exe s file
    //file Sort up ascending 
    if (strcmp(argv[1], "s") == 0)
    {
        FILE *file = fopen(argv[2], "rb+");
        err = sort_file(file);
        fclose(file);
        return err;
    }
    return ERR_INPUT;
}