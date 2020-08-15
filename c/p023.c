#include "common.h"

#define LIMIT 28123


static inline int isAbundant(uint32_t value) {
    uint32_t sum = 1, end = sqrt(value);
    for (uint32_t i = 2; i <= end; ++i) 
        if (value % i == 0)
            sum += i + value / i;
    if (end * end == value)
        sum -= end;
    return sum > value ? 1 : -1;
}

static inline int isAbundantOrSetAbundance(uint32_t value, uint32_t* cache)
{
    if (!cache[value])
        cache[value] = isAbundant(value);
    return cache[value];
}

static inline int isSumOfAbundance(uint32_t value, uint32_t* cache)
{
    for (uint32_t counter = 0; counter <= value; ++counter)
        if (isAbundantOrSetAbundance(counter, cache) == 1 && isAbundantOrSetAbundance(value - counter, cache) == 1)
            return 1;
    return 0;
}

static uint32_t notSum(void)
{
    uint32_t retVal = 0;
    uint32_t cache[LIMIT + 1] = {-1};
    for (uint32_t counter = 1; counter <= LIMIT; ++counter)
        if (!isSumOfAbundance(counter, cache))
            retVal += counter;
    return retVal;
}


int main(int argc, char** argv)
{
    printf("%" PRIu32, notSum());
    return 0;
}

#undef LIMIT
