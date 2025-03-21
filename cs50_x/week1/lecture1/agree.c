#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char ans;

    do
    {
        ans = get_char("Do you agree to the terms and conditions?(y/n)\n");

        if(ans == 'y' || ans == 'Y')
        {
            printf("you have agreed.\n");
        }

        else if(ans == 'n' || ans == 'N')
        {
            printf("you have not agreed.\n");
        }
    }
    while(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
}
