#include "international_7equeence.h"

long long sequence_game(int array[])
{
    long long product, max_product;
    int i, low_pos, high_pos;
    product = max_product = 1;
    low_pos = 0;
    high_pos = 12;
    while(high_pos < 1000)
    {
        for(i = 0; i < 13; i++)
            product *= array[low_pos + i];           
        if (low_pos == 0)
            max_product = product;
        else if (max_product < product)    
            max_product = product;
        product = 1;
        low_pos++;
        high_pos++;
    }
    return max_product;
}