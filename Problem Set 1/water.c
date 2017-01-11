#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("minutes:");
    int k, a = GetInt();
    k = a*12;
    printf("bottles:%d \n", k);
}