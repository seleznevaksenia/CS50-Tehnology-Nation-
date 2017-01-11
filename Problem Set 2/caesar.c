#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define alph_len 26  //lenth alpha

int main(int argc, string argv[])
{
    
    //check input
    if (argc != 2)
    {
        printf("Usage: ~workspace/pset2/caesar <key>\n");
        return 1;
    }
    
    //convert input to int
    int k = atoi(argv[1]);
    
    //get text
    string n = GetString();
    
    //cript text
    for (int i = 0, x = strlen(n); i < x; i++)
{
    if(isalpha(n[i]))
       {
          if (isupper(n[i]))
          {
             n[i] = (((n[i] - 'A') + k) % alph_len) + 'A';
              printf("%c",n[i]);
          }
          else 
          {
                n[i] = (((n[i] - 'a') + k) % alph_len) + 'a';
                printf("%c",n[i]);
          }
       }
    else
     {
      printf("%c",n[i]);
     }
} 
    printf("\n");
    return 0;
}