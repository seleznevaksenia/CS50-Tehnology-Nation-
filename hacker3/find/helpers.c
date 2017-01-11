/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
//#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
/*    for (int i = 0; i < n; i++)
        if (values[i] == value)
            return true;
            
    return false;            */
    
    int max = n;
    int min = 0;
    
    if (min > max)
        return false;
    
    while (max >= min)
    {
        int mid = (min + max) / 2;
        if (values[mid] == value)
            return true;
        else if (values[mid] > value)
            max = mid - 1;
        else
            min = mid + 1;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    int count = 0;
    
    do
    {
        count = 0;
    
        for (int i = 1; i < n; i++)
        {
            if (values[i] < values[i - 1])
            {
                int q = values[i];
                values[i] = values[i - 1];
                values[i - 1] = q;
                count++;
            }
        }
 /*   for (int i = 0; i < n; i++)
        {
            printf("%i ",values[i]);
        }
    printf("\n");      */
    }
    while (count != 0);
    
    return;
}
