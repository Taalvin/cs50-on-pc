// Hello, world!
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string encryption(string key, string plaintext);

// Encrypts messages using a substitution cipher.
// Implement your program in a file called substitution.c in a directory called substitution.
// Your program must accept a single command-line argument, the key to use for the substitution.
// The key itself should be case-insensitive, so whether any character in the key is uppercase or
// lowercase should not affect the behavior of your program.
// If your program is executed without any command-line arguments or with more than one command-line
// argument, your program should print an error message of your choice (with printf) and return from
// main a value of 1 (which tends to signify an error) immediately. If the key is invalid (as by not
// containing 26 characters, containing any character that is not an alphabetic character, or not
// containing each letter exactly once), your program should print an error message of your choice
// (with printf) and return from main a value of 1 immediately. Your program must output plaintext:
// (without a newline) and then prompt the user for a string of plaintext (using get_string). Your
// program must output ciphertext: (without a newline) followed by the plaintext’s corresponding
// ciphertext, with each alphabetical character in the plaintext substituted for the corresponding
// character in the ciphertext; non-alphabetical characters should be outputted unchanged. Your
// program must preserve case: capitalized letters must remain capitalized letters; lowercase
// letters must remain lowercase letters. After outputting ciphertext, you should print a newline.
// Your program should then exit by returning 0 from main.
int main(int argc, string argv[])
{
    // Prevents the user from inputting more than one command-line arguement.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Prevents the user from inputting a key which does not contain 26
    // characters.
    int key_length = strlen(argv[1]);
    if (key_length != 26)
    {
        printf("Invalid key. Key must contain only 26 characters.\n");
        return 1;
    }

    // Prevents the user from inputting non-alphabetic characters.
    for (int i = 0; i < key_length; i++)
    {
        if (isalpha((argv[1][i])) == 0)
        {
            printf("Invalid key. Key must contain only alphabets.\n");
            return 1;
        }
    }

    // Prevents the user from inputting repeating characters.
    for (int i = 0, alphabet, count; i < 26; i++)
    {
        alphabet = argv[1][i];
        count = 0;
        for (int j = 0; j < 26; j++)
        {
            if (alphabet == argv[1][j])
            {
                count++;
            }
            else
            {
                continue;
            }

            if (count != 1)
            {
                printf("Invalid key. Key must not contain repeating alphabets.\n");
                return 1;
            }
        }
    }

    // Prompts user for a plaintext.
    string plaintext = get_string("plaintext: ");

    // Prints out ciphertext.
    printf("cyphertext: %s\n", encryption(argv[1], plaintext));

    // Goodbye, world.
    return 0;
}

// Encrypts script by substituting the alphabet by the respective characters
// in the key.
// This function is case-insensitive and let other characters apart from the
// alphabet to remain unchanged.
string encryption(string key, string plaintext)
{
    for (int i = 0, plaintext_len = strlen(plaintext); i < plaintext_len; i++)
    {
        if (islower(plaintext[i]))
        {
            plaintext[i] = key[plaintext[i] - 'a'] + ('a' - 'A');
        }
        else if (isupper(plaintext[i]))
        {
            plaintext[i] = key[plaintext[i] - 'A'];
        }
    }

    string cyphertext = plaintext;

    return cyphertext;
}
