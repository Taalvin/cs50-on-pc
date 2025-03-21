#include <cs50.h>
#include <stdio.h>

// Creates an array of integers in which each integer is 2 times the value
// of the previous integer.
// The first element is 1.
// Print the array,integer by integer.
int main(void)
{
    int size;

    do
    {
        size = get_int("State the size of the array: ");
    }
    while (size <= 0);

    int doubling_up[size];

    doubling_up[0] = 1;

    printf("Sequence: %i ", doubling_up[0]);

    for (int i = 1; i < size; i++)
    {
        doubling_up[i] = doubling_up[i - 1] * 2;

        printf("%i ", doubling_up[i]);
    }

    printf("\n");
}
