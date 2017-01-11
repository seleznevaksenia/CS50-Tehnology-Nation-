#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define alph_len 26
int key(int t_len, string t); // make own funktion for key-word

int main(int argc, string argv[])
{
    //check lenth input
    if (argc != 2)
    {
        printf("Usage: ~workspace/pset2/caesar <key word>\n");
        return 1;
    }
    
    //check letters input
    string t = argv[1];
    for (int i = 0, len = strlen(t); i < len; i++)
    {
        if (!isalpha(t[i]))
        {
            printf("invalid\n");
            return 1;
        }
        
    }

        // take text
        string n = GetString();
        
         //cript text
        int t_len = 0;
           
    for (int i = 0, x = strlen(n); i < x; i++)
{
    if(isalpha(n[i]))
       {
          if (isupper(n[i]))
          {
             n[i] = (((n[i] - 'A') + key(t_len, t)) % alph_len) + 'A';
              printf("%c",n[i]);
              t_len++;
          }
          else 
          {
                n[i] = (((n[i] - 'a') + key(t_len, t)) % alph_len) + 'a';
                printf("%c",n[i]);
                t_len++;
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
int key(int t_len, string t)
{
    int length = strlen(t);
    return tolower(t[t_len % length]) - 'a';
}