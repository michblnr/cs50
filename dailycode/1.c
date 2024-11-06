#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int k = get_int("Input k value: ");
    
    int howmany = get_int("How many numbers do you wish to input: ");
    int LIST[(howmany)];
    bool isK = false;
    
    for (int i = 0; i < howmany; i++)
    {
        LIST[i] = get_int("Number: ");
    }
    
    for (int n = 0; n < howmany; n++)
    {
        for (int x = 0 ; x < howmany; x++)
        {
            if (LIST[n] != LIST[x])
            {
                if (LIST[n] + LIST[x] == k) 
                {
                    if (isK == false)
                    {
                        printf("TRUE");
                        isK = true;
                    }
                    
                }
            }
        }
    }
    if (isK == false) {printf("FALSE");}
}
    
