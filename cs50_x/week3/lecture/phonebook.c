#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Creating a new data type called person.
typedef struct
{
    string names;
    string numbers;
} person;

int main(void)
{
    // Declaring an array of type person of 5 elements.
    person people[3];

    people[0].names = "popits";
    people[0].numbers = "+230-5798-6025";

    people[1].names = "momits";
    people[1].numbers = "+250-5780-0561";

    people[2].names = "yu";
    people[2].numbers = "+250-5782-6288";

    // Prompts name whose phone number is needed.
    string name = get_string("Name: ");

    // Searches for name in names[] and outputs its corresponding number.
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].names, name) == 0)
        {
            printf("Number: %s\n", people[i].numbers);
            return 0;
        }
    }

    // If fails to find name from names[].
    printf("Person not yet registered.\n");
    return 1;
}
