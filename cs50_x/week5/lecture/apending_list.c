// implements an appending list of numbers using a linked list.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Defining node.
typedef struct node
{
    int number;
    struct node *link;
} node;

void print_list(node *list);

int main(int argc, char *argv[])
{
    // Prevents the user from not putting in any command-line arguement.
    if (argc < 2)
    {
        printf("Usage: ./apending_list num_1 num_2 num_3...\n");
        return 1;
    }

    // Creates list.
    node *list = malloc(sizeof(node));
    if (list == NULL)
    {
        return 2;
    }
    list -> number = atoi(argv[1]);
    list -> link = NULL;
    node *ptr = list;
    for (int i = 2; i < argc; i++)
    {
        ptr -> link = malloc(sizeof(node));
        (ptr -> link) -> number = atoi(argv[i]);
        (ptr -> link) -> link = NULL;
        ptr = ptr -> link;
    }

    // Prints list.
    print_list(list);
    printf("\n");

    // Frees malloced memory.
    node *tmp = list;
    node *tmp2 = list;
    while (tmp != NULL)
    {
        tmp = tmp -> link;
        free(tmp2);
        tmp2 = tmp;
    }

    return 0;
}

void print_list(node *list)
{
    if(list != NULL)
    {
        printf("%i ", list -> number);
        print_list(list -> link);
    }
    return;
}
