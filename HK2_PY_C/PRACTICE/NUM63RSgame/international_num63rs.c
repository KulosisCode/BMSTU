#include "international_num63rs.h"

int numbers_game(int min, int max)
{
    int number = max;
    int temp_a, temp_b, prevB;
    for (int i = max - 1; i >= min; --i)
    {
        temp_a = number;
        temp_b = i;
        while (temp_b)
        {
            prevB = temp_b;
            temp_b = temp_a % temp_b;
            temp_a = prevB;
        }
        number *= (i / temp_a);
    }
    return number;
}