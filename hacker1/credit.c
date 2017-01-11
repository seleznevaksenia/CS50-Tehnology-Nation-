#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    printf("number:\n");
    long long card_number = GetLongLong();
    long long n = card_number;
    
    // start count card_digits
    int count = 0;
       
	while (n != 0)

	{
		n /= 10;
		count++;
	}
   int card_digits = count;

//    printf("%i\n", card_digits);
    
    // check card
        
    
    if (card_digits < 13 || card_digits >16 || card_digits == 14)
            printf("INVALID\n");
 
    if (card_digits == 15)
    {
        printf("AMEX\n");
    }
    if (card_number >= 5100000000000000 && card_number <= 5599999999999999)
    {
        printf("MASTERCARD\n");
    }
    if ((card_number >= 4000000000000 && card_number <= 4999999999999) || (card_number >= 4000000000000000 && card_number <= 4999999999999999))
    {
        printf("VISA\n");
	}
	// check card 1 part
	long long x = card_number;
	long long y = card_number;
	int summ;
	
	if (card_digits == 16)
	{
	    int count1 = 0;
	int rem;
	while (x != 0)
	{
	   rem = x % 10 * 2;
	  
	    count1 += rem;
	    x /= 100;
//	  printf("%i\n", count1);
	}
	
	 int count2 = 0;
	int rem1;
	y = y / 10;
	while (y != 0)
	{
	   rem1 = y % 10;
	  
	    count2 += rem1;
	    y /= 100;
//	   printf("%i\n", count2);
	}
    summ = count1 + count2;
	}
	
	// check card part 2
	if (card_digits == 13 || card_digits == 15)
	{
	    int count1 = 0;
	int rem;

	    while (x != 0)
	{
	   rem = x % 10 * 2;
	  
	    count1 += rem;
	    x /= 100;
//	    printf("%i\n", count1);
	}
	
	int count2 = 0;
	int rem1;

	    while (y != 0)
	{
	   rem1 = y % 10;
	  
	    count2 += rem1;
	    y /= 100;
//	    printf("%i\n", count2);
	}
	summ = count1 + count2;
	}
	
//	printf("%i\n", summ);
	
	if ((summ % 10) > 0)
	{
//	printf("invalid\n");
	}	
}