#include "common.h"


static inline int32_t createChain(uint32_t start, uint32_t counter)
{
    if (start == 1)
        return counter + 1;
    return createChain(start % 2 == 0 ? start / 2 : 3 * start + 1, counter + 1);
}

static uint32_t maxChain(uint32_t limit)
{
    uint32_t ret = 0, maxChain = 0;
    while (--limit)
    {
        uint32_t chainLength = createChain(limit, 0);
        if (chainLength > maxChain) {
            ret = limit;
            maxChain = chainLength;
        }
    }
    return ret;
}


int main()
{
    printf("Result: %u", maxChain(1000000));
    return 0;
}
