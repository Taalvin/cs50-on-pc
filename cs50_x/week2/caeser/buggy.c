#include <stdio.h>
#include <cs50.h>

void meow(int n);

// Meows 'n' times.
int main(void)
{
    int n = get_int("How many times do you want the cat to meow?\n");

    meow(n);
}

// Prints meow 'n' amount of times.
void meow(int n)
{
    for(int i = 0; i <= n; i++)
    {
        printf("meow\n");
    }
}

