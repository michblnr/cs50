#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = get_int("how many numbers in list: ");
    int array1[(size)];
    int array2[(size)];
    
    for (int i = 0; i < size; i++)
    {
        array1[i] = get_int("Number %i: ", i + 1);
    }
    
    int product;
    
    for (int n = 0; n < size; n++)
    {
        product = 1;
        for (int x = 0; x < size; x++)
        {
            if (n != x)
            {
                product *= array1[x];
            }
            
        }
        array2[n] = product;
        printf("%i ", array2[n]);
    }
}
