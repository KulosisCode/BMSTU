#include "check_main.h"

START_TEST(test_sort_empty)
{
    node_t *head = NULL;

    head = sort(head, comparator);

    ck_assert_ptr_null(head);
}
END_TEST

START_TEST(test_sort_1_elem)
{
    node_t *head = NULL;
    // 1
    int arr[1] = {1};
    node_t node = { arr, NULL};
    head = &node;

    head = sort(head, comparator);
    ck_assert_int_eq(1, *(int *)head->data);
}
END_TEST

START_TEST(test_sort_all_same)
{
    node_t *head = NULL;
    node_t *node = NULL;
    // 1 1 1 1 1
    int arr[4] = {1, 1, 1, 1};
    node_t node_4 = { arr + 3, NULL};
    node_t node_3 = { arr + 2, &node_4};
    node_t node_2 = { arr + 1, &node_3};
    node_t node_1 = { arr, &node_2};

    head = &node_1;
    head = sort(head, comparator);
    ck_assert_int_eq(1, *(int *)head->data);
    node = head->next;
    ck_assert_int_eq(1, *(int *)node->data);
}
END_TEST

START_TEST(test_sort_normal)
{
    node_t *head = NULL;
    node_t *node = NULL;
    // 1 2 5 3 4
    int arr[5] = {1, 2, 5, 3, 4};
    node_t node_5 = { arr + 4, NULL};
    node_t node_4 = { arr + 3, &node_5};
    node_t node_3 = { arr + 2, &node_4};
    node_t node_2 = { arr + 1, &node_3};
    node_t node_1 = { arr, &node_2};
    head = &node_1;

    head = sort(head, comparator);
    ck_assert_int_eq(1, *(int *)head->data);
    node = head->next;
    ck_assert_int_eq(2, *(int *)node->data);
    node = node->next;
    ck_assert_int_eq(3, *(int *)node->data);
    node = node->next;
    ck_assert_int_eq(4, *(int *)node->data);
    node = node->next;
    ck_assert_int_eq(5, *(int *)node->data);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *result;
    TCase *neg, *pos;

    result = suite_create("check sort");

    neg = tcase_create("negatives");
    tcase_add_test(neg, test_sort_empty);
    suite_add_tcase(result, neg);

    pos = tcase_create("positives");
    tcase_add_test(pos, test_sort_1_elem);
    tcase_add_test(pos, test_sort_all_same);
    tcase_add_test(pos, test_sort_normal);
    suite_add_tcase(result, pos);
    return result;
}