#ifndef _KEY_H_
#define _KEY_H_

#include "constan.h"

#ifdef FILTER_EXPORTS
#define FILTER_DLL __declspec(dllexport)
#else
#define FILTER_DLL __declspec(dllimport)
#endif

#define FILTER_DECL __cdecl

FILTER_DLL int FILTER_DECL key(const int *src, int len_src, int **dst, int *len_dst);

#endif