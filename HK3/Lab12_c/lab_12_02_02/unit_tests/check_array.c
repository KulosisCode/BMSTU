#include "check_main.h"

START_TEST(test_fibonacci_fill_1)
{
    int a[1] = { 0 };
    fibonacci_fill(1, a);

    ck_assert_int_eq(a[0], 1);
}
END_TEST

START_TEST(test_fibonacci_fill_2)
{
    int a[2] = { 0 };
    fibonacci_fill(2, a);

    ck_assert_int_eq(a[0], 1);
    ck_assert_int_eq(a[1], 1);
}
END_TEST

START_TEST(test_fibonacci_fill_usual)
{
    int a[9] = { 0 };
    fibonacci_fill(8, a);

    ck_assert_int_eq(a[0], 1);
    ck_assert_int_eq(a[1], 1);
    ck_assert_int_eq(a[2], 2);
    ck_assert_int_eq(a[3], 3);
    ck_assert_int_eq(a[4], 5);
    ck_assert_int_eq(a[5], 8);
    ck_assert_int_eq(a[6], 13);
    ck_assert_int_eq(a[7], 21);
    ck_assert_int_eq(a[8], 0);
}
END_TEST

Suite* fibonacci_fill_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("fibonacci_fill");

    tc = tcase_create("neutral");
    tcase_add_test(tc, test_fibonacci_fill_1);
    tcase_add_test(tc, test_fibonacci_fill_2);
    tcase_add_test(tc, test_fibonacci_fill_usual);
    suite_add_tcase(s, tc);

    return s;
}

START_TEST(test_get_first_meet_less_than)
{
    int a[5] = { 3, 2, -1, 1, 5 };
    int b[7] = { 0 };
    int n = 0;

    get_first_meet(a, 5, b, &n);
    ck_assert_int_eq(n, 5);
    get_first_meet(a, 5, b, &n);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(a[i], b[i]);
    ck_assert_int_eq(b[5], 0);
    ck_assert_int_eq(b[6], 0);
}
END_TEST

START_TEST(test_get_first_meet_repeat)
{
    int a[5] = { 2, 2, 2, 2, 2 };
    int b[2] = { 0 };
    int n = 2;

    get_first_meet(a, 5, b, &n);
    ck_assert_int_eq(n, 1);
    ck_assert_int_eq(b[0], 2);
    ck_assert_int_eq(b[1], 0);
}
END_TEST

START_TEST(test_get_first_meet_usual)
{
    int a[6] = { 1, 3, 1, 5, 3, 4 };
    int b[5] = { 0 };
    int n = 5;

    get_first_meet(a, 6, b, &n);
    ck_assert_int_eq(n, 4);
    ck_assert_int_eq(b[0], 1);
    ck_assert_int_eq(b[1], 3);
    ck_assert_int_eq(b[2], 5);
    ck_assert_int_eq(b[3], 4);
}
END_TEST

Suite* get_first_meet_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("get_first_meet");

    tc = tcase_create("neutral");
    tcase_add_test(tc, test_get_first_meet_less_than);
    tcase_add_test(tc, test_get_first_meet_repeat);
    tcase_add_test(tc, test_get_first_meet_usual);
    suite_add_tcase(s, tc);

    return s;
}