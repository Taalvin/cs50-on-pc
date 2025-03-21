#include <cs50.h>
#include <stdio.h>

void pyramid(int length);

int main(void)
{
    int length = get_int("Length of pyramid: ");

    pyramid(length);
}

void pyramid(int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
