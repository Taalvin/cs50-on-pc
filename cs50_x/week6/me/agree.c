// Simple terms and conditions program.

#include <stdio.h>

int main(void)
{
    // Gets input from standard input.
    puts("Do you agree?[y/n]");
    char answer;
    do
        scanf("%c", &answer);
    while (answer != 'n' && answer != 'N' && answer != 'y' && answer != 'Y');

    // Prints output to standard output.
    if (answer == 'y' || answer == 'Y')
        puts("User has agreed.");
    else if (answer == 'n' || answer == 'N')
        puts("User has not agreed.");
}