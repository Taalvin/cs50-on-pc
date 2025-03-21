// Incomplete phonebook.

#include <stdio.h>
#include <string.h>

int main(void)
{
    // Sets up phonebook.
    int size = 3;
    char *phonebook[] = {"Taalvin", "Nemisha", "Sekha"};

    // Allocate memory for user input.
    char name[50];

    // Gets user input.
    printf("Name: ");
    scanf("%49s", name); 

    // Searches for name.
    for (int i = 0; i < size; i++)
    {
        if (strcmp(name, phonebook[i]) == 0)
        {
            puts("Person found.");
            return 0;
        }
    }
    puts("Person not found.");
    return 0;
}