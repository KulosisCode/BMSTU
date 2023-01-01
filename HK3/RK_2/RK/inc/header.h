#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30
#define MAX_GR 10
#define EMPTY -5

#define OK 0
#define ERR_READ -1
#define ERR_ALLOCATE -2
#define ERR_EMPTY -3
#define ERR_PARAM -4

typedef struct node
{
    char *name;
    int year;
    char *group;
    struct node *next;
} node_t;

#endif 