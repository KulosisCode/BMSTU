#ifndef _LIST_FUNCS_H_
#define _LIST_FUNCS_H_

#include <stdio.h>

#include "define.h"
#include "struct.h"

node_t* create_node();
void add_last_node(node_t** head, node_t* new_node);
void print_list(node_t* head);
void free_list(node_t* head);
void free_node(node_t* cur_node);

#endif // !_LIST_FUNCS_H_
