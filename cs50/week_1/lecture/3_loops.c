#include <stdio.h>

void meow(int i);

int main(void)
{
    // Prompts user for input till valid input is registered.
    int i;
    do
    {
        printf("State the number of meows: ");
        scanf(" %i", &i);
    }
    while (i < 1);
    
    // Prints "i" amount of meows.
    meow(i);
}

void meow(int i)
{
    for (int j = 0; j < i; j++)
        printf("meow\n");
}
