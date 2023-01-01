#include <stdio.h>
#include "log.h"

void func_1(void)
{
	fprintf(flog, "func_1\n");
}

void func_2(int a)
{
	fprintf(flog, "func_2(%d)\n", a);
}

int main(void)
{
	if (log_init("test.log"))
	{
		printf("Could not create log file");
		return -1;
	}

	func_1();
	func_2(5);

	log_close();
	return 0;
}