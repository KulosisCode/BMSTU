#include "header.h"

int my_strlen(const char *s)
{
    if (s == NULL)
        return NONE;
    int count = 0;
    while (s[count] != '\0')
        count++;
    return count;
}


int get_type_format(const char *s, int ind)
{
    if (s[ind] != '%')
        return NONE;
    if (s[ind + 1] == '\0' || s[ind + 1] == ' ')
        return NONE;
    if  (s[ind + 1] == 's')
        return FORMAT_S;
    else if ((s[ind + 1] == 'h') && (s[ind + 2] == 'x'))
        return FORMAT_HX;
    else 
        return NONE;
}

int my_snprintf(char *restrict s, int n, const char *restrict format, ...)
{
    int type = 0;
    int remain = n;
    int buff_count = 0;
    int format_len =  my_strlen(format);
    int able_all = 0;

    if (n < 0)
        return ERR;

    va_list vl;
    va_start(vl, format);
    for (int i = 0; i < format_len; i++)
    {
        if (format[i] == '%')
        {
            type = get_type_format(format, i);
            if (type == FORMAT_S)
            {
                write_s_type(s, &buff_count, va_arg(vl, char *), &remain, &able_all);
                i++;
            }
            else if (type == FORMAT_HX)
            {
                write_x_type(s, &buff_count, va_arg(vl, int), &remain, &able_all);
                i += 2;
            }
            else if (type == NONE)
                return ERR;
        }
        else 
            write_c_type(s, &buff_count, format[i], &remain, &able_all);
    }
    va_end(vl);

    if (n > 0)
    {
        if (able_all >= n - 1)
        {
            s[n - 1] = '\0';
        }
        else
        {
            s[able_all] = '\0';
        }
    }

    return able_all;
}


void write_c_type(char *buff, int *buff_count, char c, int *remain, int *able_all)
{
    (*able_all)++;
    if (*remain <= 1)
        return;
    buff[*buff_count] = c;
    (*buff_count)++;
    (*remain)--;
}

void write_s_type(char *buff, int *buff_count, char *s, int *remain, int *able_all)
{
    for (; *s; s++)
    {
        char ch = *s;
        write_c_type(buff, buff_count, ch, remain, able_all);
    }
}

void write_x_type(char *buff, int *buff_count, int x, int *remain, int *able_all)
{
    char *str;
    int len;
    str = from_int_to_16(x, &len);
    for (int i = 0; i < len; i++)
        write_c_type(buff, buff_count, str[i], remain, able_all);
    free(str);
}

char digit_to_char(int num)
{
    if (num > 16 || num < 0)
        return END;
    if (num <= 9)
        return (char)(num + 48);
    else
        return (char)(num + 87);
}

char *from_int_to_16(uint16_t num, int *len)
{
    int count  = get_length(num, 16);
    *len = count;
    char *cur = malloc(count * sizeof(char) + 1);
    if (!cur)
        return NULL;
    for (int i = count - 1; i >= 0; i--)
    {
        int ele = num % 16;
        cur[i] = digit_to_char(ele);
        num /= 16;
    }
    cur[count] = '\0';
    return cur;
}

int get_length(int num, int base)
{
    int length = 0;

    while (num)
    {
        num /= base;
        length++;
    }
    if (length == 0)
        length = 1;
    return length;
}

int my_strcmp(char *s1, char *s2)
{
    if (!s1 || !s2)
        return FAIL;
    int len_1 = my_strlen(s1);
    int len_2 = my_strlen(s2);
    if (len_1 != len_2)
        return FAIL;
    for (int i = 0; i < len_1; i++)
    {
        if (s1[i] != s2[i])
            return FAIL;
    }
    return OK;
}