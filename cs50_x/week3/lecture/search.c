#include <cs50.h>
#include <stdio.h>

// Gets number from user.
// searches number from an array.
int main(void)
{
    // intializing array.
    int array[] = {100, 500, 1, 50, 10, 5, 25};

    // Gets number from user.
    int input = get_int("Input: ");

    // Searches number from element of array one by one.
    for (int i = 0; i < 7; i++)
    {
        // If number is found, end program.
        if (array[i] == input)
        {
            printf("Found.\n");
            return 0;
        }
    }

    // Outputs error message if number is not found.
    printf("Not found.\n");
    return 1;
}
