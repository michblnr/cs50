#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int addition = 0;
    int multiplication = 0;
    int digit;

    long number = get_long("Number: "); // get credit card number

    long decnums = number;
    int position = 1;

    if (number >= pow(10, 17) || number <= pow(10, 12)) // reject number if not within 13 to 16 digit range
    {
        printf("INVALID\n");
    }
    else
    {
        do
        {
            digit = decnums % 10; // get last individual digit
            if (digit > 0)
            {
                if (position % 2 == 0) // check if digit position even
                {
                    if (digit * 2 <= 9) //check if digit x 2 is a single digit
                    {
                        multiplication += (digit * 2); // add to digits which will be multiplied

                    }
                    else
                    {
                        multiplication += 1 + ((digit * 2) % 10); // separate digits if larger than 9 and add them to multiplication variable
                    }
                }
                else // odd position and therefore the number which will solely be added
                {
                    addition += digit;
                }
            }

            decnums = decnums / 10; // remove last digit of card number
            position = position + 1; // counter for length of card number and position of digit
        }
        while (decnums > 0); // do loop until the last digit

        int checksum = addition + multiplication; // add multiplied and added integers

        int startnum;
        int decmod;

        if (checksum % 10 == 0) // see if checksum is correct
        {
            startnum = number / (pow(10, (position - 3))); // get left first two digits from card num
            if (startnum == 34 || startnum == 37) // american express cards start with 34 or 37
            {
                printf("AMEX\n");
            }
            else if (startnum > 50 && startnum < 56) // mastercard cards start with 51-56
            {
                printf("MASTERCARD\n");
            }
            else if (startnum / 10 == 4) // visa cards start with 4
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n"); // if none of these output invalid message
            }
        }
        else
        {
            printf("INVALID\n"); //output invalid messgae for incorrect checksum
        }
    }
}
