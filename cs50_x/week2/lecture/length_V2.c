// Remember that each string ends with /0
#include <cs50.h>
#include <stdio.h>

// Determines the length of a string.
int main(void)
{
    string s = get_string("Input string: ");

    int length = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        length++;
        i++;
    }

    printf("Length: %i\n", length);
}
