// Checks if user has agreed to something.

#include <stdio.h>

int main(void)
{
    // Asks user if he agrees or not.
    printf("Do you agree?[y/n] ");

    // Gets user input.
    char choice;
    scanf("%c", &choice);

    // Prints results.
    if (choice == 'y' || choice == 'Y')
        printf("User has agreed.\n");
    else if (choice == 'n' || choice == 'N')
        printf("User has not agreed.\n");
}