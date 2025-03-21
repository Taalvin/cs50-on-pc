#include <cs50.h>
#include <stdio.h>

void valid_triangle(int x, int y, int z);

// States if the lengths inputed will result in a valid triangle.
int main(void)
{
    int x = 1, y = 1, z = 1;
    do
    {
        if (x < 1 || y < 1 || z < 1)
        {
            printf("Please enter a valid number.\n");
        }

        x = get_int("Please state the first length:  ");

        y = get_int("Please state the second length: ");

        z = get_int("Please state the third length:  ");
    }
    while (x < 1 || y < 1 || z < 1);

    valid_triangle(x, y, z);
}

// Validates the triangle or not.
void valid_triangle(int x, int y, int z)
{
    if ((x + y) > z)
    {
        printf("This is a VALID triangle.\n");
    }
    else
    {
        printf("This is an INVALID triangle.\n");
    }
}
