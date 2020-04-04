// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 500;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int h = hash(word);

    node* n = table[h % N];
    if (n == NULL)
    {
        return false;
    }


    while(n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }

        n = n->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]);
    }
    return sum;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        fprintf(stderr, "cannot open file");
        return false;
    }
    char* word = malloc(sizeof(char)*LENGTH);
    while (fscanf(dict, "%s", word) != EOF)
    {
        node* n = malloc(sizeof(node));
        if (n == NULL)
        {
            fprintf(stderr, "not enough memory to allocate node.");
            return false;
        }

        strcpy(n->word, word);

        int i = hash(word) % N;

        if (table[i] == NULL)
        {
            table[i] = n;
        }
        else
        {
            n->next = table[i];
            table[i] = n;
        }
    }
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        node* n = table[i];
        while (n != NULL)
        {
            count++;
            n = n->next;
        }
    }
    
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node* n = table[i];
        while (n != NULL)
        {
            node* tounload = n;
            n = n->next;
            free(tounload);
        }
    }
    return true;
}
