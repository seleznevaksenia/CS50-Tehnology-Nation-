#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, rows, space, hash;
    do
    {
        printf("height:");
        height = GetInt();
    }
    
        while (height < 0 || height > 23); 
        
    for (rows = 1; rows <= height; rows++)
    {
        for (space = (height-rows); space > 0; space--)
        {
            printf(" ");
        }
        for (hash = 1; hash <= (rows+1); hash++)
        {
            printf("#");
        }
        {
            printf("\n");
        }
    }
}
