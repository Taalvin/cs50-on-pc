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

    int scores_1 = scores(strlen(word_1), word_1);

    int scores_2 = scores(strlen(word_2), word_2);

    result(scores_1, scores_2);
}

// Calculates the scores of a word.
int scores(int length, char word[])
{
    int scores = 0;

    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for (int i = 0; i < length; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            scores += points[word[i] - 'A'];
        }
        else if (word[i] >= 'a' && word[i] <= 'z')
        {
            scores += points[word[i] - 'a'];
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

