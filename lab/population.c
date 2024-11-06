#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*get starting size of at least 9*/
    int startsize;
    int endsize;

    do
    {
        startsize = get_int("Start size: ");
    }
    while (startsize < 9);
    /*prompt for end size equal to or more than start size*/
    do
    {
        endsize = get_int("End size: ");
    }
    while (endsize < startsize);

    /*calculate number of years to reach end size & print value*/
    int years = 0;
    int n = startsize;

    do
    {
        n = n + (n / 3) - (n / 4);
        years++;
    }
    while (n  < endsize);

    printf("Years: %i\n", years);
}
