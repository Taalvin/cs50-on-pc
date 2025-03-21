#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Converts all lowercase text into uppercase.
int main(void)
{
    string s = get_string("Input:  ");

    printf("Output: ");

    for (int i = 0, length = strlen(s); i < length; i++)
    {
        printf("%c", toupper(s[i]));
    }

    printf("\n");
}
