// Compares the value of 2 integers.

#include <stdio.h>

int main(void)
{
    int x, y;

    // Gets input from user.
    printf("x : ");
    scanf("%i", &x);
    printf("y : ");
    scanf("%i", &y);
    
    // Prints output.
    if (x > y)
        printf("x is greater than y.\n");
    else if (x < y)
        printf("y is greater than x.\n");
    else
        printf("x is equal to y.\n");
}