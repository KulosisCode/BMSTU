#ifndef _EFFICIENCY_H_
#define _EFFICIENCY_H_

#include "define.h"
#include "tree.h"
#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void efficiency(void);
int count_node_table(node_hash **table, int len_table);
unsigned long int tick(void);

#endif
