#include "common.h"

static inline uint32_t getSum(uint32_t value)
{
    uint32_t retVal = 0;
    for (uint32_t counter = 1; counter < value; ++counter)
        if (value % counter == 0)
            retVal += counter;
    return retVal;
}

static uint32_t totalAmicable(uint32_t max)
{
    uint32_t retVal = 0, v = 0;
    for (uint32_t counter = 1; counter < max; ++counter)
        if (getSum(v = getSum(counter)) == counter && v != counter)
            retVal += counter;
    return retVal;
}


int main(int argc, char** argv)
{
    printf("%"PRIu32, totalAmicable(10000));

    return 0;
}
