#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // s is actually a pointer to the start of the array of char.
    // (char *s == &s[0])
    string s = "Hello, world!";

    // Prints out the start of the array of char,
    // which is 'H'.
    printf("%c\n", *s);

    // Hence,... *cue dramatic music*
    string s = "Hello, world!";
    // is the exact same thing as,
    char *s = "Hello, world!"
    // BOOoOOOOM!!
}
