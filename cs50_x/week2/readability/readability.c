#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float liau(int letters, int words, int sentences);

// Implement a program that calculates the approximate grade level needed to comprehend some text.
// Your program should print as output “Grade X” where “X” is the grade level computed, rounded to
// the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior
// undergraduate reading level), your program should output “Grade 16+” instead of giving the exact
// index number. If the grade level is less than 1, your program should output “Before Grade 1”.
//  The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to
//  understand some text.
// The formula is [index = 0.0588 * L - 0.296 * S - 15.8].
// where L is the average number of letters per 100 words in the text, and S is the average number
// of sentences per 100 words in the text.
int main(void)
{
    string text;

    // Promps text from the user.
    do
    {
        text = get_string("Text: ");
    }
    // prevents the user from inputting nothing.
    while(strlen(text) < 1);

    int sentences = 0, spaces = 0, letters = 0, length = strlen(text), words;

    for (int i = 0; i < length; i++)
    {
        if (isspace(text[i]) != 0)
        {
            spaces++;
        }
        else if (isalpha(text[i]) != 0)
        {
            letters++;
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }

    // word = 1 if only one word is inputted.
    if (spaces == 0)
    {
        words = 1;
    }
    else
    {
        words = spaces + 1;
    }

    int grade = (int) round(liau(letters, words, sentences));

    if (grade < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Returns Coleman-Liau index.
float liau(int letters, int words, int sentences)
{
    float S = sentences / ((float) words / 100);

    float L = letters / ((float) words / 100);

    return 0.0588 * L - 0.296 * S - 15.8;
}
