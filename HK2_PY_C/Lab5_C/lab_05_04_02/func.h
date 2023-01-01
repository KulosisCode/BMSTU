#ifndef _FUNC_H_
#define _FUNC_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define OK 0
#define NO -10
#define ERR_EXIST_FILE -1
#define ERR_READ_FILE -2
#define ERR_EMPTY -3
 
#define NOT_ENOUGH_ARG 53
#define MAX_LEN_NAME 30
#define MAX_LEN_FACTORY 15
#define MAX_PRODUCT 100

typedef struct
{
    char name[MAX_LEN_NAME + 3];
    char factory[MAX_LEN_FACTORY + 3];
    unsigned int price;
    unsigned int amount;
} product;

int get_product_to_array(FILE *file, product *products);
void sort_product_by_name(product *products, const int n);
void print_result(FILE *fileout, product *products, const int n);
int process_st(FILE *file, FILE *fileout);
int find_str(char str[MAX_LEN_NAME], char *subname);
void print_product(product *products, const int i);
int process_ft(FILE *file, char *subname);

#endif