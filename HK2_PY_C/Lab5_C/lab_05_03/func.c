#include "func.h"

int is_number(char *str)
{
    for (size_t i = 0; i < strlen(str); i++)
        if (!isdigit((int)str[i]))
            return ERR_NUMBER;
    return OK;
}

int write_to_file(FILE *file, char *number)
{
    if (file == NULL)
    {
        fprintf(stderr, "FILE NOT EXIST!");
        return ERR_EXIST_FILE;
    }
    if (is_number(number) == ERR_NUMBER)
    {
        fprintf(stderr, "ERROR NUMBER!");
        return ERR_NUMBER;
    }
    else 
    {
        int num = atoi(number);
        int x;
        srand(time(NULL));
        for (int i = 0; i < num ; i++)
        {
            x = rand() % 10000;
            if (fwrite(&x, sizeof(int), 1, file) != 1)
            {
                fprintf(stderr, "ERROR WRITE!");
                return ERR_WRITE;
            }
        }
        return OK;
    }
}

size_t check_size_file(FILE *file, int *err)
{
    if (fseek(file, 0, SEEK_END))
    {
        fprintf(stderr, "ERROR GET SIZE OF FILE!");
        *err = ERR_GET_SIZE;
    }
    long int size = ftell(file);
    if (size < 1)
    {
        fprintf(stderr, "ERROR EMPTY FILE!");
        *err = ERR_EMPTY_FILE;
    }
    rewind(file);
    return (size_t)size;
}

int read_from_file(FILE *file)
{
    if (file == NULL)
    {
        fprintf(stderr, "FILE NOT EXIST!");
        return ERR_EXIST_FILE;
    }
    int x, err = OK;
    size_t size = check_size_file(file, &err);
    rewind(file);
    if (err != OK)
    {
        return ERR_GET_SIZE;
    }
    else if (size < sizeof(int))
    {
        fprintf(stderr, "ERROR INPUT!");
        return ERR_INPUT;
    }
    while (fread(&x, sizeof(int), 1, file) == 1)
        fprintf(stdout, "%d ", x);
    return OK;
}

void err_mess(int err)
{
    if (err == ERR_EXIST_FILE)
    {
        fprintf(stderr, "ERROR EXIST FILE!");
    }
    else if (err == ERR_EMPTY_FILE)
    {
        fprintf(stderr, "ERROR EMPTY FILE!");
    }
    else if (err == ERR_INPUT)
    {
        fprintf(stderr, "ERROR INPUT!");
    }
    else if (err == ERR_POS)
    {
        fprintf(stderr, "ERROR POSITION!");
    }
}

int get_amount(FILE *file, int *err)
{
    int x, count = 0;
    if (file == NULL)
    {
        *err = ERR_EXIST_FILE;
        return ERR_EXIST_FILE;
    }
    rewind(file);
    while (fread(&x, sizeof(int), 1, file) == 1)
    {
        count++;
    }
    if (!feof(file))
    {
        *err = ERR_INPUT;
        return ERR_INPUT;
    }
    if (count == 0)
        return ERR_EMPTY_FILE;
    return count;
}

int get_number_by_pos(FILE *file, const int pos, int *num, int *err)
{
    int x, cur = 0;
    int count = get_amount(file, err);
    rewind(file);
    if (pos >= count || pos < 0)
    {
        *err = ERR_POS;
        return ERR_POS;
    }
    while (feof(file) == 0)
    {
        if (fread(&x, sizeof(int), 1, file) != 1)
        {
            break;
        }
        if (cur == pos)
            *num = x;
        cur++;
    }
    rewind(file);
    return OK;
}

int put_number_by_pos(FILE *file, const int pos, int num, int *err)
{
    int count = get_amount(file, err);
    if (pos >= count || pos < 0)
    {
        *err = ERR_POS;
        return ERR_POS;
    }
    fseek(file, sizeof(int) * (size_t)pos, SEEK_SET);
    fwrite(&num, sizeof(int), 1, file);
    rewind(file);
    return OK;
}

int sort_file(FILE*file)
{
    if (file == NULL)
    {
        fprintf(stderr, "ERROR EXIST FILE!");
        return ERR_EXIST_FILE;
    }
    int err = OK, num_1, num_2;
    int count = get_amount(file, &err);
    rewind(file);
    if (err != OK)
    {
        err_mess(err);
        return err;
    }
    for (int i = 0 ; i < count - 1; i++)
        for (int j = 0; j < count - 1 - i; j++)
        {
            get_number_by_pos(file, j, &num_1, &err);
            get_number_by_pos(file, j + 1, &num_2, &err);
            if (err != OK)
            {
                err_mess(err);
                return err;
            }
            if (num_1 > num_2)
            {
                put_number_by_pos(file, j, num_2, &err);
                put_number_by_pos(file, j + 1, num_1, &err);
            }
            if (err != OK)
            {
                err_mess(err);
                return err;
            }
        }        
    return err;
}