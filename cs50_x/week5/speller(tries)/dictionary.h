// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Number of alphabets.
#define N 26

// Amount of pre allocated nodes.
#define PRE 143091 * 9

// Creates a trie_node.
typedef struct trie_node
{
    bool exist;
    struct trie_node *links[N];
} trie_node;

extern trie_node pre_allocated_node[PRE];

// Prototypes
bool check(const char *word);
unsigned int hash(char word, int index);
bool initialize_trie_node(trie_node **n);
bool load(const char *dictionary);
unsigned int size(trie_node **p, unsigned int total);
bool unload(trie_node **p);

#endif // DICTIONARY_H
