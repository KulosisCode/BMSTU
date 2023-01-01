#ifndef _CONSTAN_H_
#define _CONSTAN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define COUNT_ELE 1
#define OK 0
#define ERR_READ_FILE -1
#define ERR_EMPTY -2
#define ERR_DATA -3
#define NO_DATA_LEFT -4
#define MEMORY_ERR -5
#define ERR_ARGS -6
#define ERR_OPEN_FILE -7
#define ERR_CLOSE -8
#define ERR_INVALID_PARAM -9
#define ERR_LIBRARY -10

int compare(const void *a, const void *b);

#endif 