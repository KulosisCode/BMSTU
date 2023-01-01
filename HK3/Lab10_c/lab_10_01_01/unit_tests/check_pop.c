#include "check_main.h"

START_TEST(test_pop_null_poiter)
{
    node_t **head = NULL;
    void *data = NULL;

    data  = pop_front(head);
    ck_assert_ptr_null(head);
    ck_assert_ptr_null(data);
}
END_TEST

START_TEST(test_pop_null_list)
{
    node_t *head = NULL;
    void *data = NULL;

    data = pop_front(&head);
    ck_assert_ptr_null(head);
    ck_assert_ptr_null(data);
}
END_TEST

START_TEST(test_pop_data_null)
{
    node_t *head = malloc(sizeof(node_t));
    head->data = NULL;
    head->next = NULL;
    void *data = NULL;

    data = pop_front(&head);
    ck_assert_ptr_null(head);
    ck_assert_ptr_null(data);
    free_all_list(head);
}
END_TEST

START_TEST(test_pop_1_elem_list)
{
    node_t *head = NULL;
    void *data = NULL;
    // 1
    int arr[1] = { 1 };
    node_t *node = malloc(sizeof(node_t));
    node->data = arr;
    node->next = NULL;
    head = node;
    
    data = pop_front(&head);
    ck_assert_ptr_null(head);
    ck_assert_int_eq(1, *(int *)data);
    free_all_list(head);
}
END_TEST

START_TEST(test_pop_normal_list)
{
    node_t *head = NULL;
    void *data = NULL;
    // 1 2 5 3 4
    int arr[5] = {1, 2, 5, 3, 4};
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

    data = pop_front(&head);
    ck_assert_int_eq(1, *(int *)data);
    ck_assert_int_eq(2, *(int *)head->data);
    free_all_list(head);
}
END_TEST

Suite* pop_front_suite(void)
{
    Suite *result;
    TCase *neg, *pos;

    result = suite_create("check pop_front");

    neg = tcase_create("negatives");
    tcase_add_test(neg, test_pop_null_poiter);
    tcase_add_test(neg, test_pop_null_list);
    tcase_add_test(neg, test_pop_data_null);
    suite_add_tcase(result, neg);

    pos = tcase_create("positives");
    tcase_add_test(pos, test_pop_1_elem_list);
    tcase_add_test(pos, test_pop_normal_list);
    suite_add_tcase(result, pos);

    return result;
}