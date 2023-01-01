#include "header.h"

int array_queue_add(array_queue_t *array, int elem)
{
    if ((array->head == array->last + 1) || (array->head == 0 && array->last == MAX_ELEM - 1))
        return ERR_OVER_FLOW;

    if (array->head == -1)
        array->head = 0;
    array->last = (array->last + 1) % MAX_ELEM;
    array->queue[array->last] = elem;
    array->len++;
    return OK;
}

int array_queue_pop(array_queue_t *array)
{
    if (array->head == -1)
        return 0;
    if (array->head == array->last)
    {
        int elem = array->queue[array->head];
        array->head = -1;
        array->last = -1;
        array->len--;
        return elem;
    }

    int elem = array->queue[array->head];
    array->head = (array->head + 1) % MAX_ELEM;
    array->len--;
    return elem;
}

void print_array_queue(array_queue_t array)
{
    printf ("\nARRAY QUEUE\n");

    for (int i = array.head; i <= array.last; i++)
        printf("Element : %d\n", array.queue[i]);
}

void array_queue_process(void)
{
    srand(time(NULL));
    array_queue_t array;
    array.head = -1;
    array.last = -1;
    array.len = 0;

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

    int flag = 0;
    int len = 0;
    int count_add = 0;

    while (count_out_away < MAX_ELEM)
    {
        if ((count_out_away) % 100 == 0 && count_out_away != 0 && flag == 0)
        {
            printf("Current queue length: %d\n", array.len);
            printf("Average queue length: %f\n\n", (float)len / count_add);
            flag = 1;
        }

        if (process_time - input_time > 0)
        {
            process_time -= input_time;
            array_queue_add(&array, NUMBER);

            count_input++;

            real_time += input_time;
            get_time(&input_time, input_t1, input_t2);
        }
        else if (array.head != -1)
        {
            input_time -= process_time;
            array_queue_pop(&array);

            count_out++;

            if (CHANCE_RETURN < 0.8 + EPS)
            {
                array_queue_add(&array, NUMBER);
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
        len += array.len;
        count_add++;
    }
    real_time += wait_time;
    
    printf("Ожидаемое время моделирования: 3000 е.в.\n");
    printf("Общее время моделирования: %f е.в.\n\n", real_time);

    printf("Количество вошедших заявок: %d, из них повторно возвращенные заявки: %d\n", count_input, count_return);
    printf("Количество вышедших заявок: %d, из них не вернувшихся обратно: %d\n\n", count_out, count_out_away);

    printf("Время среднего пребывания заявки в очереди: %f е.в.\n", real_time / count_out * (float)len / count_add);
    
    printf("Ожидаемое время простоя: 500 е.в\n");
    printf("Время простоя аппарата: %f е.в.\n\n", wait_time);

    printf("Количество cрабатываний ОА: %d\n\n", count_out);

    printf("Погрешность по вошедшим заявкам: %f%%\n", 100 * fabs(((count_input - count_return - real_time/3) / (real_time/3))));
    printf("Погрешность по вышедшим заявкам: %f%%\n\n", 100 * fabs((real_time - 3000)/3000));
}