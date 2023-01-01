#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define MIN_COMMAND 0
#define MAX_COMMAND 11
#define NOT_PALINDROME 0
#define PALINDROME 1

#define MAX_STACK 100
#define ERR_COMMAND -1
#define ERR_OVER_FLOW -2
#define ERR_EMPTY_STACK -3
#define ERR_INPUT -4


typedef struct
{
    int len;
    char array[MAX_STACK + 1];
} stack_arr_t;

typedef struct node
{
    int len;
    char sym;
    struct node *next;
} stack_list_t;

typedef struct
{
    size_t *arr;
    int size;
} locate_t;

//io
void clear();
void menu(void);
void message(int rc);
int input_symbol(char *sym);

//array
int add_symbol_to_arr(stack_arr_t *array, const char sym);
int array_input(stack_arr_t *array);
char pop_stack_array(stack_arr_t *arr);
int print_array(stack_arr_t *arr);
int array_is_palindrome(stack_arr_t *arr);

//list
stack_list_t *create_node(const char sym);
int add_node_to_list(stack_list_t **head, const char sym);
int list_input(stack_list_t **head);
char pop_stack_list(stack_list_t **head, size_t *locate);
int print_list(stack_list_t **head, locate_t address);
int list_is_palindrome(stack_list_t **head);
void free_list(stack_list_t *head);


//address
locate_t *create_address(void);
void print_address(const locate_t address);
int free_array_address(locate_t *address);

//effect
int time_effect();
#endif