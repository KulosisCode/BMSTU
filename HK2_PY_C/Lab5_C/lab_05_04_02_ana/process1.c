#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "input_output.h"
#include "process1.h"

void sort(struct product *info, int count)
{
	for (int i = 0; i < count - 1; i++)
		for (int j = 0; j < count - i - 1; j++)
			if (info[j].price < info[j + 1].price)
			{
				struct product tmp = info[j];
				info[j] = info[j + 1];
				info[j + 1] = tmp;
			}
			else if (info[j].price == info[j + 1].price)
				if (info[j].number < info[j + 1].number)
				{
					struct product tmp = info[j];
					info[j] = info[j + 1];
					info[j + 1] = tmp;
				}
}

int process1(FILE *f1, FILE *f2, struct product *info)
{	
	int count = read(f1, info);
	if (count == 0)
		return EMPTY_FILE;
	if (count == READ_ERR)
		return READ_ERR;
	sort(info, count);
	record(f2, info, count);
	return OK;
}
