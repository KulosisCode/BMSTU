#include "check_main.h"

START_TEST(test_param_snull_nnull)
{
    char *exp_s = NULL;
    char *my_s = NULL;
    int n = 0;

    int exp_out = snprintf(exp_s, n, "abc");
    int my_out = my_snprintf(my_s, n, "abc");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), FAIL);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_param_nnull)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 0;

    int exp_out = snprintf(exp_s, n, "123");
    int my_out = my_snprintf(my_s, n, "123");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_param_n_less_input)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 3;

    int exp_out = snprintf(exp_s, n, "12345");
    int my_out = my_snprintf(my_s, n, "12345");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_param_n_more_input)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 10;

    int exp_out = snprintf(exp_s, n, "12345");
    int my_out = my_snprintf(my_s, n, "12345");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_param_n_equal_input)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 6;

    int exp_out = snprintf(exp_s, n, "12345");
    int my_out = my_snprintf(my_s, n, "12345");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_param_n_neg)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = -1;

    int exp_out = snprintf(exp_s, n, "12345");
    int my_out = my_snprintf(my_s, n, "12345");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

// START_TEST(test_param_nothing_inputed)
// {
//     char exp_s[MAX_LEN] = { '\0' };
//     char my_s[MAX_LEN] = { '\0' };
//     int n = 5;

//     int exp_out = snprintf(exp_s, n, "");
//     int my_out = my_snprintf(my_s, n, "");

//     ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
//     ck_assert_int_eq(exp_out, my_out);
// }
// END_TEST

//extra args
// START_TEST(test_param_more_args)
// {
//     char exp_s[MAX_LEN] = { '\0' };
//     char my_s[MAX_LEN] = { '\0' };
//     int n = 5;

//     int exp_out = snprintf(exp_s, n, "abc", 10);
//     int my_out = my_snprintf(my_s, n, "abc", 10);

//     ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
//     ck_assert_int_eq(exp_out, my_out);
// }
// END_TEST

Suite* param_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("check_param");

    tc = tcase_create("neutrals");
    tcase_add_test(tc, test_param_snull_nnull);
    tcase_add_test(tc, test_param_nnull);
    tcase_add_test(tc, test_param_n_less_input);
    tcase_add_test(tc, test_param_n_more_input);
    tcase_add_test(tc, test_param_n_equal_input);
    tcase_add_test(tc, test_param_n_neg);
    // tcase_add_test(tc, test_param_nothing_inputed);
    // tcase_add_test(tc, test_param_more_args);

    suite_add_tcase(s, tc);

    return s;
}


START_TEST(test_s_nothing)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 10;

    int exp_out = snprintf(exp_s, n, "%s", "");
    int my_out = my_snprintf(my_s, n, "%s", "");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_s_no_space)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 15;

    int exp_out = snprintf(exp_s, n, "123%s123", "abc");
    int my_out = my_snprintf(my_s, n, "123%s123", "abc");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_s_wont_begin)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 6;

    int exp_out = snprintf(exp_s, n, "abcd%safter", "abc");
    int my_out = my_snprintf(my_s, n, "abcd%safter", "abc");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_s_wont_end)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 7;

    int exp_out = snprintf(exp_s, n, "abcd%safter", "abcd");
    int my_out = my_snprintf(my_s, n, "abcd%safter", "abcd");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_s_exactly)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 7;

    int exp_out = snprintf(exp_s, n, "1234%safter", "ab");
    int my_out = my_snprintf(my_s, n, "1234%safter", "ab");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_s_more_s)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 15;

    int exp_out = snprintf(exp_s, n, "Hello %s %s.", "ab","cd");
    int my_out = my_snprintf(my_s, n, "Hello %s %s.", "ab","cd");

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

// extra args
// START_TEST(test_s_extra_args)
// {
//     char exp_s[MAX_LEN] = { '\0' };
//     char my_s[MAX_LEN] = { '\0' };
//     int n = 15;

//     int exp_out = snprintf(exp_s, n, "abcd%safter", "ab", "cd");
//     int my_out = my_snprintf(my_s, n, "abcd%safter", "ab", "cd");

//     ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
//     ck_assert_int_eq(exp_out, my_out);
// }
// END_TEST

// //not enough args
// START_TEST(test_s_notenough_args)
// {
//     char exp_s[MAX_LEN] = { '\0' };
//     char my_s[MAX_LEN] = { '\0' };
//     int n = 20;

//     int exp_out = snprintf(exp_s, n, "%s%s", "ab");
//     int my_out = my_snprintf(my_s, n, "%s%s", "ab");

//     ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
//     ck_assert_int_eq(exp_out, my_out);
// }
// END_TEST

Suite* s_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("check_s");

    tc = tcase_create("neutral");
    tcase_add_test(tc, test_s_nothing);
    tcase_add_test(tc, test_s_no_space);
    tcase_add_test(tc, test_s_wont_begin);
    tcase_add_test(tc, test_s_wont_end);
    tcase_add_test(tc, test_s_exactly);
    tcase_add_test(tc, test_s_more_s);

    // tcase_add_test(tc, test_s_extra_args);
    // tcase_add_test(tc, test_s_notenough_args);

    suite_add_tcase(s, tc);

    return s;
}

START_TEST(test_hx_neg)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "hello %hx", -100);
    int my_out = my_snprintf(my_s, n, "hello %hx", -100);

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_hx_0)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 30;

    int exp_out = snprintf(exp_s, n, "%hx", 0);
    int my_out = my_snprintf(my_s, n, "%hx", 0);

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST


START_TEST(test_hx_not_end)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 3;

    int exp_out = snprintf(exp_s, n, "%hx", 7000);
    int my_out = my_snprintf(my_s, n, "%hx", 7000);

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_hx_more)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 20;

    int exp_out = snprintf(exp_s, n, "hello %hx %hx", 7000, 10);
    int my_out = my_snprintf(my_s, n, "hello %hx %hx", 7000, 10);

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

START_TEST(test_hx_with_s)
{
    char exp_s[MAX_LEN] = { '\0' };
    char my_s[MAX_LEN] = { '\0' };
    int n = 20;

    int exp_out = snprintf(exp_s, n, "hello %s %hx", "raiden", 10);
    int my_out = my_snprintf(my_s, n, "hello %s %hx", "raiden", 10);

    ck_assert_int_eq(my_strcmp(exp_s, my_s), OK);
    ck_assert_int_eq(exp_out, my_out);
}
END_TEST

Suite* hx_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("check_hx");

    tc= tcase_create("neutral");
    tcase_add_test(tc, test_hx_neg);
    tcase_add_test(tc, test_hx_0);
    tcase_add_test(tc, test_hx_not_end);
    tcase_add_test(tc, test_hx_more);
    tcase_add_test(tc, test_hx_with_s);

    suite_add_tcase(s, tc);

    return s;
}