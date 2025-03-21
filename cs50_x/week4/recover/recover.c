#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Forces user to imput only 1 command-line arguement.
    if (argc != 2)
    {
        printf("Usage: ./recover forensic_image\n");
        return 1;
    }

    // Opens the source RAW file.
    FILE *forensic_image = fopen(argv[1], "r");
    if (forensic_image == NULL)
    {
        printf("Error: Could not open %s.\n", argv[1]);
        return 1;
    }

    // Buffer of 512 unsigned BYTEs.
    BYTE buffer[512];

    // String to store int images_found.
    char typestring_images_found[8];

    // Number of JPEGs found.
    int images_found = 0;

    // Reads 4 BYTEs from a block in forensic_image.
    // If BYTEs could not be read, end search.
    while (fread(buffer, 4 * sizeof(BYTE), 1, forensic_image) == 1)
    {
        // Go back 4 BYTEs.
        fseek(forensic_image, -4, SEEK_CUR);

        // If JPEG is found.
        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 &&
            (buffer[3] >= 224 && buffer[3] <= 240))
        {
            // Caps images_found to 999.
            if (images_found > 999)
            {
                fclose(forensic_image);
                printf("Error: Number of restored images has exceeded 999.\n");
                return 2;
            }

            // Converts counter to a string.
            if (images_found < 10)
                sprintf(typestring_images_found, "00%i.jpg", images_found);
            else if (images_found > 9 && images_found < 99)
                sprintf(typestring_images_found, "0%i.jpg", images_found);
            else
                sprintf(typestring_images_found, "%i.jpg", images_found);

            images_found++;

            // Creates JPEG file.
            FILE *recovered_image = fopen(typestring_images_found, "w");
            if (recovered_image == NULL)
            {
                fclose(forensic_image);
                printf("Error: Could not create recovered_image JPEG.\n");
                return 3;
            }

            fseek(forensic_image, 4, SEEK_CUR);

            do
            {
                // Go back 4 BYTEs.
                fseek(forensic_image, -4, SEEK_CUR);

                // Reads 1 block(512 unsigned BYTEs) from forensic_image.
                fread(buffer, 512 * sizeof(BYTE), 1, forensic_image);

                // Writes image found into JPEG file.
                fwrite(buffer, 512 * sizeof(BYTE), 1, recovered_image);

                // Reached EOF.
                if (fread(buffer, 4 * sizeof(BYTE), 1, forensic_image) != 1)
                {
                    fclose(forensic_image);
                    fclose(recovered_image);
                    return 0;
                }
            }
            while (buffer[0] != 255 || buffer[1] != 216 || buffer[2] != 255 ||
                   (buffer[3] < 224 || buffer[3] > 240));

            // Closes JPEG file.
            fclose(recovered_image);

            // Puts fread() at beginning of new block.
            fseek(forensic_image, -4, SEEK_CUR);
        }
        else
            // Skips 1 block(512 BYTEs).
            fseek(forensic_image, 512, SEEK_CUR);
    }

    // Closes file.
    fclose(forensic_image);
    return 0;
}
