#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) // check if a command line argument is present 
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if ((strlen(argv[1])) != 26) // check if its length is 26 characters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else // if equal to 26 chars, check if valid-
    {
        for (int n = 0; n < 26; n++)
        {
            if (!isalpha(argv[1][n])) // check if non letters present
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            for (int y = 0; y < 26; y++) // check if there are no repeated letters
            {
                if (y != n && argv[1][y] == argv[1][n])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
        
        char CIPHER[(26)];
        for (int x = 0; x < 26; x++) // input argv into cipher array
        {
            CIPHER[x] = argv[1][x];
        }
        
        string plaintext = get_string("plaintext: "); // prompt for plain text
        
        int ascii;
        printf("ciphertext: ");
    
        for (int i = 0, a = strlen(plaintext); i < a; i++) // output corresponding cipher text from plain text
        {
            if (plaintext[i] >= 'a' && plaintext[i] <= 'z') // lower case letters
            {
                ascii = (int) plaintext[i]; // get ascii value for letter
                printf("%c", tolower(CIPHER[ascii - 97]));
            }
            else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') // upper case letters
            {
                ascii = (int) plaintext[i];
                printf("%c", toupper(CIPHER[ascii - 65]));
            }
            else // if character is not alphabetical, output the character itself
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
}
