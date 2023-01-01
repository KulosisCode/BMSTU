#include "header.h"

node_t *create_node(const int elem)
{
    node_t *node = malloc(sizeof(node_t));
    if (node)
    {
        node->elem = elem;
        node->next = NULL;
    }
    return node;
}

int list_queue_add(list_queue_t *list, int elem)
{
    if (list->len == MAX_ELEM)
        return ERR_OVER_FLOW;

    node_t *node = list->last;
    node->elem = elem;

    list->last = create_node(ZERO);
    node->next = list->last;
    list->len++;
    return OK;
}


int list_queue_pop(list_queue_t *list)
{
    if (list->len == 0)
        return 1;

    node_t *node = list->head->next;
    int elem = node->elem;
    list->head->next = node->next;

    list->len--;
    free(node);
    return elem;
}


void print_list(list_queue_t list)
{
    printf("\nLIST QUEUE:\n");

    for (node_t *i = list.head->next; i != list.last; i = i->next)
    {
        size_t locate = (size_t)i;
        printf("Element: %d  Address: %zx\n", i->elem, locate);
    }
}


void print_address_free(size_t *free_elem, int n)
{
    if (n == 0)
        return;

    printf("\nFree addresses: \n");
    for (int i = 0; i < n; i++)
        printf("Address: %zx\n", free_elem[i]);
}


void free_list(list_queue_t *list)
{
    while (list->len > 0)
        list_queue_pop(list);

    free(list->head);
    list->head = NULL;

    free(list->last);
    list->last = NULL;
}


void list_queue_process(void)
{
    srand(time(NULL));
    list_queue_t list;
    list.head = malloc(sizeof(node_t));
    list.last = malloc(sizeof(node_t));
    list.head->next = list.last;
    list.head->elem = ZERO;
    list.last->next = NULL;
    list.last->elem = ZERO;
    list.len = 0;

    float input_t1 = 0.0;
    float input_t2 = 6.0;
    float input_time = (input_t2 - input_t1) * (float)(TIME) + input_t1;

    float process_t1 = 0.0;
    float process_t2 = 1.0;
    float process_time = (process_t2 - process_t1) * (float)(TIME) + process_t1;

    double wait_time = 0;
    double real_time = 0;

    int count_input = 0;
    int count_return  = 0;
    int count_out = 0;
    int count_out_away = 0;

    int count_add = 0;
    int flag = 0;
    int len = 0;

    while (count_out_away < MAX_ELEM)
    {
        if ((count_out_away) % 100 == 0 && count_out_away != 0 && flag == 0)
        {
            printf("Current queue length: %d\n", list.len);
            printf("Average queue length: %f\n\n", (float)len / count_add);
            flag = 1;
        }

        if (process_time - input_time > 0)
        {
            process_time -= input_time;
            list_queue_add(&list, NUMBER);

            count_input++;

            real_time += input_time;

            get_time(&input_time, input_t1, input_t2);
        }
        else if (list.len != 0)
        {
            input_time -= process_time;
            list_queue_pop(&list);

            count_out++;

            if (CHANCE_RETURN < 0.8 + EPS)
            {
                list_queue_add(&list, NUMBER);
                count_input++;
                count_return++;
            }
            else
            {
                count_out_away++;
                flag = 0;
            }
            real_time += process_time;
            get_time(&process_time, process_t1, process_t2);
        }
        else
        {
            input_time -= process_time;
            wait_time += process_time;
            get_time(&process_time, process_t1, process_t2);

        }
        len += list.len;
        count_add++;
    }
    real_time += wait_time;

    printf("Ожидаемое время моделирования: 3000 е.в.\n");
    printf("Общее время моделирования: %f е.в.\n\n", real_time);

    printf("Количество вошедших заявок: %d, из них повторно возвращенные заявки: %d\n", count_input, count_return);
    printf("Количество вышедших заявок: %d, из них не вернувшихся обратно: %d\n\n", count_out, count_out_away);

    printf("Время среднего пребывания заявки в очереди: %f е.в.\n", real_time/count_out * (float)len / count_add);
    
    printf("Ожидаемое время простоя: 500 е.в\n");
    printf("Время простоя аппарата: %f е.в.\n\n", wait_time);

    printf("Количество cрабатываний ОА: %d\n\n", count_out);

    printf("Погрешность по вошедшим заявкам: %f%%\n", 100 * fabs(((count_input - count_return - real_time / 3) / (real_time / 3))));
    printf("Погрешность по вышедшим заявкам: %f%%\n\n", 100 * fabs((real_time - 3000) / 3000));
}