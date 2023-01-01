#include "check_main.h"

int check_mtr_eq(double **mtr1, double **mtr2, int n1, int m1, int n2, int m2)
{
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            if (fabs(mtr1[i][j] - mtr2[i][j]) > EPS)
                return 0;
    return 1;
}

//addition
START_TEST(test_add_matrix_zeros)
{
    int result;

    int n1 = 2, m1 = 2;
    double a1[2][2] = {{0, 0}, {0, 0}};
    double *mtr1[2] = {a1[0], a1[1]};

    double a2[2][2] = {{0, 0}, {0, 0}};
    double *mtr2[2] = {a2[0], a2[1]};

    int n3 = 2, m3 = 2;
    double a3[2][2] = {{0, 0}, {0, 0}};
    double *mtr3[2] = {a3[0], a3[1]};

    int n_res = 2, m_res = 2;
    double **mtr_res = NULL;
    mtr_res = allocate_matrix(n_res, m_res);
    assert(mtr_res != NULL);
    matrix_addition(mtr1, mtr2, mtr_res, n1, m1);

    result = check_mtr_eq(mtr3, mtr_res, n3, m3, n_res, m_res);
    ck_assert_int_eq(result, 1);
    free_matrix(mtr_res, n_res);
}
END_TEST

START_TEST(test_add_matrix_usual)
{
    int result;

    int n1 = 2, m1 = 3;
    double a1[2][3] = {{-2, 5, 0.5}, {-4, 5.2, 0}};
    double *mtr1[2] = {a1[0], a1[1]};

    double a2[2][3] = {{2, 5, -0.5}, {-2, -1.2, -9}};
    double *mtr2[2] = {a2[0], a2[1]};

    int n3 = 2, m3 = 3;
    double a3[2][3] = {{0, 10, 0}, {-6, 4.0, -9}};
    double *mtr3[2] = {a3[0], a3[1]};

    int n_res = 2, m_res = 3;
    double **mtr_res = NULL;
    mtr_res = allocate_matrix(n_res, m_res);
    assert(mtr_res != NULL);
    matrix_addition(mtr1, mtr2, mtr_res, n1, m1);

    result = check_mtr_eq(mtr3, mtr_res, n3, m3, n_res, m_res);
    ck_assert_int_eq(result, 1);
    free_matrix(mtr_res, n_res);
}
END_TEST

Suite* add_matrix_suite(void)
{
    Suite *count;
    TCase *tc_add;

    count = suite_create("add_matrix");

    tc_add = tcase_create("check_add");
    tcase_add_test(tc_add, test_add_matrix_zeros);
    tcase_add_test(tc_add, test_add_matrix_usual);
    suite_add_tcase(count, tc_add);

    return count;
}

//multi
START_TEST(test_mult_matrix_same_sizes)
{
    int result;

    int n1 = 2, m1 = 2;
    double a1[2][2] = {{1, 1.1}, {2, 0}};
    double *mtr1[2] = {a1[0], a1[1]};

    double a2[2][2] = {{1, 0}, {0, 1}};
    double *mtr2[2] = {a2[0], a2[1]};

    int n3 = 2, m3 = 2;
    double a3[2][2] = {{1, 1.1}, {2, 0}};
    double *mtr3[2] = {a3[0], a3[1]};

    int n_res = 2, m_res = 2;
    double **mtr_res = NULL;
    mtr_res = allocate_matrix(n_res, m_res);
    assert(mtr_res != NULL);
    matrix_multi(mtr1, mtr2, mtr_res, n1, m1, m1);

    result = check_mtr_eq(mtr3, mtr_res,n3, m3, n_res, m_res);
    ck_assert_int_eq(result, 1);
    free_matrix(mtr_res, n_res);
}
END_TEST

START_TEST(test_mult_matrix_dif_sizes)
{
    int result;

    int n1 = 2, m1 = 3;
    double a1[2][3] = {{-1, 1, 0.01},
                       {-2, 1.6, 0}};
    double *mtr1[2] = {a1[0], a1[1]};

    int m2 = 2;
    double a2[3][2] = {{1, -1},
                       {1, -1},
                       {1, -1}};
    double *mtr2[3] = {a2[0], a2[1], a2[2]};

    int n3 = 2, m3 = 2;
    double a3[2][2] = {{0.01, -0.01}, {-0.4, 0.4}};
    double *mtr3[2] = {a3[0], a3[1]};

    int n_res = n1, m_res = m2;
    double **mtr_res = NULL;
    mtr_res = allocate_matrix(n_res, m_res);
    assert(mtr_res != NULL);
    matrix_multi(mtr1, mtr2, mtr_res, n1, m1, m2);

    result = check_mtr_eq(mtr3, mtr_res,n3, m3, n_res, m_res);
    ck_assert_int_eq(result, 1);
    free_matrix(mtr_res, n_res);
}
END_TEST

Suite* mult_matrix_suite(void)
{
    Suite *count;
    TCase *tc_mult;

    count = suite_create("mult_matrix");

    tc_mult = tcase_create("check_multi");
    tcase_add_test(tc_mult, test_mult_matrix_same_sizes);
    tcase_add_test(tc_mult, test_mult_matrix_dif_sizes);
    suite_add_tcase(count, tc_mult);

    return count;
}

//gauss
START_TEST(test_gauss_det_simple)
{
    double result;

    int n = 2;
    double a[2][2] = {{0, 1}, {0, 1}};
    double *mtr[2] = {a[0], a[1]};

    result = gauss_caculation(mtr, n);

    ck_assert_double_eq_tol(result, 0, EPS);
}
END_TEST

START_TEST(test_gauss_det_same_line)
{
    double result;

    int n = 2;
    double a[2][2] = {{2, 3}, {2, 3}};
    double *mtr[2] = {a[0], a[1]};

    result = gauss_caculation(mtr, n);

    ck_assert_double_eq_tol(result, 0, EPS);
}
END_TEST

START_TEST(test_gauss_det_swap)
{
    double result;

    int n = 2;
    double a[2][2] = {{3, 3}, {2, 2}};
    double *mtr[2] = {a[0], a[1]};

    result = gauss_caculation(mtr, n);

    ck_assert_double_eq_tol(result, 0, EPS);
}
END_TEST


START_TEST(test_gauss_det_usual)
{
    double result;

    int n = 3;
    double a[3][3] = {{-1, 2, 3},
                      {2, 3, 4},
                      {3, 4, 5}};
    double *mtr[3] = {a[0], a[1], a[2]};

    result = gauss_caculation(mtr, n);

    ck_assert_double_eq_tol(result, 2, EPS);
}
END_TEST

Suite* get_gaus_det_suite(void)
{
    Suite *count;
    TCase *tc_gauss;

    count = suite_create("get_gauss_det");

    tc_gauss = tcase_create("check_gauss");
    tcase_add_test(tc_gauss, test_gauss_det_simple);
    tcase_add_test(tc_gauss, test_gauss_det_same_line);
    tcase_add_test(tc_gauss, test_gauss_det_swap);
    tcase_add_test(tc_gauss, test_gauss_det_usual);
    suite_add_tcase(count, tc_gauss);

    return count;
}