// Simple program to test structs in C.

#include <stdio.h>

typedef struct employee
{
    char *first;
    char *last;
} employee;

void print_fname(employee x);

int main(void)
{
    // Initializing employee.
    employee x;
    x.first = "Taalvin";
    x.last = "Coolen";

    // Printing first and last name.
    print_fname(x);

    return 0;
}

void print_fname(employee x)
{
    printf("Full name: %s %s\n", x.first, x.last);
}