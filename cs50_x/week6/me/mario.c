// Simple program that makes ascii art of bricks.

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
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}