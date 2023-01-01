#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>

#include "struct.h"
int create_list(node_t** root, FILE *f);
node_t* create_group_list(char* group_name, node_t* list);

#endif