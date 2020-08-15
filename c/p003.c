#include "common.h"

static void largest_prime_factor(uint64_t value)
{
    if (value < 2)
        goto end;
    for (uint64_t counter = 2; counter < value; ++counter)
        if (value % counter == 0)
            return largest_prime_factor(value / counter);
end:
    printf("%"PRIu64, value);
}

int main(int argc, char** argv)
{

    ASSERT_ARGUMENTS(argc, argv, 1, "<NUMBER>");

    if (!isNumeric(argv[1], strlen(argv[1])))
        return 1;

    largest_prime_factor(strtoull(argv[1], 0, 10));
    return 0;
}

