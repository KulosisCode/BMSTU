#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "input_output.h"
#include "process2.h"

int check(char *str1, char *str2)
{
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	if (n1 < n2)
		return NO;
	int flag = 1;
	for (int i = 0; i < n2; i++)
		if (str2[n2 - i - 1] != str1[n1 - i - 1])
		{
			flag = 0;
			break;
		}
	if (!flag)
		return NO;
	return OK;	
}

int process2(FILE *f1, char *str, struct product *info)
{
	int count = read(f1, info);
	if (count == 0)
		return EMPTY_FILE;
	if (count == READ_ERR)
		return READ_ERR;
	int n = 0;
	for (int i = 0; i < count; i++)
	{
		if (check(info[i].name, str) == OK)
		{
			n++;
			printf("%s\n", info[i].name);
			printf("%s\n", info[i].producer);
			printf("%u\n", info[i].price);
			printf("%u\n", info[i].number);
		}
	}
	if (n != 0)
		return OK;
	else
		return NO;
}