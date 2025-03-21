#include <cs50.h>
#include <stdio.h>

void pyramid(int h);
int add(int a);

int main(void)
{
    int height;

    do
    {
        height = get_int("height: ");
    }
    while (height <= 0);

    pyramid(height);
}

void pyramid(int h)
{
    for (int j = 0; j < h; j++)
    {
        for (int x = 0; x < h - add(j); x++)
        {
            printf(" ");
        }

        for (int i = 0; i < add(j); i++)
        {
            printf("#");
        }

        printf("  ");

        for (int i = 0; i < add(j); i++)
        {
            printf("#");
        }

        printf("\n");
    }
}

int add(int a)
{
    return (a + 1);
}
