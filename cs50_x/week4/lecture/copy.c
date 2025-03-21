#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "hi!";
    char t[strlen(s) + 1];

    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    {
        t[i] = s[i];
    }

    if (strlen(s) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);
}
