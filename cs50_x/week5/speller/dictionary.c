// Implements a dictionary's functionality
/*
 TO DO: Implement all the basic features.
 TO DO: Improve the hash funcion.
 TO DO: Make it go faster than the cs50 team's version(i.e Make it go brrrrrr!).
*/

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26 * 26 * 26;

// Hash table.
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Searches for word.
    for (node *trv = table[hash(word)]; trv != NULL; trv = trv->next)
    {
        // If word is found.
        if (strcasecmp(word, trv->word) == 0)
            return true;
    }

    // Word is not found.
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // unsigned int hash_value = 0;
    // for (int i = 0, length = strlen(word); i < length; i++)
    // {
    //     hash_value += ((toupper(word[i]) - 'A') % 26) * (int) pow(26, i);
    // }
    // return hash_value % (int) pow(26, 4);
    // If word has one character.

    if (word[1] == '\0')
        return toupper(word[0]) - 'A';
    // If word has two characters.
    else if (word[2] == '\0')
        return ((toupper(word[0]) - 'A') + ((toupper(word[1]) - 'A') % 26) * 26);
    // If word has three characters.
    else if (word[3] == '\0')
        return ((toupper(word[0]) - 'A') + ((toupper(word[1]) - 'A') % 26) * 26 + ((toupper(word[2]) - 'A') % 26) * (26 * 26));
     // If word has four characters.
    else
        return ((toupper(word[0]) - 'A') + ((toupper(word[1]) - 'A') % 26) * 26 + ((toupper(word[2]) - 'A') % 26) * (26 * 26) + ((toupper(word[3]) - 'A') % 26) * (26 * 26 * 26));
}

void initialize_table(void)
{
    for (int i = 0; i < N; i++)
        table[i] = NULL;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    initialize_table();

    // Opens dictionary.
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
        return false;

    // Populates node and links them to table appropriately.
    char buffer[S];
    char word[LENGTH + 1];
    unsigned int index = 0, bytesRead;
    do
    {
        bytesRead = fread(buffer, sizeof(char), S, fp);
        for (int i = 0; i < bytesRead; i++)
        {
            // Processes word.
            if (buffer[i] != '\n')
            {
                word[index] = buffer[i];
                index++;
                continue;
            }

            // finalizes word.
            word[index] = '\0';

            // Resets index.
            index = 0;

            // Creating new node.
            node* n = malloc(sizeof(node));
            if (n == NULL)
                return false;

            // Populates node.
            strcpy(n->word, word);
            n->next = NULL;

            // Links node to table.
            int hashcode = hash(n->word);
            n->next = table[hashcode];
            table[hashcode] = n;
        }
    }
    while(bytesRead != 0);

    // Closes dictionary.
    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Iterates through table of linked-lists.
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (node *trv = table[i]; trv != NULL; trv = trv->next)
            count++;
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iteratively frees malloced nodes.
    node *ptr;
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            ptr = table[i];
            table[i] = ptr->next;
            free(ptr);
        }
    }
    return true;
}
