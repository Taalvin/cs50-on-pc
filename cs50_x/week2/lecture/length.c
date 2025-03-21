#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Determines the length of a string.
int main(void)
{
    string name = get_string("Name: ");

    printf("%lu\n", strlen(name));
}

