#include <stdint.h>
#include <stdio.h>

// uint64_t = unsigned 64-bit integer
uint64_t factorial(uint32_t f)
{
    // Please complete the function body
    uint64_t result = 1;
    if (f == 0)
    {
        return result;
    }
    else
    {
        return (f * factorial(f - 1));
    }

    // for (uint64_t x = f; x > 0; x--)
    // {
    //     result *= x;
    // }
    // return result;
}

int main()
{
    // You can modify main function for testing purpose
    for (int i = 0; i < 15; i++)
    {
        printf("%d! = %lu\n", i, factorial(i));
    }
    return 0;
}