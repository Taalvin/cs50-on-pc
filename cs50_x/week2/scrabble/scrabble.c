#include <cs50.h>
#include <stdio.h>
#include <string.h>

int scores(int length, char word[]);
void result(int scores_1, int scores_2);

// Your program should determine the winner of a short Scrabble-like game.
// Your program should prompt for input twice:
// once for “Player 1” to input their word and once for “Player 2” to input their word.
// Then, depending on which player scores the most points,
// your program should either print “Player 1 wins!”, “Player 2 wins!”, or “Tie!”
// (in the event the two players score equal points).
int main(void)
{
    string word_1 = get_string("Player 1: ");

    string word_2 = get_string("Player 2: ");

    int length_1 = strlen(word_1);

    int length_2 = strlen(word_2);

    int scores_1 = scores(length_1, word_1);

    int scores_2 = scores(length_2, word_2);

    result(scores_1, scores_2);
}

// Calculates the scores of a word.
int scores(int length, char word[])
{
    int scores = 0;

    char point_1[] = {'a', 'e', 'i', 'l', 'n', 'o', 'r', 's', 't', 'u', 'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U'};

    char point_2[] = {'d' , 'g', 'D', 'G'};

    char point_3[] = {'b', 'c', 'm', 'p', 'B', 'C', 'M', 'P'};

    char point_4[] = {'f', 'h', 'v', 'w', 'y', 'F', 'H', 'V', 'W', 'Y'};

    char point_5[] = {'k', 'K'};

    char point_8[] = {'j', 'x', 'J', 'X'};

    char point_10[] = {'q', 'z', 'Q', 'Z'};

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (word[i] == point_1[j])
            {
                scores++;

                continue;
            }
        }

        for (int j = 0; j < 4; j++)
        {
            if (word[i] == point_2[j])
            {
                scores = scores + 2;

                continue;
            }
        }

        for (int j = 0; j < 8; j++)
        {
            if (word[i] == point_3[j])
            {
                scores = scores + 3;

                continue;
            }
        }

        for (int j = 0; j < 10; j++)
        {
            if (word[i] == point_4[j])
            {
                scores = scores + 4;

                continue;
            }
        }

        for (int j = 0; j < 2; j++)
        {
            if (word[i] == point_5[j])
            {
                scores = scores + 5;

                continue;
            }
        }

        for (int j = 0; j < 4; j++)
        {
            if (word[i] == point_8[j])
            {
                scores = scores + 8;

                continue;
            }
        }

        for (int j = 0; j < 4; j++)
        {
            if (word[i] == point_10[j])
            {
                scores = scores + 10;

                continue;
            }
        }
    }

    return scores;
}

// Prints the winner of the game(or tie).
void result(int scores_1, int scores_2)
{
    if (scores_1 > scores_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (scores_1 < scores_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
