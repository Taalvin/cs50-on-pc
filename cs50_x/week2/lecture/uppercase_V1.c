#include <cs50.h>
#include <string.h>
#include <stdio.h>

// Converts all lowercase text into uppercase.
int main(void)
{
    string s = get_string("Input:  ");

    printf("Output: ");

    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (97 <= s[i] && s[i] <= 122)
        {
                s[i] = s[i] - 32;
        }

        printf("%c", s[i]);
    }

    printf("\n");
}
