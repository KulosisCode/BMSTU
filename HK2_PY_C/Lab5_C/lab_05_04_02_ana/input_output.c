#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "input_output.h"

int read(FILE *f, struct product *info)
{
	int i = 0;
	while (!feof(f))
	{
		char str[11];
		if (!fgets(info[i].name, sizeof(info[i].name), f))
			break;
		if (!fgets(info[i].producer, sizeof(info[i].producer), f))
			break;
		int n1 = strlen(info[i].name);
		if (info[i].name[n1 - 1] == '\n')
			info[i].name[n1 - 1] = '\0'; 
		n1 = strlen(info[i].producer);
		if (info[i].producer[n1 - 1] == '\n')
			info[i].producer[n1 - 1] = '\0';
		
		if (!fgets(str, sizeof(str), f))
			break;
		info[i].price = (unsigned int) atoi(str);
		int n = strlen(str);
		for (int j = 0; j < n; j++)
			str[j] = '\0';
		
		if (!fgets(str, sizeof(str), f))
			break;
		info[i].number = (unsigned int) atoi(str);
		n = strlen(str);
		for (int j = 0; j < n; j++)
			str[j] = '\0';
		i++;
	}
	if (!feof(f))
	{
		if (fgetc(f) == '\n')
			return i;
		else
			return READ_ERR;
	}
	return i;
}

void result_print(struct product *info, int count)
{
	int i = 0;
	while (i < count)
	{
		printf("%s\n", info[i].name);
		printf("%s\n", info[i].producer);
		printf("%u\n", info[i].price);
		printf("%u\n", info[i].number);
		i++;
	}
}

void record(FILE *f, struct product *info, int count)
{
	for (int i = 0; i < count; i++)
	{
		fprintf(f, "%s\n", info[i].name);
		fprintf(f, "%s\n", info[i].producer);
		fprintf(f, "%u\n", info[i].price);
		fprintf(f, "%u\n", info[i].number);
	}
}