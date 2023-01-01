#include "check_main.h"

START_TEST(test_filter_invalid_1)
{
    int *begin = NULL;
    int len = 0;
    int rc = key(NULL, 5, &begin, &len);
    ck_assert_int_eq(rc, ERR_INVALID_PARAM);
    ck_assert_int_eq(len, 0);
    ck_assert_ptr_null(begin);
}
END_TEST

START_TEST(test_filter_invalid_2)
{
    int arr[5] = {1, 3, 2, 5, 4};
    int *begin = NULL;
    int len = 0;
    int rc = key(arr, 0, &begin, &len);
    ck_assert_int_eq(rc, ERR_INVALID_PARAM);
    ck_assert_int_eq(len, 0);
    ck_assert_ptr_null(begin);
}
END_TEST

START_TEST(test_filter_no_data_left)
{
    int arr[5] = {-1, 9, 8, 1, 5};
    int *begin = NULL;
    int len = 0;
    int rc = key(arr, 5, &begin, &len);
    ck_assert_int_eq(rc, NO_DATA_LEFT);
    ck_assert_int_eq(len, 0);
    ck_assert_ptr_null(begin);
}
END_TEST

START_TEST(test_filter_normal)
{
    int arr[5] = {1, 3, 2, -5, 4};
    int *begin = NULL;
    int len = 0;
    int rc = key(arr, 5, &begin, &len);
    begin = malloc(len * sizeof(int));
    key(arr, 5, &begin, &len);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(len, 3);
    ck_assert_int_eq(*begin, 1);
    ck_assert_int_eq(*(begin + 1), 3);
    ck_assert_int_eq(*(begin + 2), 2);
    free(begin);
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