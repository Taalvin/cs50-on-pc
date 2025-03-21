#include <stdio.h>

int main(void)
{
    // Initializing a variable.
    int n = 50;

    // Declaring a pointer.
    // Declaring a variable called p that is going
    // to point to an integer's location.
    int *p = &n;

    // Printing the address of n.
    printf("%p\n", p);

    // Printing n. *p: go to that location.
    printf("%i\n", *p);
}
