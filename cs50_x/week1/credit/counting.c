#include <cs50.h>
#include <math.h>
#include <stdio.h>

int digits(long n);
int digit_addition(long input, int digits);

// Counts the amount of digits in an integer and counts the sum of the digits in an integer.
int main(void)
{
    long input;

    do
    {
        input = get_long("Input: ");
    }
    while (input <= 0);

    printf("Number of digits: %i\n", digits(input));
    printf("Addition of all digits: %i\n", digit_addition(input, digits(input)));
}

// Counts the amount of digits in a long.
int digits(long n)
{
    int counter = 0;

    while (n != 0)
    {
        n /= 10;
        counter++;
    }
    return counter;
}

// Calculates the sum of all the digits of an integer.
int digit_addition(long input, int digits)
{
    int total = 0;

    for (int i = 0; i < digits; i++)
    {
        total += input % 10;
        input /= 10;
    }
    return total;
}
