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
    // This function returns the number of items read, which equals
    // the number of bytes read when size is 1.
    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        // &b = where to find the BYTE that you wanted to be pasted.
        // sizeof(b) = size of BYTE.
        // 1 = One BYTE at a time.
        // dst = write it do the destination file.
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(src);
    fclose(dst);
}
