#include <stdio.h>
#include <cs50.h>

void meow_loop(int n);



int main(void)
{
    int n = get_int("How many times do you want the cat to meow?\n");

    meow_loop(n);
}



void meow_loop(int n)
{
    while(n > 0)
    {
        printf("meow\n");

        n -= 1;
    }
}
