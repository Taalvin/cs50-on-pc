#include <cs50.h>
#include <stdio.h>

void recursive_row(int length);

int main(void)
{
    int length = get_int("length: ");

    recursive_row(length);
}

void recursive_row(int length)
{
    if (0 < length)
    {
        recursive_row(length - 1);
    }

    for (int i = 0; i < length; i++)
    {
        printf("#");
    }

    printf("\n");
}
