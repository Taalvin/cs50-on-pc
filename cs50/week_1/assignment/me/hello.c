#include <stdio.h>

int main(void)
{
    // Prompts user for name.
    char name [99];
    printf("what's your name? ");
    scanf("%s", name);

    printf("hello, %s\n", name);
    return 0;
}
