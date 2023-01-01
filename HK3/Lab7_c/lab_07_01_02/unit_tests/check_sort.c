#include "../inc/check_main.h"

START_TEST(test_sort_null_base)
{
    int nitem = 5;
    int rc = mysort(NULL, nitem, sizeof(int), compare);
    ck_assert_int_eq(rc, ERR_INVALID_PARAM);
}
END_TEST

START_TEST(test_sort_zero_elment)
{
    int arr[6] = {1, -2, 2, 5, 4, -3};
    int rc = mysort(arr, 0, sizeof(int), compare);
    ck_assert_int_eq(rc, ERR_INVALID_PARAM);
}
END_TEST

START_TEST(test_sort_normal)
{
    int arr[5] = {1, -2, 2, 5, 4};
    int rc = mysort(arr, 5, sizeof(int), compare);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(arr[0], -2);
    ck_assert_int_eq(arr[1], 1);
    ck_assert_int_eq(arr[2], 2);
    ck_assert_int_eq(arr[3], 4);
    ck_assert_int_eq(arr[4], 5);
}
END_TEST

Suite* check_sort(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("check_sort");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_sort_null_base);
    tcase_add_test(tc_neg, test_sort_zero_elment);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_normal);
    suite_add_tcase(s, tc_pos);

    return s;
}