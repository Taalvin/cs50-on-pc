#include <stdio.h>

char Toupper(char character);

int main(void)
{
    // Buffer for answer.
    char ans;

    do
    {
        // Prompts the user.
        printf("Do you agree? ");
        scanf(" %c", &ans);
        ans = Toupper(ans);

        // Confirms intput.
        if (ans == 'Y')
            printf("The user agreed.\n");
        else if (ans == 'N')
            printf("The user has not agreed.\n");
        else
            printf("Please enter apropriate answer.\n");
    } while (ans != 'Y' && ans != 'N');
}

// Converts lowercase characters to uppercase.
char Toupper(char character)
{
    if (character >= 'a' && character <= 'z')
        return character - ('a' - 'A');
    else 
        return character;
}   
