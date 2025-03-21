#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                // Adds pairs to pairs array.
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;

                // Updates pair count.
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0, k = 0, x, w, l; i < pair_count - 1; i++)
    {
        // Resets x.
        x = preferences[pairs[i].winner][pairs[i].loser];

        // Compares pairs[i].winner to elements after pairs[i].winner.
        for (int j = (i + 1); j < pair_count; j++)
        {
            // Checks if it is the largest value that showed up yet.
            if ((preferences[pairs[j].winner][pairs[j].loser] >
                 preferences[pairs[i].winner][pairs[i].loser]) &&
                preferences[pairs[j].winner][pairs[j].loser] > x)
            {
                // Stores pairs[j].winner(largest value yet) in memory.
                x = preferences[pairs[j].winner][pairs[j].loser];

                // Stores index of largest value yet in memory.
                k = j;

                // Stores the value of pairs[j] in memory.
                w = pairs[k].winner;
                l = pairs[k].loser;
            }
        }

        // If there is an element greater than pairs[i].winner, switch places.
        if (x != preferences[pairs[i].winner][pairs[i].loser])
        {
            // Edits the largest pairs[k].winner with original value.
            pairs[k].winner = pairs[i].winner;
            pairs[k].loser = pairs[i].loser;

            // Edits the original with largest.
            pairs[i].winner = w;
            pairs[i].loser = l;
        }
    }

    return;
}

// Checks for loops of edges.
bool loop_check(int pairs_index, int original_pairs_index)
{
    // Searches for match.
    for (int i = 0; i < pair_count; i++)
    {
        if ((locked[pairs[i].winner][pairs[i].loser] == true) &&
            (pairs[i].winner == pairs[pairs_index].loser))
        {
            // Base case 1.
            // If original_pairs_index is found, prevent loop from happening.
            if (i == original_pairs_index)
            {
                return false;
            }

            // Recursive case.
            // Returns bool back to the original function.
            // If origital_pairs_index is not found, continue searching in the
            // previous recursion.(Run-back / Explore all possible routes)
            if (loop_check(i, original_pairs_index) == true)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    // Base case 2.
    return true;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        locked[pairs[i].winner][pairs[i].loser] = loop_check(i, i);
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int counter = 0;

        // Checks column of locked array.
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                counter++;
            }
        }

        // If winner is found.
        if (counter == 0)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}
