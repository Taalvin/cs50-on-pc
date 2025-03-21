// Calculates the average length of words in a txt file.
#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Forces user to input only 2 command-line arguements.
    if (argc != 2)
    {
        printf("Usage: ./avglen txt_file\n");
        return 1;
    }

    // Opens txt file.
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error: Could not open txt file.\n");
        return 2;
    }

    // Counts amount of words and characters in txt file.
    unsigned int word_count = 0, char_count = 0;
    char buffer;
    while (fread(&buffer, sizeof(char), 1, fp))
    {
        if (buffer == '\n' || isblank(buffer))
            word_count++;
        else
            char_count++;
    }
    if (word_count == 0)
    {
        printf("Error: There are no words in the txt file.\n");
        return 3;
    }

    // Calculates Average word length.
    double avglen = char_count / (double)word_count;

    // Prints results.
    printf("Characters: %i\nWords: %i\nAverage length of word: %f\n", char_count, word_count, avglen);

    // Closes txt file.
    fclose(fp);
}
