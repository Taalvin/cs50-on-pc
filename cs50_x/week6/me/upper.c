// Converts all characters in a string to uppercase.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Gets input from standard input.
    char *s = get_string("Input:  ");

    // Processes input.
    for (int i = 0, len = strlen(s); i < len; i++)
        s[i] = toupper(s[i]); 

    // Prints output to standard output.
    printf("Output: %s\n", s);
}