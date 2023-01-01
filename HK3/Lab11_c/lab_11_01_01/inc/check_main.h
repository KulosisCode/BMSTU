#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include "header.h"
#include <assert.h>
#include "check.h"

#define MAX_LEN 100

Suite* param_suite(void);
Suite* s_suite(void);
Suite* hx_suite(void);

#endif