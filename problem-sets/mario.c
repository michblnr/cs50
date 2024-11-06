#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do // prompt for height within range of 1 to 8 inclusive
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    int totalspaces = height;
    for (int row = 1; row < height + 1; row++) // loop for each row
    {
        totalspaces = totalspaces - 1;
        for (int spaces = totalspaces; spaces > 0; spaces--) // print spaces
        {
            printf(" ");
        }
        for (int x = 1; x < row + 1; x++) // print left side of hastag pyramid
        {
            printf("#");
        }
        printf("  "); // print double spaces in between hashtags
        for (int y = 1; y < row + 1; y++) // print left side of pyramid
        {
            printf("#"); 
        }
        printf("\n"); // next line
    }
}
