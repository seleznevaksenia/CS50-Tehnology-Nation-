/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"
typedef struct node
{
    bool word;
    struct node* children[27];
}
node;

node* root;

unsigned int words; 

void clear(node* next);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int length = strlen(word);
    node* next = root;
    for (int i=0; i < length; i++)
    {
        char c = tolower(word[i]);
        if (c == '\'')
        {
          c = 123;
        }
        struct node* newNode = next->children[c-97];
        if (newNode == NULL)
        {
            return false;
        }
        else
        {
            next = newNode;
        }
    }
     if (next->word == true)
    {
        return true;
    }
     return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */

bool load(const char* dictionary)
{
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    root = calloc(1, sizeof(node));
    node* next = root;
    for (char c = tolower(fgetc(dict)); c != EOF; c = fgetc(dict))
    {
      if (c == '\n')
        { 
            if (next != root)
              {
                words++;
                next->word = true;
                next = root;
              }
        }
      else
      {
          if (c == '\'')
          {
            c = 123;    
          }
          struct node* newNode = next->children[c-97];
          if (newNode == NULL)
          {
              next->children[c-97] = calloc(1, sizeof(node));
              next = next->children[c-97];
           }
           else
           {
               next = newNode;
           }
      }   
    }
    
    fclose(dict);
    // TODO
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
       return words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
 
void clear(node* next)
{
    for (int i = 0; i < 27; i++)
    {
        if (next->children[i] != NULL)
            {
            clear(next->children[i]);
            }
    }
     free(next);
}
 
 
 
bool unload(void)
{
    clear(root);
    // TODO
    return true;
}
