#include <stdio.h>
#include <cs50.h>

void lucky_block(int n);

void block(int a, int b,int o);

int main(void)
{
    int x;

    do
    {
        x = get_int("x : ");
    }
    while(x < 0);

    int y;

    do
    {
        y = get_int("y : ");
    }
    while(y < 0);

    int i = x;

    block(x, y, i);
}

void lucky_block(int n)
{
    while(n > 0)
    {
        printf("|?|");

        n--;
    }
}

void block(int a, int b, int o)
{
    while(b > 0)
    {
        while(a > 0)
        {
            printf("|/|");

            a--;
        }

        printf("\n");

        a = o;

        b--;
    }
}
