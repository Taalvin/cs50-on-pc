#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // PDF files always start with a four-byte sequence, corresponding to the
    // intergers: 37, 80, 68, 70
    BYTE *pattern = malloc(4 * sizeof(BYTE));

    *pattern = 37;
    *(pattern + 1) = 80;
    *(pattern + 2) = 68;
    *(pattern + 3) = 70;

    // Prevent user from inputting multiple files.
    if (argc != 2)
    {
        printf("Usage: ./pdf_checker file\n");
        return 1;
    }

    // Opens file.
    FILE *file = fopen(argv[1], "r");

    // Error checking.
    if (file == NULL)
    {
        return 2;
    }

    // Creates space to allocate the first four BYTE of file.
    BYTE *sequence = malloc(4 * sizeof(BYTE));
    if (sequence == NULL)
    {
        return 2;
    }

    // Copies first integers of file into sequence array.
    fread(sequence, sizeof(BYTE), 4, file);

    for (int i = 0; i < 4; i++)
    {
        // Compares each int.
        if (sequence[i] != *(pattern + i))
        {
            printf("file format is not PDF.\n");
            return 3;
        }
    }

    printf("file format is PDF.\n");

    // Closes file.
    fclose(file);

    free(pattern);
    free(sequence);

    return 0;
}
