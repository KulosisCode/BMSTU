#ifndef _SORT_H_
#define _SORT_H_

#include "constan.h"

int compare(const void *a, const void *b);
void swap(size_t size, char *num_1, char *num_2);
int mysort(void *base, size_t nitems, size_t size, int (*compare)(const void*, const void*));

#endif