#include <cs50.h>
#include <stdio.h>

// Greets the name inputed in the command line arguements.
int main(int argc, string argv[])
{
    if (argc >= 2)
    {
         printf("Hello,");

        for (int i = 0; i < (argc - 1); i++)
        {
            printf(" %s", argv[i + 1]);
        }

        printf(".\n");
    }
    else
    {
        printf("Hello, world!\n");
    }
}
