#include "check_main.h"

START_TEST(test_add_null_node_1)
{
    int rc = 0;
    node_t *node_1 = NULL, *node_2 = NULL;
    node_t *result = NULL;
    FILE *in1 = fopen("unit_tests/in_1.txt", "r");
    node_2 = read_file(in1, &rc);
    fclose(in1);

    rc = add_matrix(&result, node_1, node_2);
    ck_assert_int_eq(rc, ERR_PARAM);
    free_all_list(node_2);
}
END_TEST

START_TEST(test_add_all_node_null)
{
    int rc = 0;
    node_t *node_1 = NULL;
    node_t *node_2 = NULL;
    node_t *result = NULL;

    rc = add_matrix(&result, node_1, node_2);
    ck_assert_int_eq(rc, ERR_PARAM);
}
END_TEST

START_TEST(test_add_size_node_1_bigger)
{
    int rc = 0;
    node_t *node_1 = NULL, *node_2 = NULL, *node_3 = NULL;
    node_t *result = NULL;
    FILE *in1 = fopen("unit_tests/in_1.txt", "r");
    FILE *in2 = fopen("unit_tests/in_2.txt", "r");
    FILE *in3 = fopen("unit_tests/out_1.txt", "r");

    node_1 = read_file(in2, &rc);
    node_2 = read_file(in1, &rc);
    node_3 = read_file(in3, &rc);

    rc = add_matrix(&result, node_1, node_2);
    ck_assert_int_eq(rc, OK);
    
    node_t *curr = result;
    node_t *pers = node_3;
    for (; curr && pers; curr = curr->next, pers = pers->next)
    {
        ck_assert_int_eq(curr->num, pers->num);
    }
    free_all_list(node_1);
    free_all_list(node_2);
    free_all_list(node_3);
    free_all_list(result);
}
END_TEST

START_TEST(test_add_size_node_2_bigger)
{
    int rc = 0;
    node_t *node_1 = NULL, *node_2 = NULL, *node_3 = NULL;
    node_t *result = NULL;
    FILE *in1 = fopen("unit_tests/in_1.txt", "r");
    FILE *in2 = fopen("unit_tests/in_2.txt", "r");
    FILE *in3 = fopen("unit_tests/out_1.txt", "r");

    node_1 = read_file(in1, &rc);
    node_2 = read_file(in2, &rc);
    node_3 = read_file(in3, &rc);

    rc = add_matrix(&result, node_1, node_2);
    ck_assert_int_eq(rc, OK);
    
    node_t *curr = result;
    node_t *pers = node_3;
    for (; curr && pers; curr = curr->next, pers = pers->next)
    {
        ck_assert_int_eq(curr->num, pers->num);
    }
    free_all_list(node_1);
    free_all_list(node_2);
    free_all_list(node_3);
    free_all_list(result);
}
END_TEST

START_TEST(test_add_opposite_value_elements)
{
    int rc = 0;
    FILE *in1 = fopen("unit_tests/in_3.txt", "r");
    FILE *in2 = fopen("unit_tests/in_4.txt", "r");
    node_t *node_1 = read_file(in1, &rc);
    node_t *node_2 = read_file(in2, &rc);
    node_t *result = NULL;

    rc = add_matrix(&result, node_1, node_2);
    ck_assert_int_eq(rc, OK);
    rc = -1;
    if (!result)
        rc = OK;
    ck_assert_int_eq(rc, OK);

    free_all_list(node_1);
    free_all_list(node_2);
    free_all_list(result);
}
END_TEST

Suite* add_suite(void)
{
    Suite *result;
    TCase *tc_neg, *tc_pos;
    
    result = suite_create("check_add");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_add_null_node_1);
    tcase_add_test(tc_neg, test_add_all_node_null);
    suite_add_tcase(result, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_add_size_node_1_bigger);
    tcase_add_test(tc_pos, test_add_size_node_2_bigger);
    tcase_add_test(tc_pos, test_add_opposite_value_elements);
    suite_add_tcase(result, tc_pos);

    return result;
}

START_TEST(test_read_wrong_size_matrix)
{
    node_t *node = NULL;
    int rc = 0;
    FILE *file = fopen("unit_tests/read_1.txt", "r");

    node = read_file(file, &rc);

    ck_assert_int_eq(rc, ERR_DATA);
    ck_assert_ptr_null(node);
    free_all_list(node);
    fclose(file);
}
END_TEST

START_TEST(test_read_wrong_value_element)
{
    node_t *node = NULL;
    int rc = 0;
    FILE *file = fopen("unit_tests/read_2.txt", "r");

    node = read_file(file, &rc);

    ck_assert_int_eq(rc, ERR_DATA);
    ck_assert_ptr_null(node);
    free_all_list(node);
    fclose(file);
}
END_TEST

START_TEST(test_read_normal)
{
    node_t *node = NULL;
    int rc = 0;
    FILE *file = fopen("unit_tests/read_3.txt", "r");

    node = read_file(file, &rc);

    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(node->num, 1);
    free_all_list(node);
    fclose(file);
}
END_TEST

Suite* read_suite(void)
{
    Suite *result;
    TCase *tc;
    
    result = suite_create("check_read");

    tc = tcase_create("read_test");
    tcase_add_test(tc, test_read_wrong_size_matrix);
    tcase_add_test(tc, test_read_wrong_value_element);
    tcase_add_test(tc, test_read_normal);
    suite_add_tcase(result, tc);

    return result;
}