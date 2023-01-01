#include "../inc/check_main.h"

START_TEST(test_filter_invalid_1)
{
    int arr[5] = {1, 3, 2, 5, 4};
    int *begin = NULL, *end = NULL;
    int rc = key(NULL, arr + 5, &begin, &end);
    ck_assert_int_eq(rc, ERR_INVALID_PARAM);
    free_copy_arr(&begin, &end);
}
END_TEST

START_TEST(test_filter_invalid_2)
{
    int arr[5] = {1, 3, 2, 5, 4};
    int *begin = NULL, *end = NULL;
    int rc = key(arr, arr, &begin, &end);
    ck_assert_int_eq(rc, ERR_INVALID_PARAM);
    free_copy_arr(&begin, &end);
}
END_TEST

START_TEST(test_filter_no_data_left)
{
    int arr[5] = {-1, 9, 8, 1, 5};
    int *begin = NULL, *end = NULL;
    int rc = key(arr, arr + 5, &begin, &end);
    ck_assert_int_eq(rc, NO_DATA_LEFT);
    free_copy_arr(&begin, &end);
}
END_TEST

START_TEST(test_filter_normal)
{
    int arr[5] = {1, 3, 2, -5, 4};
    int *begin = NULL, *end = NULL;
    int rc = key(arr, arr + 5, &begin, &end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(end - begin, 3);
    ck_assert_int_eq(*begin, 1);
    ck_assert_int_eq(*(begin + 2), 2);
    free_copy_arr(&begin, &end);
}
END_TEST

Suite* check_filter(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("check_filter");
    
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_filter_invalid_1);
    tcase_add_test(tc_neg, test_filter_invalid_2);
    tcase_add_test(tc_neg, test_filter_no_data_left);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positive");

    tcase_add_test(tc_pos, test_filter_normal);
    suite_add_tcase(s, tc_pos);
    
    return s;
}