#ifndef _SORT_H_
#define _SORT_H_

#include "constan.h"

#ifdef SORT_EXPORTS
#define SORT_DLL __declspec(dllexport)
#else
#define SORT_DLL __declspec(dllimport)
#endif

#define SORT_DECL __cdecl

SORT_DLL int SORT_DECL mysort(void *base, size_t nitems, size_t size, int (*compare)(const void*, const void*));
void swap(size_t size, char *num_1, char *num_2);

#endif