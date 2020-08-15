#include "common.h"


static inline uint64_t n_teTriangle(uint32_t n)
{
    return n*(n + 1) / 2;
}

static uint32_t totalDivisors(uint64_t tri)
{
    uint32_t retVal = 0;
    for (uint64_t counter = 1; counter <= tri; ++counter)
        retVal += !(tri % counter);
//    printf("Total: %u, Tri: %lu\n", retVal, tri);
    return retVal;
}

static uint64_t triangleNumberWithOverNDivisors(uint32_t n)
{
    uint64_t retVal;
    for (retVal = 1; totalDivisors(n_teTriangle(retVal)) <= n; ++retVal);
    return n_teTriangle(retVal);
}


int main(int argc, char** argv)
{
    ASSERT_ARGUMENTS(argc, argv, 1, "<TOTAL_DIVISORS>");
    assert(isIntegral(argv[1], strlen(argv[1])));
    printf("%"PRIu64, triangleNumberWithOverNDivisors(strtoul(argv[1], 0, 10)));
    return 0;
}
