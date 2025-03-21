// Simple calculator.
#include <stdio.h>

int main(void)
{
    // Gets input from standard input(user).
    int x, y;
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    // Prints output to standard output.
    printf("x + y = %d\n", x + y);
}