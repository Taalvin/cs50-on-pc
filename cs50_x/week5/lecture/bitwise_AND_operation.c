// This simple program demonstrates how the AND operation work. The
// demonstration involves the checking of the first 4 bits of a file.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "rb");
    if (file != NULL)
    {
        // fgetc() reads the next char from a given file.
        int byte = fgetc(file);
        if (byte != EOF)
        {
            // Checks the first four bits.
            // (0xF0 / 11110000) Mask to get the first four bits.
            // The bitwise AND operation compares each bit of byte and 0xf0.
            //  It results in 1 only if both corresponding bits are 1.
            // For example, if the first bytes are 1010-1101,
            // first_four_bits bitwise will become 1010-0000.
            int first_four_bits = byte & 0xF0;
        }
        fclose(file);
    }
    return 0;
}
