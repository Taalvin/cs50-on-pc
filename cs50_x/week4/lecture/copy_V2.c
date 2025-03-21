#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s;
    do
    {
        s = get_string("s: ");
    }
    while (strlen(s) < 1);

    // If the computer runs out of memory, return 1.
    if (s == NULL)
    {
        return 1;
    }

    int l = strlen(s) + 1;

    // Allocates memory dynamically for "l" amount of bytes and
    // assigns the address of the allocated memory to the pointer t.
    // "dynamically" means that the memory is allocated at runtime,
    // as opposed to compile-time. This allows for more flexible
    // memory management, as you can allocate exactly the amount
    // of memory you need when you need it, rather than having to
    // specify the size in advance.
    // Malloc returns the first address of the chunck of memory.
    char *t = malloc(strlen(s) + 1);

    // If the computer runs out of memory, return 1.
    if (t == NULL)
    {
        return 1;
    }

    // Copies string to empty char array.
    strcpy(t, s);

    // Converts first char of t to upper case.
    t[0] = toupper(t[0]);

    printf("t: %s\n", t);

    // Deallocates the memory that was previously allocated with malloc.
    // This helps prevent memory leaks by returning the allocated memory
    // back to the system for future use.
    // A memory leak occurs when a program allocates memory but fails
    // to release it back to the system, leading to a gradual increase
    // in memory usage and potentially causing the program to run out
    // of memory.
    free(t);

    return 0;
}
