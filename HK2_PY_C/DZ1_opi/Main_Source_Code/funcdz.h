/**
 * \file funcdz.h
 * \author Truong Van Hao
 * \brief This header file!
 * \warning The main code is in file homework.c
 */

#ifndef _funcdz_h_
#define _funcdz_h_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \def MAX_ARR
 * \brief Maximal size of array
 */
#define MAX_ARR      100

#define ERR_EMPTY    -1
#define Input_Error  -2
#define NOT_EXIST    -3
#define ERR_100      -4


/**
 * \fn int ReadFile(FILE *file, int a[], int n)
 * \brief Get number of array elements and elements themselves
 *
 * \param [in] file pointer to file
 * \param [out] a pointer to arrray
 * \param [out] n pointer to number of elements
 * \return error code
 */
int ReadFile(FILE *file, int a[], int n);


/**
 * \fn int SumDigits(int num)
 * \brief Determines whether the sum of digits is even or odd
 * 
 * \param [in] num pointer to a number
 * \return 1 or 0 (even or odd) 
 */
int SumDigits(int num);


/**
 * \fn int ReverseNumber(int num)
 * \brief The reverse of the number 
 * 
 * \param [in] num pointer to a number
 * \return number (after reverse) 
 */
int ReverseNumber(int num);


/**
 * \fn int ConverNumberToBase2(int num)
 * \brief Convert a numbers to base 2 
 * 
 * \param [in] num pointer to a number
 * \return  number (after convert to base 2)
 */
int ConverNumberToBase2(int num);


/**
 * \fn void ConverNumber(int a[], int n)
 * \brief Convert a numbers
 * 
 * \param [in,out] a pointer to array 
 * \param [in] n pointer to number of elemnets
 */
void ConverNumber(int a[], int n);


/**
 * \fn void PrintArr(int a[], int n)
 * \brief Print elements of array
 * 
 * \param [in] a pointer to array 
 * \param [in] n pointer to number of elemnets
 */
void PrintArr(int a[], int n);

#endif 