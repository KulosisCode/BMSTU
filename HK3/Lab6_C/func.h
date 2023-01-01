#ifndef _FUNC_H_
#define _FUNC_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARG 3
#define MIN_ARG 2
#define MAX_LEN 25
#define FILTER_SIZE 100
#define ALL "ALL"
#define MAX_THINGS 16
#define OK 0
#define ERR_DATA -1
#define ERR_EMPTY -2
#define ERR_EXIST -3
#define ERR_ARG -4
#define ERR_CLOSE -5
#define ERR_MAX_THINGS -6

typedef struct
{
    char name[MAX_LEN];
    float weight;
    float volume;
    float density;
} stuff;

int read_file(FILE *file, stuff *things);
void print_structure(const stuff *const things, const int index);
void sorted_stuff(stuff *things, const int n);
void print_info(stuff *things, const int n, int argc, char *filter);
#endif