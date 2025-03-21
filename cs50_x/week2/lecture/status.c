#include <cs50.h>
#include <stdio.h>

// Return error code if code failed.
// Use "echo $?" command line arguement to view error code.
int main(int argc, string argv[])
{
    if (argc >= 2)
    {
         printf("Hello,");

        for (int i = 1; i < argc; i++)
        {
            printf(" %s", argv[i]);
        }

        printf("!\n");

        return 0;
    }
    else
    {
        printf("Usage: ./status NAME_1 NAME_2..etc\n");

        return 1;
    }
}
