#ifndef _IO_H_
#define _IO_H_

#include "constan.h"

#ifdef IO_EXPORTS
#define IO_DLL __declspec(dllexport)
#else
#define IO_DLL __declspec(dllimport)
#endif

#define IO_DECL __cdecl

IO_DLL int IO_DECL read_file(FILE *file, size_t *count);
IO_DLL void IO_DECL write_to_array(FILE *file, int *arr);
IO_DLL void IO_DECL write_to_file(int *p_e, int len, FILE *f_out);

#endif 