#include <stdio.h>

int main(void)
{
    // Stores user's input.
    int x, y;

    // Gets input from the user.
    printf("x: ");
    scanf("%i", &x);
    printf("x: ");
    scanf("%i", &y);
    
    // Prints output.
    printf("x + y = %i\n", x + y);
}