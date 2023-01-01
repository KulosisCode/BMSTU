#ifndef _IO_H_
#define _IO_H_

#include "constan.h"

int read_file(FILE *file, size_t *count);
void write_to_array(FILE *file, int *arr);
void write_to_file(int *p_b, int *p_e, FILE *f_out);
void free_copy_arr(int **pb, int **pe);

#endif 