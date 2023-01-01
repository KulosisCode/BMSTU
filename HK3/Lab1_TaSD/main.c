#include "header.h"


int main(void)
{
    setbuf(stdout, NULL);
    print_conditions();

    number first_number, second_number, result_number;
    int rc;

    rc = input_number(&first_number);
    if (rc != OK)
        return rc;
    rc = input_number(&second_number);
    if (rc != OK)
        return rc;
    if (abs(first_number.order - second_number.order) >= 99999)
    {
        printf("Переполнение порядка.\n");
        return OVERFLOW;
    }
    normalize_number(&first_number);
    normalize_number(&second_number);

    add_zeros(&first_number);
    add_zeros(&second_number);

    rc = divide_numbers(&first_number, &second_number, &result_number);

    if (rc == ZERO)
    {
        printf("Результат деления: +0.0E+0\n");
        return OK;
    }
    else if (rc != OK)
        return rc;   

    delete_zeros(&result_number);

    output_number(result_number);

    return OK;
}