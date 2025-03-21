#include <stdio.h>

int main(int argc, char *argv[])
{
    // Prevent user from inputting multiple files.
    if (argc != 2)
    {
        printf("Usage: ./cat file\n");
        return 1;
    }

    // Opens file.
    FILE *file = fopen(argv[1], "r");

    // Error checking.
    if (file == NULL)
    {
        return 2;
    }

    // Copies file in terminal.
    char container;
    while ((container = fgetc(file)) != EOF)
    {
        printf("%c", container);
    }

    // Closes file.
    fclose(file);

    return 0;
}
