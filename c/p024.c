#include "common.h"


static uint32_t nthPermutatition(uint32_t n)
{
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    n <<= (sizeof(n) * CHAR_BIT - 10 - 1);

    
   
printf("%u\n", n);


    uint32_t retVal = 0;
    for (unsigned counter = 0, size = sizeof(values) / sizeof(*values) - 1; counter <= size; ++counter)
         retVal += values[size - counter] * pow(10, counter);
    return retVal;
}


int main(void)
{
    printf("%"PRIu32, nthPermutatition(1000000));

    return 0;
}
