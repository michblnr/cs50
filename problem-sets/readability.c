#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

// prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string gettext = get_string("Text: "); // prompt for text
    
    int letters = count_letters(gettext); // get letter, word and sentence count
    int words = count_words(gettext);
    int sentences = count_sentences(gettext);
    
    float L = ((float) letters / words) * 100.00; // calculate L and S value
    float S = ((float) sentences / words) * 100.00;
    
    float index = 0.0588 * L - 0.296 * S - 15.8; // calculate index value
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++) // if a letter is present add 1 to count
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) 
        {
            count += 1;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int x = 0, n = strlen(text); x < n; x++) // if a space is present add 1 to word count
    {
        if (text[x] == ' ')
        {
            count += 1;
        }
    }
    count += 1; // add one more to count for last word
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int y = 0, n = strlen(text); y < n; y++)
    {
        if (text[y] == '.' || text[y] == '?' || text[y] == '!') // add 1 to cunt if period, ? or ! is present
        {
            count += 1;
        }
    }
    return count;
}
