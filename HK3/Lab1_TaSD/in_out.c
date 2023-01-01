#include "header.h"


void print_conditions(void)
{
    printf("Назначение программы: данная программа делит действительное число на действительное.\n\n");

    printf("После приглашения 'Введите 1-го действительное число: ' и 'Введите 2-го действительное число: '\n"
    "введите соответствующие числа в соответствии с указанными ниже форматами и правилами.\n\n"
    "Формат ввода чисел:\n\n");
    printf("Действительное число   +/-m[.nE+/-k]\n"
    "m - целая часть действительного числа\n"
    "n - дробная часть действительного числа\n"
    "k - порядок действительного числа\n\n");
    printf("Правила ввода чисел:\n"
    "* Ввод осуществляется без пробелов\n"
    "* Мантиссы чисел могут состоять только из цифр\n"
    "* Длина мантисс чисел должна быть меньше, либо равна 30 и больше, либо равна 1\n"
    "* Перед каждым числом необходимо ввести знак   '+'/'-'\n"
    "* Дробная часть действительного числа не обязательна\n"
    "* Если у действительного числа вводится дробная часть, то: \n"
    "   * После целой части числа необходимо вводить '.', а затем дрбную часть\n"
    "   * После дробной части числа необходимо вводить 'E' в верхнем регистре\n"
    "   * После 'E' необходимо вводить знак порядка   '+'/'-'\n"
    "   * После знака порядка необходимо вводить порядок числа\n"
    "   * Порядок числа может состоять только из цифр\n"
    "   * Длина порядка числа должна быть меньше, либо равна 5 и больше, либо равна 1\n\n");
}

int input_number(number *real_number)
{
    printf("%s",
        "\n                                    \n"
        "                             1       10        20         31E+-порядок\n"
        "                           +-|........|.........|..........|..|...|\n"
        "Введите вещественное число: ");
    int symbol;
    if ((symbol = getchar()) != '\n')
    {
        if ((symbol == EOF) || (symbol != '+' && symbol != '-'))
        {
            printf("Первым символом действительного числа должен быть знак числа.\n");
            return ERR_NO_SIGN;
        }
        real_number->number_sign = symbol;
    }
    real_number->point_index = NO_POINT;

    int i = 0, pos = 0;

    while ((symbol = getchar()) != 'E')
    {
        if (symbol == ' ')
        {
            printf("Не должно быть пробелов между символами.\n");
            return ERR_SPACES;
        }

        if (symbol == '\n')
        {
            if (i)
            {
                real_number->order_sign = '+';
                real_number->order = 0;
                real_number->mantissa[i] = '\0';
                return OK;
            }
            printf("Необходимо ввести действительное число.\n");
            return ERR_INPUT;
        }
        
        if (symbol == '.')
        {
            if (pos)
            {
                printf("У действительного числа должна быть только одна точка.\n");
                return MORE_ONE_POINT;
            }
            pos = 1;
            real_number->point_index = i;
        }
        else 
        {
            if ((symbol < '0') || (symbol > '9'))
            {
                printf("Мантисса действительного числа должна состоять только из цифр.\n");
                return INCORRECT_SYMBOL; 
            }
        }

        real_number->mantissa[i++] = symbol;

        if ((pos && i > MAX_LEN_MANTISSA + 1) || (pos == 0 && i > MAX_LEN_MANTISSA))
        {
            printf("Длина мантиссы действительного числа должна быть меньше, либо равна 30 и больше 0.\n");
            return ERR_LEN;  
        }
    }
    real_number->mantissa[i] = '\0';

    if ((symbol = getchar()) != '\n')
    {
        if ((symbol == EOF) || (symbol != '+' && symbol != '-'))
        {
            printf("Перед порядком действительного числа должен быть знак порядка.\n");
            return ERR_NO_SIGN;
        }
        real_number->order_sign = symbol;
    }

    i = 0;
    char order[MAX_LEN_ORDER + 2] = {'\0'};

    while ((symbol = getchar()) != '\n')
    {
        if (symbol == ' ')
        {
            printf("Не должно быть пробелов между символами.\n");
            return ERR_SPACES;
        }

        if (symbol < '0' || symbol > '9')
        {
            printf("Порядок действительного числа должен состоять только из цифр.\n");
            return INCORRECT_SYMBOL;   
        }

        if (i >= MAX_LEN_ORDER)
        {
            printf("Длина порядка действительного числа должна быть меньше, либо равна 5 и больше 0.\n");
            return ERR_LEN;
        }

        order[i++] = symbol;
    }
    if (real_number->order_sign == '-')
        real_number->order = -atoi(order);
    else
        real_number->order = atoi(order);
    
    return OK;
}

void output_number(number real_number)
{
    printf("Результат деления: ");

    if (real_number.order > 0)
        printf("%c0.%sE+%d\n", real_number.number_sign, real_number.mantissa + 1, real_number.order);
    else
        printf("%c0.%sE%d\n", real_number.number_sign, real_number.mantissa + 1, real_number.order);
}