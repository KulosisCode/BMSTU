#include "header.h"

void delete_zeros(number *result_number)
{
    int i = strlen(result_number->mantissa) - 1;
    while (result_number->mantissa[i] == '0' && i > 1)
        i--;
    result_number->mantissa[i + 1] = '\0';
}

int compare_characters(char first_char, char second_char)
{
    if (first_char == second_char)
        return EQUAL;
    return NOT_EQUAL;
}

void normalize_number(number *one_number)
{
    int len = strlen(one_number->mantissa);
    int i = 0;
     
    if (one_number->point_index != NO_POINT)
    {
        for (i = one_number->point_index; i < len; i++)
            one_number->mantissa[i] = one_number->mantissa[i + 1];

        one_number->order += -1 * (len - 1 - one_number->point_index);
    }

    if (one_number->point_index != NO_POINT)
        i = len - 1;
    else
        i = len;
    for (; i < MAX_LEN_MANTISSA + 1; i++)
    {
        one_number->mantissa[i] = '0';
        one_number->order--;
    }
    one_number->mantissa[MAX_LEN_MANTISSA + 1] = '\0';
}

void add_zeros(number *one_number)
{
    int len = strlen(one_number->mantissa);
    int i,count = 0;
    char symbol;

    while (one_number->mantissa[0] == '0' && count != len - 1)
    {
        for (i = 0; i < len - 1; i++)
        {
            symbol = one_number->mantissa[i];
            one_number->mantissa[i] = one_number->mantissa[i + 1];
            one_number->mantissa[i + 1] = symbol;
        }
        count++;
        one_number->order--;
    }
    len = strlen(one_number->mantissa);
    for (i = len; i > 0; i--)
        one_number->mantissa[i] = one_number->mantissa[i - 1];
    one_number->mantissa[0] = '0';
    one_number->mantissa[len] = '\0';
}

int compare_numbers(number *first_number, number *second_number)
{
    int len = strlen(first_number->mantissa);
    for (int i = 0; i < len; i++)
    {
        if (first_number->mantissa[i] - second_number->mantissa[i] > 0)
            return MORE;
        else if (first_number->mantissa[i] - second_number->mantissa[i] < 0)
            return LESS;
    }
    return MORE;
}

int compare_zero(number *one_number)
{
    int len = strlen(one_number->mantissa);
    for (int i = 0; i < len; i++)
    {
        if (one_number->mantissa[i] != '0')
            return NOT_EQUAL;
    }
    return EQUAL;
}

void change_zero(number *one_number)
{
    for (int i = 0; i < MAX_LEN_MANTISSA; i++)
        one_number->mantissa[i] = one_number->mantissa[i + 1];
    one_number->mantissa[MAX_LEN_MANTISSA] = '0';
}

int subtraction(number *first_number, number *second_number)
{
    if (compare_numbers(first_number, second_number))
    {
        int  i = strlen(second_number->mantissa) - 1;
        for (;i >= 0; i--)
        {
            if (first_number->mantissa[i] - second_number->mantissa[i] >= 0)
                first_number->mantissa[i] -= second_number->mantissa[i] - '0';
            else
            {
                int j = i - 1;
                while (first_number->mantissa[j] - '0' == 0 && j > 0)
                    j--;
                first_number->mantissa[j++]--;
                for(; j < i; j++)
                    first_number->mantissa[j] += 9;
                first_number->mantissa[i] += 10 - (second_number->mantissa[i] - '0');
            }
        }
        return GO;
    }
    return STOP;
}

int divide_numbers(number *first_number, number *second_number, number *result_number)
{
    if (compare_zero(second_number))
    {
        printf("Нельзя делить на 0.\n");
        return DIVISION_BY_ZERO;
    }

    if (compare_zero(first_number))
        return ZERO;

    if (abs(first_number->order - second_number->order) >= 99999)
    {
        printf("Переполнение порядка.\n");
        return OVERFLOW;
    }

    if (compare_numbers(first_number, second_number) == LESS)
    {
        change_zero(first_number);
        first_number->order--;
    }

    result_number->mantissa[0] = '0';
    int count_digits = 0;

    while (subtraction(first_number, second_number))
        count_digits++;

    change_zero(first_number);

    result_number->mantissa[1] = '0' + count_digits;

    int i;

    for (i= 2; i < MAX_LEN_MANTISSA + 1; i++)
    {
        if (compare_zero(first_number))
        {
            result_number->mantissa[i] = '\0';
            count_digits = 0;
            break;
        }

        if (compare_numbers(first_number, second_number) == LESS)
        {
            change_zero(first_number);
            result_number->mantissa[i] = '0';
        }
        else
        {
            count_digits = 0;

            while (subtraction(first_number, second_number))
                count_digits++;

            change_zero(first_number);
            result_number->mantissa[i] = '0' + count_digits;
        }
    }

    result_number->mantissa[MAX_LEN_MANTISSA + 1] = '\0';

    count_digits = 0;

    while (subtraction(first_number, second_number))
        count_digits++;

    change_zero(first_number);

    if (i == MAX_LEN_MANTISSA + 1 && count_digits >= 5)
        result_number->mantissa[MAX_LEN_MANTISSA] += 1;

    for (; i < MAX_LEN_MANTISSA + 1; i++)
        result_number->mantissa[i] = '0';

    result_number->mantissa[MAX_LEN_MANTISSA + 1] = '\0';

    int remainder = 0;

    for (i = MAX_LEN_MANTISSA; i >= 0; i--)
    {
        result_number->mantissa[i] += remainder;

        if (result_number->mantissa[i] == ':')
        {
            result_number->mantissa[i] = '0';
            remainder = 1;
        }
        else
            break;
    }

    if (result_number->mantissa[0] == '1')
    {
        for (i = MAX_LEN_MANTISSA; i > 0; i--)
            result_number->mantissa[i] = result_number->mantissa[i - 1];

        result_number->mantissa[0] = '0';
    }
    else
        remainder = 0;

    result_number->mantissa[MAX_LEN_MANTISSA + 1] = '\0';

    result_number->order = first_number->order - second_number->order + remainder + 1;

    if (compare_characters(first_number->number_sign, second_number->number_sign))
        result_number->number_sign = '+';
    else
        result_number->number_sign = '-';
    
    return OK;
}