#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define MAX_LEN_MANTISSA 30
#define MIN_LEN_MANTISSA 1
#define MAX_LEN_ORDER 5
#define MORE 1
#define LESS 0
#define GO 1
#define STOP 0
#define ZERO 50


#define EQUAL 1
#define NOT_EQUAL 0
#define ERR_NO_SIGN -1
#define ERR_SPACES -2
#define ERR_INPUT -3
#define MORE_ONE_POINT -4
#define INCORRECT_SYMBOL -5
#define ERR_LEN -6
#define DIVISION_BY_ZERO -7
#define NO_POINT -100
#define OVERFLOW -101

typedef struct 
{
    char number_sign;
    char mantissa[MAX_LEN_MANTISSA + 2];
    int point_index;
    char order_sign;
    int order;
} number;

void print_conditions(void);
int input_number(number *real_number);
void output_number(number real_number);

void delete_zeros(number *result_number);
int compare_characters(char first_char, char second_char);

void normalize_number(number *one_number);
void add_zeros(number *one_number);

int compare_numbers(number *first_number, number *second_number);
int compare_zero(number *one_number);
void change_zero(number *one_number);
int subtraction(number *first_number, number *second_number);
int divide_numbers(number *first_number, number *second_number, number *result_number);

#endif