#include "common.h"


uint32_t getTotalSundays(uint32_t day, uint32_t month, uint32_t year)
{
    const uint16_t days1[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    const uint16_t days2[] = {0, 31, 60, 91, 130, 152, 182, 213, 244, 274, 305, 335, 366};
    uint32_t retVal = 0;
    uint32_t currentDay = 0;
    const uint16_t* ptr = 0;
    for (uint32_t counter = 1901; counter <= year; ++counter) {
        ptr = (counter % 4 == 0 && counter % 400 != 0 ? days2 : days1);
        for (unsigned i = 1; i <= 12; i++) {
            retVal += (currentDay == 5); // 01.01.1901 Starts on a Tuesday, so Sunday 7 = 2 + 5
            currentDay = (currentDay + ptr[i]) % 7;
        }
    }
    return retVal;
}


int main(int argc, char** argv)
{
    printf("%" PRIu32, getTotalSundays(0, 0, 2000));
    return 0;
}
