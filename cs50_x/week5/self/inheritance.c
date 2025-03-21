// This is a version of inheritance made by Taalvin Krishna Coolen.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct person
{
    char alleles[2];
    struct person *parents[2];
} person;

person *load_tree(unsigned int generations);
void print_tree(person *tree, unsigned int generations, unsigned int counter);
void free_tree(person *tree);
char allele_generator(void);

int main(int argc, char *argv[])
{
    // Forces user to input only 2 command-line arguements.
    if (argc != 2)
    {
        printf("Usage: ./inheritance number_of_generations(int)\n");
        return 1;
    }

    unsigned int generations = atoi(argv[1]);
    person *tree = NULL;
    srand(time(NULL));

    tree = load_tree(generations);
    print_tree(tree, generations, generations);
    free_tree(tree);
}

// Dynamically allocates memory for family
// tree and links all persons(nodes) together.
person *load_tree(unsigned int generations)
{
    person *tree = malloc(sizeof(person));
    if (tree == NULL)
    {
        printf("Error: Could not create a person(node).\n");
        return tree;
    }

    if (generations == 1)
    {
        tree->alleles[0] = allele_generator();
        tree->alleles[1] = allele_generator();
        tree->parents[0] = NULL;
        tree->parents[1] = NULL;
    }
    else
    {
        tree->parents[0] = load_tree(generations - 1);
        tree->parents[1] = load_tree(generations - 1);
        tree->alleles[0] = tree->parents[0]->alleles[rand() % 2];
        tree->alleles[1] = tree->parents[1]->alleles[rand() % 2];
    }
    return tree;
}

// Prints every member in the family tree.
void print_tree(person *tree, unsigned int generation, unsigned int counter)
{
    for (int i = 0; i < (counter - generation); i++)
        printf("    ");
    printf("Generation %i: blood type %c%c\n", generation, tree->alleles[0], tree->alleles[1]);

     
    {
    print_tree(tree->parents[0], generation - 1, counter);
    print_tree(tree->parents[1], generation - 1, counter);
    }
}

// Frees all the persons(nodes) in the family tree.
void free_tree(person *tree)
{
    if (tree->parents[0] != NULL)
    {
        free_tree(tree->parents[0]);
        free_tree(tree->parents[1]);
    }
    free(tree);
}

// Returns a random allele.
char allele_generator(void)
{
    char allele[] = {'A', 'B', 'O'};
    return allele[rand() % 3];
}
