#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <time.h>

#define TIME (float)rand() / RAND_MAX
#define CHANCE_RETURN (float)rand() / RAND_MAX
#define NUMBER 10
#define EPS 1e-5

#define MAX_ELEM 1000
#define MIN_COMMAND 0
#define MAX_COMMAND 10
#define ZERO 0

#define OK 0
#define ERR_COMMAND -1 
#define ERR_OVER_FLOW -2 
#define ERR_EMPTY -3
#define ERR_INPUT -4


typedef struct 
{
    int queue[MAX_ELEM];
    int head;
    int last;
    int len;
} array_queue_t;

typedef struct node
{
    int elem;
    struct node *next;
} node_t;

typedef struct list_queue_t
{
    int len;
    node_t *head;
    node_t *last;
} list_queue_t;


//io
int input_number(int *elem);
void clear();
void message(int rc);
void menu(void);


//array queue
int array_queue_add(array_queue_t *array, int elem);
int array_queue_pop(array_queue_t *array);
void print_array_queue(array_queue_t array);
void array_queue_process(void);

//list queue
node_t *create_node(const int elem);
int list_queue_add(list_queue_t *list, int elem);
int list_queue_pop(list_queue_t *list);
void print_list(list_queue_t list);
void print_address_free(size_t *free_elem, int n);
void free_list(list_queue_t *list);
void list_queue_process(void);

//time 
void get_time(float *result, float time_1, float time_2);
int time_effect();

#endif