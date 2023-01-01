/**
 * \file homework.c
 * \brief This is main code file!
 * \author Truong Van Hao
 * \date 22.5.2021
 * \warning All subfuntions are initialized in file funcdz.h
 */

#include "funcdz.h"

/**
 * \fn int main()
 * \brief Take the elements in the array and convert them 
 *
 * \return error code
 */
int main()
{
    int a[100];
    FILE *file = NULL;
    int n = 0;
    n = ReadFile(file, a, n);
    if (n == 0)
    {
        printf("Empty file !");
        return ERR_EMPTY;
    }
    else if (n == Input_Error)
    {
        printf("Incorrect data!");
        return Input_Error;
    }
    else if (n == ERR_100)
    {
        printf("The file line has more than 100 numbers!");
        return ERR_100;
    }
    else if (n == NOT_EXIST)
    {
        printf("The file does not exist!");
        return NOT_EXIST;
    }
    else 
    {
        ConverNumber(a, n);
        PrintArr(a, n);
        return EXIT_SUCCESS;
    }
}