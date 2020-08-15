#include "common.h"

uint32_t sumFactorial(unsigned x)
{
    if (x <= 1)
        return 1;
    size_t length = 0;
    unsigned buffer[1000];
    unsigned a = x;
    while (a)
    {
        buffer[length++] = a % 10;
        a /= 10;
    }
    for (unsigned counter = x - 1; counter > 0; --counter)
    {
        length = string_multiply_int(counter, buffer, length);
    }
    uint32_t retVal = 0;
    while (length--)
        retVal += buffer[length];
    return retVal;
}



int main()
{
    printf("%"PRIu32, sumFactorial(100));

    return 0;
}
