#ifndef _STRUCT_H
#define _STRUCT_H

typedef struct node node_t;
struct node
{
    char* name;
    int year;
    char* group;
    node_t* next;
};

#endif