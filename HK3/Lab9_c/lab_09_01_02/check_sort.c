#include "check_main.h"

void free_object(stuff *things, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if ((things + i))
        {
            free((things + i)->name);
        }
    }
    free(things);
}


START_TEST(test_sort_null_pointer)
{
    stuff *obj = NULL;
    int n = 2;
    int rc = sorted_stuff(obj, n);
    ck_assert_int_eq(rc, ERR_PARAM);
}
END_TEST

START_TEST(test_sort_zero_elem)
{
    size_t n = 2;
    stuff *thing = calloc(n, sizeof(stuff));
    create_things(thing, "Pencil", 10, 2);
    create_things(thing + 1, "Fan", 15, 5);

    int rc = sorted_stuff(thing, 0);
    ck_assert_int_eq(rc, ERR_PARAM);
    free_object(thing, n);
}
END_TEST

START_TEST(test_sort_devide_zero)
{
    size_t n = 2;
    stuff *thing = calloc(n, sizeof(stuff));
    create_things(thing, "Pencil", 10, 0);
    create_things(thing + 1, "Fan", 15, 5);

    int rc = sorted_stuff(thing, n);
    ck_assert_int_eq(rc, ERR_DATA);
    free_object(thing, n);
}
END_TEST

START_TEST(test_sort_all_same_density)
{
    size_t n = 3;
    stuff *thing = calloc(n, sizeof(stuff));
    create_things(thing, "ABC", 10, 2); // density == 5
    create_things(thing + 1, "BCD", 15, 3); // density == 5
    create_things(thing + 2, "XYZ", 5, 1); // density == 5

    int rc = sorted_stuff(thing, n);
    ck_assert_int_eq(rc, OK);
    ck_assert_str_eq(thing->name, "ABC");
    ck_assert_str_eq((thing + 1)->name, "BCD");
    free_object(thing, n);
}
END_TEST

START_TEST(test_sort_normal_things)
{
    size_t n = 3;
    stuff *thing = calloc(n, sizeof(stuff));
    create_things(thing, "A", 10, 1); // density == 5
    create_things(thing + 1, "B", 20, 5); // density == 5
    create_things(thing + 2, "C", 3, 2); // density == 5

    int rc = sorted_stuff(thing, n);
    ck_assert_int_eq(rc, OK);
    ck_assert_str_eq(thing->name, "C");
    ck_assert_str_eq((thing + 1)->name, "B");
    free_object(thing, n);
}

Suite* sort_suite(void)
{
    Suite *result;
    TCase *tc_neg;
    TCase *tc_pos;

    result = suite_create("check_sort");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_sort_null_pointer);
    tcase_add_test(tc_neg, test_sort_zero_elem);
    tcase_add_test(tc_neg, test_sort_devide_zero);
    suite_add_tcase(result, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_all_same_density);
    tcase_add_test(tc_pos, test_sort_normal_things);
    suite_add_tcase(result, tc_pos);

    return result;
}