#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include "header.h"
#include <assert.h>
#include "check.h"

Suite* pop_front_suite(void);
Suite* insert_suite(void);
Suite *rm_dup_suite(void);
Suite *sort_suite(void);

#endif