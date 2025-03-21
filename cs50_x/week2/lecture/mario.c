#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// "argc" is the number of inputs to our program at the command-line.
// "argv" is the array of strings of inputs of our program at the command-line.
// "atoi()" is a function that converts string(numbers) into int(text will become the value 0).
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./mario height.\n");

        return 1;
    }

    int height = atoi(argv[1]);

    printf("%i\n", height);

    return 0;
}
