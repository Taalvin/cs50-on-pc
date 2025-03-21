// Complete phonebook.

#include <stdio.h>
#include <string.h>

typedef struct
{
    char * name;
    char * number;
} person;

int main(void)
{
    // Sets up phonebook.
    int size = 3;
    person phonebook[size];

    phonebook[0].name = "popits";
    phonebook[0].number = "+230-5798-6025";

    phonebook[1].name = "momits";
    phonebook[1].number = "+250-5780-0561";

    phonebook[2].name = "yu";
    phonebook[2].number = "+250-5782-6288";

    // Allocate memory for user input.
    char name[50];

    // Gets user input.
    printf("Name: ");
    scanf("%49s", name); 

    // Searches for name.
    for (int i = 0; i < size; i++)
    {
        if (strcmp(name, phonebook[i].name) == 0)
        {
            printf("Number: %s\n", phonebook[i].number);
            return 0;
        }
    }
    puts("Person not found.");
    return 0;
}