#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int y = get_int("Please input an integer for y\n");

    int x = get_int("Please input an integer for x\n");

    if(y > x)
    {
        printf("y is greater than x\n");
    }

    else if(x > y)
    {
        printf("x is greater than y\n");
    }

    else
    {
        printf("x is equal to y\n");
    }

}
