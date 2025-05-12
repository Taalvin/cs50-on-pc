#include <stdio.h> 

int main(void)
{
    // Prompts the user for a suitable column of the pyramid.
    int column, row;
    printf("Height: ");
    do
        scanf("%i", &column);
    while (column < 0);
    row = column;

    // Prints the pyramid.
    for (int i = 0; column > i; i++)
    {
        row--;
        for (int j = 0; row > j; j++)
            printf(" ");
        for (int j = 0; i >= j; j++)
            printf("#");
        printf("\n");
    }
}
           
