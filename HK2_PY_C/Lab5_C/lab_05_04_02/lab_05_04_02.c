#include "func.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int err = NOT_ENOUGH_ARG;
    //app.exe st FILE_SRC FILE_DST
    if (argc == 4 && strcmp(argv[1], "st") == 0)
    {
        err = OK;
        FILE *file = fopen(argv[2], "r");
        FILE *fileout = fopen(argv[3], "w");
        err = process_st(file, fileout);
        return err;
    }
    //app.exe ft FILE SUBSTR
    if (argc == 4 && strcmp(argv[1], "ft") == 0)
    {
        err = OK;
        FILE *file = fopen(argv[2], "r");
        err = process_ft(file, argv[3]);
        return err;
    }
    return err;
}