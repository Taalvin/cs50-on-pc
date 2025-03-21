#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encryption(int key, int length, char plaintext[]);

// Takes only one key(int) from the user in the command-line interface.
int main(int argc, string argv[])
{
    // Prevents the user from inputting no key, or more than one key.
    if (argc != 2)
    {
        printf("Usage: ./caeser key\n");

        return 1;
    }

    // Prevents the user from inputting a negative integer.
    if (atoi(argv[1]) < 1)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }

    // Prevents the user from inputting a non-integer value.
    for (int i = 0, key_length = strlen(argv[1]); i < key_length; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caeser key\n");
            return 1;
        }
    }

    // Converts key from string to int data type.
    // prevents key from going over 26.
    int key = (atoi(argv[1]) + 26) % 26;

    // Prompts plaintext from user.
    string plaintext = get_string("plaintext: ");

    // Outputs cypertext.
    printf("ciphertext: %s\n", encryption(key, strlen(plaintext), plaintext));
}

// Encryption logic.
string encryption(int key, int length, char plaintext[])
{
    for (int i = 0; i < length; i++)
    {
        // Checks if elements of plaintext is char or int.
        if (isalpha(plaintext[i]))
        {
            // Checks if loop-back is needed.
            if ((isupper(plaintext[i]) && (plaintext[i] + key) > 'Z') ||
                (islower(plaintext[i]) && (plaintext[i] + key) > 'z'))
            {
                plaintext[i] = plaintext[i] + key - 26;
            }
            // Encrypts char.
            else
            {
                plaintext[i] = plaintext[i] + key;
            }
        }
    }
    return plaintext;
}
