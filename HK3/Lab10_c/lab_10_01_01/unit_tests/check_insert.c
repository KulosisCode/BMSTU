#include "check_main.h"

START_TEST(test_insert_null_head)
{
    // int *x = malloc(sizeof(int));
    // int *y = malloc(sizeof(int));
    int x = 5;
    int y = 7;

    node_t elem = { &x, NULL};
    node_t before = { &y, NULL};
    node_t *head = NULL;

    insert(&head, &elem, &before);
    ck_assert_ptr_null(head);
    ck_assert_ptr_null(elem.next);
}
END_TEST

START_TEST(test_insert_null_element)
{
    // int *x = malloc(sizeof(int));
    // int *y = malloc(sizeof(int));
    // *x = 5, *y = 7;
    int x = 5;
    int y = 7;

    node_t before = { &y, NULL};
    node_t node = { &x, &(before)};
    node_t *head = &node;
    node_t *elem = NULL;

    insert(&head, elem, &before);
    ck_assert_ptr_null(elem);
    ck_assert_ptr_eq(&before, head->next);
}

START_TEST(test_insert_before_not_found)
{
    int x = 5, y = 8, z = 10, q = 1;
    node_t before = { &x, NULL};
    node_t node_2 = { &y, NULL};
    node_t node_1 = { &z, &node_2};
    node_t elem = {&q, NULL};
    node_t *head = &node_1;

    insert(&head, &elem, &before);
    ck_assert_ptr_eq(head, &node_1);
    ck_assert_ptr_eq(head->next, &node_2);
    ck_assert_ptr_null((head->next)->next);
    ck_assert_ptr_null(elem.next);
}

START_TEST(test_insert_at_begin)
{
    int x = 5, y = 8, q = 1;
    node_t node_2 = { &y, NULL};
    node_t node_1 = { &x, &node_2};
    node_t elem = {&q, NULL};
    node_t *head = &node_1;

    insert(&head, &elem, &node_1);
    ck_assert_ptr_eq(head, &elem);
    ck_assert_ptr_eq(head->next, &node_1);
}
END_TEST

START_TEST(test_insert_normal)
{
    int x = 5, y = 8, q = 1;
    node_t node_2 = { &y, NULL};
    node_t node_1 = { &x, &node_2};
    node_t elem = {&q, NULL};
    node_t *head = &node_1;

    insert(&head, &elem, &node_2);
    ck_assert_ptr_eq(head, &node_1);
    ck_assert_ptr_eq(head->next, &elem);
    ck_assert_ptr_eq((head->next)->next, &node_2);
}
END_TEST

START_TEST(test_insert_at_end)
{
    int x = 5, y = 8, q = 1;
    node_t node_2 = { &y, NULL};
    node_t node_1 = { &x, &node_2};
    node_t elem = { &q, NULL};
    node_t *head = &node_1;

    insert(&head, &elem, NULL);
    ck_assert_ptr_eq(head, &node_1);
    ck_assert_ptr_null(elem.next);
    ck_assert_ptr_eq((head->next)->next, &elem);
}

Suite* insert_suite(void)
{
    Suite *result;
    TCase *neg, *pos;

    result = suite_create("check insert");

    neg = tcase_create("negatives");
    tcase_add_test(neg, test_insert_null_head);
    tcase_add_test(neg, test_insert_null_element);
    tcase_add_test(neg, test_insert_before_not_found);
    suite_add_tcase(result, neg);

    pos = tcase_create("positives");
    tcase_add_test(pos, test_insert_at_begin);
    tcase_add_test(pos, test_insert_normal);
    tcase_add_test(pos, test_insert_at_end);
    suite_add_tcase(result, pos);
    return result;
}