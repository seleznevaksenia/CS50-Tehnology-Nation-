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
        
    for (rows = 0; rows <= (height-1); rows++)
    {
        for (space = (height-rows-1); space > 0; space--)
            {
                printf(" ");
            }
        for (hash = 1; hash <= (rows+1); hash++)
            {
                printf("#");
            }
            {  
                printf("  ");
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
