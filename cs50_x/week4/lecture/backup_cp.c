#include <stdio.h>
#include <stdint.h>

// unit8_t = Give me an 8 bit value that is unsigned(no negative value).
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;

    // While there are bits to read from the file, execute loop.
    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(src);
    fclose(dst);
}
