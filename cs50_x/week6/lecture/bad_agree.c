// INCORRECT VERSION.
// Checks if user has agreed to something.

#include <stdio.h>

int main(void)
{
    // Asks user if he agrees or not.
    printf("Do you agree?[y/n] ");

    // Gets user input.
    int choice;
    scanf("%i", &choice);

    // Prints results.
    /*
    The expression ('y' || 'Y') evaluates to true (or 1)
    because it's a logical OR operation between two non-zero values.
    So, choice == ('y' || 'Y') is essentially choice == 1
    */
    if (choice == ('y' || 'Y'))
        printf("User has agreed.\n");
    else if (choice == ('n' || 'N')) 
        printf("User has not agreed.\n");
} 