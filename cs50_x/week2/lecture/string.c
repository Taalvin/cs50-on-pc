#include <string.h>
#include <cs50.h>
#include <stdio.h>

// Prints a string without using %s.
int main(void)
{
    string s = get_string("Input:  ");

    printf("Output: ");

    for(int i = 0, length = strlen(s); i < length; i++)
    {
        printf("%c", s[i]);
    }

    printf("\n");
}
