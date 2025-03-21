// Implements a dictionary's functionality with tries.
// CURRENTLY: 0.120s

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Root of tries.
trie_node *root;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    trie_node *ptr = root;
    for (int i = 0, word_length = strlen(word); i < word_length; i++)
    {
        // Hash code for char.
        unsigned int hash_code = hash(word[i], i);

        // Character of word is found.
        if (ptr->links[hash_code] != NULL)
            ptr = ptr->links[hash_code];

        // Character of word is NOT found.
        else
            return false;
    }
    return ptr->exist;
}

// Hashes character to a number.
unsigned int hash(const char word, int index)
{
    // Handles alphabets.
    if (isalpha(word))
        return ((toupper(word) - 'A') * index) % N;

    // Handles Numbers.
    else if (isdigit(word))
        return ((word - '0') * index) % N;

    // Handle other characters.
    else
        return (word * index) % N;
}

// Initialize a trie node.
bool initialize_trie_node(trie_node **n)
{
    // Creates First trie.
    *n = malloc(sizeof(trie_node));
    if (*n == NULL)
    {
        printf("Error: Could not create trie_node.");
        return false;
    }

    // Makes root's links point towards NULL.
    for (int i = 0; i < N; i++)
    {
        (*n)->links[i] = NULL;
    }
    return true;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    if (!initialize_trie_node(&root))
        return false;

    // Open dictionary.
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
        return false;

    // Inserts word into Trie.
    int pre_allocated_node_used = 0;
    int index = 0;
    int buffer_size = 10240;
    char buffer[buffer_size];
    trie_node *ptr = root;
    while (fread(&buffer, sizeof(char), buffer_size, fp))
    {
        for(int i = 0; i < buffer_size; i++)
        {
            // Starts processing new word.
            if (buffer[i] == '\n')
            {
                index = 0;
                ptr->exist = true;
                ptr = root;
                continue;
            }

            // Hash code for char.
            unsigned int hash_code = hash(buffer[i], index);
            index++;

            // Path does not exist.
            if (ptr->links[hash_code] == NULL)
            {
                // If there are still pre-allocated nodes left.
                if (pre_allocated_node_used < PRE)
                {
                    ptr->links[hash_code] = &pre_allocated_node[pre_allocated_node_used];
                    pre_allocated_node_used++;
                }

                // Creates new trie_node.
                else
                {
                    trie_node *n = NULL;
                    if (!initialize_trie_node(&n))
                        return false;

                    // links trie_node together.
                    ptr->links[hash_code] = n;
                }
            }
            ptr = ptr->links[hash_code];
        }
    }

    // Close dictionary.
    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(trie_node **p, unsigned int total)
{
    // If word is found.
    if ((*p)->exist == true)
        total++;

    // Recursive case.
    for (int i = 0; i < N; i++)
    {
        if ((*p)->links[i] != NULL)
            total = size(&(*p)->links[i], total);
    }

    // Base case.
    return total;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(trie_node **p)
{
    // Recursive case.
    for (int i = 0; i < N; i++)
    {
        if ((*p)->links[i] != NULL)
            unload(&(*p)->links[i]);
    }
    if (*p >= &pre_allocated_node[0] && *p < &pre_allocated_node[0] + PRE)
    {
        // Do not free pre-allocated nodes
        return true;
    }
    else
    {
        free(*p);
        *p = NULL;
        return true;
    }
}
