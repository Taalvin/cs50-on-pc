#include "stdio.h"
#include "cs50.h"

void pyramid(int t, int b);

int main(void)
{
    int t = get_int("Length of top: ");

    int h = get_int("Length of height: ");

    pyramid(t, h);
}



void pyramid(int t, int h)
{
    for(int i = 0; i < h; i++)
    {
        for(int n = 0; n < t; n++)
        {
            printf("|/|");
        }

        t++;

        printf("\n");
    }
}
