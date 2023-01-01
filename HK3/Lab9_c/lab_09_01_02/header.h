#ifndef _FUNC_H_
#define _FUNC_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ARG 3
#define MIN_ARG 2
#define MAX_LEN 25
#define FILTER_SIZE 100
#define ALL "ALL"
#define MAX_THINGS 30
#define EPS 1e-7

#define OK 0
#define ERR_DATA -1
#define ERR_EMPTY -2
#define ERR_EXIST -3
#define ERR_ARG -4
#define ERR_CLOSE -5
#define ERR_MAX_THINGS -6
#define ERR_ALLOCATE -7
#define ERR_PARAM -8

typedef struct
{
    char *name;
    double weight;
    double volume;
    double density;
} stuff;

//io
void print_structure(FILE *out, stuff *const things);
void print_info(stuff *things, const size_t n, int argc, char *filter);
void free_single_thing(stuff *thing);
void free_things(stuff *things, const int size);

//read
int create_things(stuff *things, const char *name, double weight, double volume);
int read_file(FILE *file, stuff *things);
int count_things(FILE *file, size_t *size);
void read_all_things(FILE *file, stuff *things, size_t size);

//sort
int sorted_stuff(stuff *things, const size_t n);

#endif