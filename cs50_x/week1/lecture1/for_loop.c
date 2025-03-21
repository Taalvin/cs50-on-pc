#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("How many times do you want DevDuck to quack?\n");

    for(int counter = 0; counter < n; counter++)
    {
        printf("QUACK!\n");
    }
}
