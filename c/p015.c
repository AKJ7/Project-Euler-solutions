#include "common.h"

static uint64_t totalLaticePaths(uint32_t squareLength)
{
    return binom(2*squareLength, squareLength);
}


int main(int argc, char** argv)
{
    ASSERT_ARGUMENTS(argc, argv, 1, "<SQUARE_LENGTH>");
    assert(isIntegral(argv[1], strlen(argv[1])));
//    printf("%"PRIu64, totalLaticePaths(strtoul(argv[1], 0, 10)));
    uint32_t val = strtoul(argv[1], 0, 10);
    printf("%"PRIu64, binom(2 * val, val));
    return 0;
}
