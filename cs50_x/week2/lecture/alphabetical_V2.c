#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Write a program to check if an array of characters is in alphabetical order.
// Assume the characters are all uppercase.
int main(void)
{
    string text = get_string("Input a text: ");

    for (int i = 0, length = (strlen(text) - 1); i < length; i++)
    {
        if (text[i] > text[i + 1])
        {
            printf("Not in alphabetical order.\n");

            return 0;
        }
    }

    printf("In alphabetical order.\n");
}
