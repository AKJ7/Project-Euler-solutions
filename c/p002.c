#include <stdio.h>
#include <stdint.h>
#include <stddef.h>


size_t getSumEvenFibo(size_t max)
{
    size_t retVal = 0;

    size_t last = 0;
    size_t temp = 0;

    for (size_t i = 1; i < max;)
    {
        temp = i;
        i = i + last;
        if (i % 2 == 0)
            retVal += i;
        last = temp;
    }
    return retVal;
}

int main() 
{

    printf("%zu\n", getSumEvenFibo(4000000));

    return 0;
}
