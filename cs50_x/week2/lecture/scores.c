#include <cs50.h>
#include <stdio.h>

float avg(int n, int scores[]);

// Calculates avg value of scores inputed by user.
int main(void)
{
    const int n = get_int("Amount of subjects: ");

    int scores[n];

    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("score_%i = ", i + 1);
    }

    printf("%f\n", avg(n, scores));
}

// Calcuates average float value of integers of an array
float avg(int n, int scores[])
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = scores[i] + sum;
    }

    return (sum / (float) n);
}
