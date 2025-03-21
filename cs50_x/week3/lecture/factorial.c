#include <cs50.h>
#include <stdio.h>

int factorial(int number);

int main(void)
{
    printf("ans = %i\n", factorial(8));
}

int factorial(int number)
{
    int x;
    x = number - 1;

    if (x > 0)
    {
        return number * factorial(x);
    }
    else
    {
        return 1;
    }
}
