#include <stdint.h>
#include <stdio.h>

float a, b, c, d;

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
}

float _pow(float x, int y)
{
    // Please complete the function body

    if (y == 0)
    {
        return 1;
    }
    else if (y % 2 == 0)
    {
        return _pow(x, y / 2) * _pow(x, y / 2);
    }
    else
    {
        return x * _pow(x, y / 2) * _pow(x, y / 2);
    }
}

float taylor_series_sin(float radian)
{
    int y = 1;
    while (y < 8)
    {
        a = _pow(radian, 2 * y - 1);
        b = _pow(-1, y + 1);
        c = factorial(2 * y - 1);

        d = d + a * b / c;
        y++;
    }

    return d;
}

int main()
{
    const float PI = 3.14159265f;
    float radian = PI / 3.0f;
    printf("sin(%f) = %f", radian, taylor_series_sin(radian));
    return 0;
}