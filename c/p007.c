#include "common.h"

static uint32_t expected = 0;
static uint32_t counter = 0;

static bool nthPrimeCallback(uint64_t prime)
{
    return ++counter == expected;
}

static uint64_t nthPrime(uint32_t n)
{
    assert(n > 1);
    uint64_t max = 100;
    uint64_t ret = 0;
    expected = n;
    do {
        max *= 2;
        counter = 0;
    } while((ret = sieveOfErastosthenes(max, nthPrimeCallback)) == 0);
   return ret; 
}

int main(int argc, char** argv)
{
    ASSERT_ARGUMENTS(argc, argv, 1, "<Nth PRIME>");
    assert(isIntegral(argv[1], strlen(argv[1])));
    printf("%"PRIu64, nthPrime(strtoul(argv[1], 0, 10)));
    return 0;
}
