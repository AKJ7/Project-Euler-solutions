#ifndef PROJECT_EULER_SOLUTIONS_H
#define PROJECT_EULER_SOLUTIONS_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <inttypes.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>


#ifdef __cplusplus
#define EXTERN_C_BEGIN extern "C" {
#define EXTERN_C_END }
#else
#define EXTERN_C_BEGIN 
#define EXTERN_C_END
#endif

EXTERN_C_BEGIN

static inline uint8_t isIntegral(void* value, size_t size) 
{
    char* v = (char*)value;
    for (size_t counter = 0; counter < size; ++counter)
        if (!isdigit(v[counter]))
            return 0;
    return 1;
}

static inline uint8_t isNumeric(void* value, size_t size) 
{
    char* v = (char*)value;
    for (size_t counter = 0; counter < size; ++counter)
        if (!isdigit(v[counter]) && v[counter] != '.')
            return 0;
    return 1;
}

#define ASSERT_ARGUMENTS(argc, argv, expected, usage_fmt, ...) \
    do { \
        int _argc = argc; \
        char** _argv = argv; \
        const char* _usage_fmt = usage_fmt; \
        if (_argc < 2 || (argc - 1) != expected) {                \
            fprintf(stderr, "Usage: %s " usage_fmt "\n", argv[0], #__VA_ARGS__); \
            return EXIT_FAILURE;        \
        }                   \
    } while (0)

static inline uint8_t ultoa(unsigned long value, uint8_t* dest)
{
    uint8_t* ptr = dest;
    for (; value != 0;)
    {
        *ptr++ = value % 10;
        value /= 10;
    }
    *ptr = 0;
    return ptr - dest;
}

static inline uint8_t ascii2Dec(char ascii)
{
    assert(ascii <= 57 && ascii >= 48);
    return ascii - 48;
}

static uint64_t sieveOfErastosthenes(uint64_t n, bool(*callback)(uint64_t))
{
    assert(n > 1);
    bool A[n]; 
    memset(A, true, n);
    uint64_t i;
    for (i = 2; i < sqrt(n); ++i)
        if (A[i] == true) {
            uint64_t i_squared = i * i;
            for (uint64_t j = i_squared, counter = 0; j < n; j = i_squared + i * counter++)
                A[j] = false;
        }
    for (uint64_t counter = 2; counter < n; ++counter) {
        if (A[counter]) {
            if (callback(counter))
               return counter;
        }
    }
    return 0;
}

uint64_t factorial(uint64_t value)
{
    return value == 1 ? 1 : value * factorial(value - 1);
}

uint64_t binom(uint32_t n, uint32_t k)
{
    assert(k <= n);
    uint64_t ret = 1;
    uint32_t sub = n - k;
    if (sub > k) {
        for (uint32_t counter = n; counter > sub; --counter)
            ret *= counter;
        printf("Ret: %"PRIu64"\n", ret);
        return ret / factorial(k);
    } else {
        for (uint32_t counter = n; counter > k; --counter)
            ret *= counter;
        printf("Ret: %"PRIu64"\n", ret);
        return ret / factorial(sub);
    }
}

static inline uint8_t ascii2alph(uint8_t value)
{
    return value - 'A';
}

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a > b) ? (a) : (b)
#define STRINGLENGTH(val) val, strlen(val)

size_t string_add(const char* a, size_t lengtha, const char* b, size_t lengthb, char* dest)
{
    return 0;
}

size_t string_multiply_int(int a, unsigned b[], size_t length)
{
    unsigned res = 0;
    for (size_t counter = 0; counter < length; ++counter)
    {
        int prod = b[counter] * a + res;
        b[counter] = prod % 10;
        res = prod / 10;
    }
    while (res != 0)
    {
        b[length++] = res % 10;
        res /= 10;
    }
    return length;
}

#define FLEXIBLE_INT_MAXSIZE UINT32_MAX

typedef struct flexibleInt_s
{
    uint32_t size;
    uint32_t digits[1];
} flexibleInt_t;

EXTERN_C_END

#endif // PROJECT_EULER_SOLUTIONS_H
