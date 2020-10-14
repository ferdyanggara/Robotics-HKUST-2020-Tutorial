#include <stdio.h>
int _pow(float x, int y)
{
    // Please complete the function body
    int result = 1;
    int i = 0;
    while (i < y)
    {
        result *= x;
        i++;
    }
    return result;
}

int reverse(int x)
{
    // Please complete the function body
    // check for negative
    int neg = 0;
    if (x < 0)
    {
        x = -x;
        neg = 1;
    }

    int result = 0;
    int placeHolder = x;
    int length = 0;
    int digit;

    while (placeHolder != 0)
    {
        placeHolder /= 10;
        length++;
    }

    while (length > 0)
    {
        digit = x % 10;
        result += digit * _pow(10, --length);
        x /= 10;
    }

    if (neg)
        result = -result;

    return result;
}

int main()
{
    int to_reverse = 123;
    printf("reverse %d = %d", to_reverse, reverse(to_reverse));
    return 0;
}