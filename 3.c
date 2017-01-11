#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int k,a;
    do
    {
    printf("minutes:");
    a = GetInt();
    }
    while (a < 1);
    
    k = a*12;
    printf("bottles:%d \n", k);
}