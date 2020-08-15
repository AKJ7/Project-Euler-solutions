#include "common.h"

int digits[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
int tenth[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int tenths[] = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};

uint64_t getCount(uint64_t value)
{
    if (value < 10) {
        return digits[value];
    } else if (value < 20) {
        return tenth[value % 10];
    } else if (value < 100) {
        return tenths[value / 10] + getCount(value % 10);
    } else if (value < 1000){
        return digits[value / 100] + (value % 100 == 0 ? getCount(value % 100) + 7 : getCount(value % 100) + 10);
    } else {
        return digits[value / 1000] + getCount(value % 1000) + 8;
    }
}


int main(int argc, char** argv)
{
    ASSERT_ARGUMENTS(argc, argv, 1, "<MAX_VALUE>");
    assert(isNumeric(argv[1], strlen(argv[1])));
    uint64_t value = strtoul(argv[1], 0, 10);
    assert(value < 10000);
    uint64_t retVal = 0;
    for (uint64_t counter = 0; counter <= value; ++counter)
        retVal += getCount(counter);
    printf("%" PRIu64, retVal);

    return 0;
}
