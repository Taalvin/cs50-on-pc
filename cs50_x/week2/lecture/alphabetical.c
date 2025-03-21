#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Write a program to check if an array of characters is in alphabetical order.
// Assume the characters are all uppercase.
int main(void)
{
    string text = get_string("Input text: ");

    int n = (int) strlen(text);

    int x;

    int first_char = text[0];

    for (int i = 0; i < n; i++)
    {
        x = 1;

        if (text[i] == (first_char + i))
        {
            x = 1 + i;
        }
    }

    if (x == n)
    {
        printf("VALID.\n");
    }
    else
    {
        printf("INVALID.\n"); 
    }
}
