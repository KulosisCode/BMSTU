/* Текстовый файл, задания a, b.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "input_output.h"
#include "process1.h"
#include "process2.h"

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	FILE *f1, *f2;
	struct product info[N];
	if (argc != 4)
		return KEY_ERR;
	if (strcmp(argv[1], "st") == 0)
	{
		f1 = fopen(argv[2], "r");
		if (f1 == NULL)
			return OPEN_FILE_ERR;
		f2 = fopen(argv[3], "w");
		if (f2 == NULL)
			return OPEN_FILE_ERR;
		int rc = process1(f1, f2, info);
		fclose(f1);
		fclose(f2);
		if (rc == READ_ERR)
			return READ_ERR;
		if (rc == EMPTY_FILE)
			return EMPTY_FILE;
		return OK;
	}
	else if (strcmp(argv[1], "ft") == 0)
	{
		char str[NAME + 1] = "";
		strcpy(str, argv[3]);
		f1 = fopen(argv[2], "r");
		if (f1 == NULL)
			return OPEN_FILE_ERR;
		int rc = process2(f1, str, info);
		if (rc == READ_ERR)
			return READ_ERR;
		if (rc == EMPTY_FILE)
			return EMPTY_FILE;
		if (rc == NO)
			return NO;
		return OK;
	}
	else
		return KEY_ERR;
}
