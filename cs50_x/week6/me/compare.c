// Compares two numbers. 

#include <stdio.h>

int main(void)
{
    // Gets input from standard input.
    int x, y;
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    // Prints output to standard output.
    if (x > y)
        puts("x is greater than y.");
    else if (x < y)
        puts("y is greater than x.");
    else
        puts("x is equal to y.");
}