#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(void)
{
    char *s1 = "sekha";
    char *s2 = "sekha's";
    if (strcasecmp(s1, s2) == 0)
        printf("Similar\n");
    else
        printf("Different\n");
}
