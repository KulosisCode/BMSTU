#include "func.h"
int get_product_to_array(FILE *file, product *products)
{
    int n = 0;
    while (fscanf(file, "%s %s", products[n].name, products[n].factory) == 2)
    {
        if (fscanf(file, "%u", &products[n].price) != 1)
            return ERR_READ_FILE;
        if (fscanf(file, "%u", &products[n].amount) != 1)
            return ERR_READ_FILE;
        n++;
    }
    if (n == 0)
        return ERR_READ_FILE;
    return n;
}
// int get_product_to_array(FILE *file, product *products)
// {
//     int i = 0;
//     while (!feof(file))
//     {
//         char str[11];
//         if (!fgets(products[i].name, sizeof(products[i].name), file))
//             break;
//         if (!fgets(products[i].factory, sizeof(products[i].factory), file))
//             break;
//         int n1 = strlen(products[i].name);
//         if (products[i].name[n1 - 1] == '\n')
//             products[i].name[n1 - 1] = '\0'; 
//         n1 = strlen(products[i].factory);
//         if (products[i].factory[n1 - 1] == '\n')
//             products[i].factory[n1 - 1] = '\0';
        
//         if (!fgets(str, sizeof(str), file))
//             break;
//         products[i].price = (unsigned int) atoi(str);
//         int n = strlen(str);
//         for (int j = 0; j < n; j++)
//             str[j] = '\0';
        
//         if (!fgets(str, sizeof(str), file))
//             break;
//         products[i].amount = (unsigned int) atoi(str);
//         n = strlen(str);
//         for (int j = 0; j < n; j++)
//             str[j] = '\0';
//         i++;
//     }
//     if (!feof(file))
//     {
//         if (fgetc(file) == '\n')
//             return i;
//         else
//             return ERR_READ_FILE;
//     }
//     return i;
// }
void sort_product_by_name(product *products, const int n)
{
    product temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (products[j].price < products[j + 1].price)
            {
                temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
            else if (products[j].price == products[j + 1].price)
            {
                if (products[j].amount < products[j + 1].amount)
                {
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
}

void print_result(FILE *fileout, product *products, const int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(fileout, "%s\n", products[i].name);
        fprintf(fileout, "%s\n", products[i].factory);
        fprintf(fileout, "%u\n", products[i].price);
        fprintf(fileout, "%u\n", products[i].amount);
    }
}

int process_st(FILE *file, FILE *fileout)
{
    if (file == NULL || fileout == NULL)
    {
        fprintf(stderr, "ERROR EXIST FILE!");
        return ERR_EXIST_FILE;
    }
    product products[MAX_PRODUCT];
    int n = get_product_to_array(file, products);
    if (n == ERR_READ_FILE)
    {
        fclose(file);
        fclose(fileout);
        fprintf(stderr, "ERROR READ FILE!");
        return ERR_READ_FILE;
    }
    if (n == 0)
    {
        return ERR_EMPTY;
    }
    sort_product_by_name(products, n);
    print_result(fileout, products, n);
    fclose(file);
    fclose(fileout);
    return OK;
}

int find_str(char *str, char *subname)
{
    // if (str == NULL || subname == NULL)
    //     return NO;
    // size_t a = strlen(str);
    // size_t b = strlen(subname);
    // if (a < b)
    //     return NO;
    // if (strncmp(str + a - b, subname, b) == 0)
    //     return OK;
    // return NO;
    int n1 = strlen(str);
    int n2 = strlen(subname);
    if (n1 < n2)
        return NO;
    int flag = 1;
    for (int i = 0; i < n2; i++)
        if (subname[n2 - i - 1] != str[n1 - i - 1])
        {
            flag = 0;
            break;
        }
    if (!flag)
        return NO;
    return OK;
}

void print_product(product *products, const int i)
{
    printf("%s\n", products[i].name);
    printf("%s\n", products[i].factory);
    printf("%u\n", products[i].price);
    printf("%u\n", products[i].amount);
}

int process_ft(FILE *file, char *subname)
{
    if (file == NULL)
    {
        fprintf(stderr, "ERROR EXIST FILE!");
        return ERR_EXIST_FILE;
    }
    int count = 0;
    product products[MAX_PRODUCT];
    int n = get_product_to_array(file, products);
    if (n == ERR_READ_FILE)
    {
        fclose(file);
        fprintf(stderr, "ERROR READ FILE!");
        return ERR_READ_FILE;
    }
    if (n == 0)
    {
        fclose(file);
        fprintf(stderr, "ERROR EMPTY !");
        return ERR_EMPTY;
    }
    for (int i = 0; i < n; i++)
    {
        if (find_str(products[i].name, subname) == OK)
        {
            print_product(products, i);
            count++;
        }       
    }
    //printf("%d", count);
    if (count == 0)
    {
        fclose(file);
        fprintf(stderr, "ERROR EMPTY !");
        return ERR_EMPTY;
    }
    fclose(file);
    return OK;
}