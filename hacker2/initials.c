#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string text = GetString();
 
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((i == 0 && isalpha(text[0])) || (isalpha(text[i]) && isspace(text[i-1])))
        {
          printf("%c", toupper(text[i]));
        }
    }
   
    printf("\n");
    return 0;
}