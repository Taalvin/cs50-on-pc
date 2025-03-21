#include <stdio.h>

int factorial(int number);

int main(void)
{
    printf("ans = %i\n", factorial(8));
}

int factorial(int number)
{
    if (number > 1)
    {
        return number * factorial(number - 1);
    }

    return 1;
}
