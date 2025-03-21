#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[8] = {1, 5, 3, 2, 0, 4, 7, 6};

    // Prints unsorted array.
    for (int i = 0; i < 8;i++)
    {
        printf("%i", numbers[i]);
    }
    printf("\n");

    for (int i = 0, x, k = 0; i < 7; i++)
    {
        x = numbers[i];
        // Compares numbers[i] to all the elements in numbers.
        // Switches place with the smallest element.
        // Else, stay in place.
        for (int j = (i + 1); j < 8; j++)
        {
            if (numbers[i] < numbers[j] && numbers[j] > x)
            {
                // Store numbers[j] in memory.
                x = numbers[j];
                k = j;

            }
        }

        // If there is an element less than numbers[i], switch places.
        if (x != numbers[i])
        {
            numbers[k] = numbers[i];
            numbers[i] = x;
        }
    }

    // Prints sorted array.
    for (int i = 0; i < 8;i++)
    {
        printf("%i", numbers[i]);
    }
    printf("\n");
}
