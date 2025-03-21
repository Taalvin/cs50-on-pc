#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int vote;
} candidate;

int main(void)
{
    candidate president[4];

    president[0].name = "Trump";
    president[0].vote = 1000;

    president[1].name = "Kamala";
    president[1].vote = 1;

    president[2].name = "Obama";
    president[2].vote = 400;

    president[3].name = "Biden";
    president[3].vote = 0;

    int highest_vote_index = 0;

    for (int i = 0; i < 3; i++)
    {
        if (president[highest_vote_index].vote < president[i + 1].vote)
        {
            highest_vote_index = i + 1;
        }
    }

    printf("%s, is the next president.\n", president[highest_vote_index].name);
}
