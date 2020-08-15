#include "common.h"


static uint32_t stringPower(unsigned base, unsigned power)
{
    if (!power) {
        putc('1', stdout);
        return 1;
    }
    
    unsigned temp = base;
    unsigned buffer[1280];
    size_t length = 0;
    while (temp)
    {
        buffer[length++] = temp % 10;
        temp /= 10;
    }
    for (unsigned counter = 1; counter < power; ++counter)
    {
        length = string_multiply_int(base, buffer, length);
    }
    uint32_t retVal = 0;
    while (length--)
    {
        retVal += buffer[length];
    }
    return retVal;
}


int main(int argc, char** argv)
{
    printf("%"PRIu32, stringPower(2, 1000));
    return 0;
}
