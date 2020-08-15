#include "common.h"

typedef struct pythagorean_s
{
    uint32_t a, b, c;
} pythagorean_t;

static inline pythagorean_t find_pythagore(uint32_t max)
{
    pythagorean_t ret = {};
    uint32_t middleSum = (max*max) / 2;
    for (ret.b = 1; ret.b < max; ++ret.b)
        for (ret.a = 1; ret.a < ret.b; ++ret.a) 
            if ((max * (ret.a + ret.b) - (ret.a * ret.b)) == middleSum)
                return ret.c = max - (ret.a + ret.b), ret;
    return ret;
}

static uint64_t find_product(const pythagorean_t* p)
{
    return p->a * p->b * p->c;
}


int main(int argc, char** argv)
{
    ASSERT_ARGUMENTS(argc, argv, 1, "<SUM_OF_ABC>");
    assert(isIntegral(argv[1], strlen(argv[1])));
    pythagorean_t p = find_pythagore(strtoul(argv[1], 0, 10));
    // printf("(a, b, c) = (%"PRIu32", %"PRIu32", %"PRIu32")\n", p.a, p.b, p.c);
    printf("%"PRIu64, find_product(&p));
    return 0;
}

