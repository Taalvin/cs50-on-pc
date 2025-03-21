#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Using strcmp function to compare strings.
int main(void)
{
    string answer = get_string("Are you taalvin? ");

    if (strcmp(answer, "yes") == 0)
    {
        printf("You must make it.\n");
    }
}

