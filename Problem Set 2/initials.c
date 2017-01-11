#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    //take text
    string text = GetString();
   // make first letter
    printf("%c", toupper(text[0]));
    //make all next
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ' && text[i+1] != '\0')
        {
          printf("%c", toupper(text[i+1]));
          i++;
        }
    }
    printf("\n");
}