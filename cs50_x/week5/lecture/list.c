#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
} node;

#define LIST_SIZE 2

bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    node *list = NULL;

    // Add items to list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // add phrase to new node in list
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        // Populates node.
        n -> phrase = phrase;
        n -> next = NULL;

        // Addition of first node.
        if (list == NULL)
        {
            list = n;
            visualizer(list);
            continue;
        }
        list -> next = n;

        // Visualize list after adding a node.
        visualizer(list);
    }

    // Free all memory used
    if (!unload(list))
    {
        printf("Error freeing the list.\n");
        return 1;
    }

    printf("Freed the list.\n");
    return 0;
}

bool unload(node *list)
{
    // TODO: Free all allocated nodes
    node *tmp = list;
    while (tmp != NULL)
    {
        tmp = list -> next;
        free(list);
        list = tmp;
    }
    if (list == NULL)
        return true;
    else
        return false;
}

void visualizer(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
        list = list->next;
    }
    printf("+---------------------+\n\n");
}
