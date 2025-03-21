// This is a version of volume.c made without looking at the distribution code
// provided by the CS50 team.

#include <limits.h> // INT16_MAX and INT16_MIN are defined in the <limits.h>.
#include <stdio.h> // Has FILE data type.
#include <stdlib.h> // Has atoi() function.
#include <stdint.h> // Has uint8_t data type.

// uint8_t == BYTE == 8 bit value that is unsigned(no negative value).
// int16_t == 2BYTEs == 16 bit value that is signed(+Ve and -Ve values).
typedef uint8_t BYTE;
typedef int16_t TWO_BYTES;

int main(int argc, char *argv[])
{
    // Forces user to imput only 3 command-line arguements.
    if (argc != 4)
    {
        printf("Usage: ./vol src_file new_file factor\n");
        return 1;
    }

    // Converts factor(which is currently a string) into a float value for more
    // precise volume adjustments.
    float factor = atof(argv[3]);
    if (factor < 0)
    {
        printf("Please input a positive factor.\n");
        return 2;
    }

    // Opens the source WAV file.
    FILE * src_file = fopen(argv[1], "r");
    if (src_file == NULL)
    {
        printf("Error: Could not open source file %s.\n", argv[1]);
        return 3;
    }

    // Creates a new WAV file.
    FILE * new_file = fopen(argv[2], "w");
    if (new_file == NULL)
    {
        printf("Error: Could not create new file %s.\n", argv[2]);
        fclose(src_file);
        return 4;
    }

    // Creates buffer to store first 44 BYTEs of WAV src_file.
    BYTE *buffer = malloc(44 * sizeof(BYTE));
    if (buffer == NULL)
    {
        printf("Error: Could not allocate memory for the buffer.\n");
        fclose(src_file);
        fclose(new_file);
        return 5;
    }

    // Transfer first 44 BYTEs to new_file.
    if (fread(buffer, sizeof(BYTE), 44, src_file) != 44)
    {
        printf("Error: Could not read header from source file.\n");
        free(buffer);
        fclose(src_file);
        fclose(new_file);
        return 6;
    }
    if (fwrite(buffer, sizeof(BYTE), 44, new_file) != 44)
    {
        printf("Error: Could not write header to new file.\n");
        free(buffer);
        fclose(src_file);
        fclose(new_file);
        return 7;
    }

    // Creates buffer to store 2 BYTEs.
    TWO_BYTES *buffer_2 = malloc(sizeof(TWO_BYTES));
    if (buffer_2 == NULL)
    {
        printf("Error: Could not allocate memory for the buffer.\n");
        free(buffer);
        fclose(src_file);
        fclose(new_file);
        return 8;
    }

    // Reads each audio signal, scales it, and then writes it in new_file)
    while ((fread(buffer_2, sizeof(TWO_BYTES), 1, src_file)) == 1)
    {
        *buffer_2 = *buffer_2 * factor;

        // If audio signal exceeds TWO_BYTES
        if (*buffer_2 > INT16_MAX)
        *buffer_2 = INT16_MAX;

        // If audio signal is less than TWO_BYTES
        if (*buffer_2 < INT16_MIN)
        *buffer_2 = INT16_MIN;

        if ((fwrite(buffer_2, sizeof(TWO_BYTES), 1, new_file)) != 1)
        {
            printf("Error: Could not write audio signal to new file.\n");
            free(buffer_2);
            free(buffer);
            fclose(src_file);
            fclose(new_file);
            return 9;
        }
    }

    // Closes both files.
    fclose(src_file);
    fclose(new_file);

    // Free memory.
    free(buffer);
    free(buffer_2);

    // Goodbye, world.
    return 0;
}
