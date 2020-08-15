#include "common.h"

static inline uint8_t isPalindrome(uint32_t value)
{
    uint8_t digits[20] = {};
    uint8_t total = ultoa(value, digits);
    for (uint8_t counter = 0; counter < total / 2; ++counter)
        if (digits[counter] != digits[total - counter - 1])
            return 0;
    return 1;
}

static void find_palindrome(uint32_t min, uint32_t max)
{
    uint32_t ret = 0;
    for (uint32_t m1 = max; m1 >= min; --m1) {
        for (uint32_t m2 = max; m2 >= min; --m2) {
            uint32_t mult  = m1 * m2;
            if (isPalindrome(mult) && mult > ret)
                ret = mult;
        }
    }
    printf("%" PRIu32, ret);
}

int main(int argc, char** argv)
{
    ASSERT_ARGUMENTS(argc, argv, 2, "<MIN> <MAX>");
    assert(isIntegral(argv[1], strlen(argv[1])));
    assert(isIntegral(argv[2], strlen(argv[2])));
    find_palindrome(strtoul(argv[1], 0, 10), strtoul(argv[2], 0, 10));
    return 0;
}
