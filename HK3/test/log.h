#ifndef _LOG_H_
#define _LOG_H_

#include <stdio.h>

extern FILE *flog;

int log_init(const char *name);

void log_close(void);

#endif 