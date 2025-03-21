// Implements a sorted list of numbers using a linked list.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Creation of node.
typedef struct node
{
    int number;
    struct node *link;
} node;

int main(int argc, char*argv[])
{
    node *list = NULL;

    // Adding elements to list.
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Error: Could not allocate memory for node n.\n");
            return 2;
        }
        n -> number = number;
        n -> link = NULL;

        if (list == NULL)
            list = n;
        else if (number <= list -> number)
        {
            n -> link = list;
            list = n;
        }
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr -> link)
            {
                // If next number is greater than (n -> number).
                if (number <= (ptr -> link) -> number)
                {
                    n -> link = ptr -> link;
                    ptr -> link = n;
                    break;
                }

                // If end of list is reached.
                else if (ptr -> link == NULL)
                {
                    ptr -> link = n;
                    break;
                }
            }
        }
    }

    // Print numbers.
    for (node *ptr = list; ptr != NULL; ptr = ptr -> link)
    {
        printf("%i\n", ptr -> number);
    }

    // Frees memory.
    node *ptr = list;
    while (ptr != NULL)
    {
        node *tmp = ptr;
        ptr = ptr -> link;
        free(tmp);
    }
}
