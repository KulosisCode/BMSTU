#include "check_main.h"

START_TEST(test_remove_dup_ptr_null)
{
    node_t **head = NULL;

    remove_duplicates(head, comparator);

    ck_assert_ptr_null(head);
}
END_TEST

START_TEST(test_remove_dup_empty)
{
    node_t *head = NULL;

    remove_duplicates(&head, comparator);

    ck_assert_ptr_null(head);
}
END_TEST

START_TEST(test_remove_dup_1_ele)
{
    int arr[1] = {10};
    node_t node = { arr, NULL};
    node_t *head = &node;

    remove_duplicates(&head, comparator);

    ck_assert_int_eq(10, *(int *)head->data);
    ck_assert_ptr_null(head->next);
}
END_TEST

START_TEST(test_remove_dup_normal)
{
    node_t *head = NULL;
    node_t *node = NULL;
    // 3 2 2 1 1
    int arr[5] = {3, 2, 2, 1, 1};
    node_t *node_5 = malloc(sizeof(node_t));
    node_5->data = arr + 4;
    node_5->next = NULL;
    node_t *node_4 = malloc(sizeof(node_t));
    node_4->data = arr + 3;
    node_4->next = node_5;
    node_t *node_3 = malloc(sizeof(node_t));
    node_3->data = arr + 2;
    node_3->next = node_4;
    node_t *node_2 = malloc(sizeof(node_t));
    node_2->data = arr + 1;
    node_2->next = node_3;
    node_t *node_1 = malloc(sizeof(node_t));
    node_1->data = arr;
    node_1->next = node_2;
    head = node_1;

    remove_duplicates(&head, comparator);
    node = head;
    ck_assert_int_eq(3, *(int *)node->data);
    node = node->next;
    ck_assert_int_eq(2, *(int *)node->data);
    node = node->next;
    ck_assert_int_eq(1, *(int *)node->data);
    node = node->next;
    ck_assert_ptr_null(node);
    free_all_list(head);
}
END_TEST

Suite *rm_dup_suite(void)
{
    Suite *result;
    TCase *neg, *pos;

    result = suite_create("check rm_dup");

    neg = tcase_create("negatives");
    tcase_add_test(neg, test_remove_dup_ptr_null);
    tcase_add_test(neg, test_remove_dup_empty);
    suite_add_tcase(result, neg);

    pos = tcase_create("positives");
    tcase_add_test(pos, test_remove_dup_1_ele);
    tcase_add_test(pos, test_remove_dup_normal);
    suite_add_tcase(result, pos);
    return result;
}