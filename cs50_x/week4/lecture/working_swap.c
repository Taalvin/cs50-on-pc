#include <cs50.h>
#include <stdio.h>

void swap(int *x, int *y);

int main(void)
{
    int y = get_int("y: ");
    int x = get_int("x: ");

    // Passing by reference/pointer.
    swap(&y, &x);

    printf("y: %i\n", y);
    printf("x: %i\n", x);
}

// Its kinda like int*x = &x(in the main funciton).
// That is why we can't use void swap(&a, &b)...
// You can't use the &a = &y; expression as you can't
// assign to the address of a variable because the
// address of a variable is a constant value determined
// by the compiler.
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
