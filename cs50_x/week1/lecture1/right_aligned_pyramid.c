#include <stdio.h>
#include <cs50.h>

int add(int x);
void space_row(int i);
void block_row(int j);
void pyramid(int h);

int main(void)
{
    int height = get_int("Height: ");

    pyramid(height);
}



int add(int x)
{
    return(x + 1);
}



void space_row(int i)
{
    while(i > 0)
    {
        printf("_");

        i--;
    }
}



void block_row(int j)
{
    while(j > 0)
    {
        printf("#");

        j--;
    }
}



void pyramid(int h)
{
    for(int i = 0; i < h; i++)
    {
        space_row(h - add(i));

        block_row(add(i));-

        printf("\n");
    }
}
