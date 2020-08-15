#include "common.h"

static inline uint64_t sumOfSquare(uint32_t limit)
{
    return limit*(limit + 1)*(2* limit + 1) / 6;
}

static inline uint64_t squareOfSum(uint32_t limit)
{
    uint64_t sum = limit*(limit + 1) / 2;
    return sum * sum;
}


static uint64_t difference(uint32_t limit)
{
    return squareOfSum(limit) - sumOfSquare(limit);
}

int main(int argc, char** argv)
{
    ASSERT_ARGUMENTS(argc, argv, 1, "<MAX>");
    assert(isIntegral(argv[1], strlen(argv[1])));
    printf("%"PRIu64, difference(strtoul(argv[1], 0, 10)));
    return 0;
}

