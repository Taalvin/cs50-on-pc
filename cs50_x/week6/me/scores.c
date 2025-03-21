//  Dynamically gets scores and produces an average score.

#include <stdio.h>
#include <stdlib.h>

// Linked-list setup.
typedef struct node
{
    int score;
    struct node *link;
} node;

int main(void)
{
    // Gets amount of subjects.
    int total = 0, sbj;
    printf("Amount of subjects: ");
    scanf("%d", &sbj);


    // Dynamically allocates memory for each score.
    node *list = NULL;
    for (int i = 0; i < sbj; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return 1;

        printf("Score %d: ", i);
        scanf("%d", &(n->score));

        total += n->score;
        n->link = list;
        list = n;
    }


    // Prints output.
    printf("Average: %.2f\n", total / (float) sbj);

    // Frees linked-list.
    node *tmp;
    while (list != NULL)
    {
        tmp = list;
        list = list->link;
        free(tmp);
    }
}