#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Making place for a string of size 4 BYTES.
    char s[4];

    printf("s: ");
    scanf("%s", s);
    printf("String scanned: %s\n", s);
}
