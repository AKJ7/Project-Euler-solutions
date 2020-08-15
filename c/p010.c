#include "common.h"

static uint64_t result = 0;

static bool summer(uint64_t prime)
{
    result += prime;
    return false;
}

static void sum_primes(uint32_t max)
{
    sieveOfErastosthenes(max, summer);
}

int main(int argc, char** argv)
{
    ASSERT_ARGUMENTS(argc, argv, 1, "<LIMIT>");
    assert(isIntegral(argv[1], strlen(argv[1])));
    sum_primes(strtoul(argv[1], 0, 10));
    printf("%"PRIu64, result);
    return 0;
}
