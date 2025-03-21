#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    // Gets input from standard input.
    char character;
    printf("Input character: ");
    scanf("%c", &character);

    // Processes input.
    bool letters_only = isalpha(character) ? true : false;
    
    // Prints Output.
    if (letters_only == true)
        puts("Character is an alphabet.");
    else
        puts("Character is NOT an alphabet.");

    return 0;
}