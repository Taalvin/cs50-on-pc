#include <cs50.h>
#include <stdio.h>

void swap(int x, int y);

int main(void)
{
    int y = get_int("y: ");
    int x = get_int("x: ");

    // Passing by value/copy.
    swap(y, x);

    printf("y: %i\n", y);
    printf("x: %i\n", x);
}

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    return;
}
