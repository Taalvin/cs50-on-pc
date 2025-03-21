// Compares two strings.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Gets input from standard input.
    char *s1 = get_string("s1: ");
    char *s2 = get_string("s2: ");

    // Prints output to standard output.
    if (strcmp(s1, s2) == 0)
        printf("Strings are similar to each other.\n");
    else
        printf("Strings differ to each other.\n");
}