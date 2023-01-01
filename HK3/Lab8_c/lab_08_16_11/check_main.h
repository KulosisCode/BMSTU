#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include "io.h"
#include <check.h>
#include <assert.h>

int check_mtr_eq(double **mtr1, double **mtr2, int n1, int m1, int n2, int m2);

Suite* add_matrix_suite(void);
Suite* mult_matrix_suite(void);
Suite* get_gaus_det_suite(void);

#endif