#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
    float cash;
   
        do
    {
        printf("H1! How much change do you want?\n");
        cash = GetFloat();
    }
     while (cash <= 0);
    
      
    int allcoins = round(cash*100);
   
    int left;
    
    int coin25 = allcoins / 25;
        left = allcoins % 25;
         
    int coin10 = left / 10;
        left = left % 10;
       
    int coin5 = left / 5;
        left = left % 5;
        
    int coin1 = left / 1;
        left = left % 1;
       
        
    int result1;
   result1 = coin25 + coin10 + coin5 + coin1;
   
    printf("%i\n", result1);
    
}
