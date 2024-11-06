#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2 && argv[1] == NULL) // check if command line arg is exactly one and is openable
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r"); // read info from file

    typedef uint8_t BYTE;
    int jpegcount = 0;
    BYTE buffer[BLOCK_SIZE];
    bool firstjpg = true;
    FILE *currentfile;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, f) == BLOCK_SIZE)
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xff) == 0xe0))
        {
            if (firstjpg == true)
            {
                firstjpg = false;
            }
            else // close last jpg fle to write to new one if not first file
            {
                fclose(currentfile);
            }

            char *filename = malloc(8); // free enough space for xxx.jpg(\0)
            sprintf(filename, "%03i.jpg", jpegcount);
            jpegcount++;

            currentfile = fopen(filename, "w");
            fwrite(buffer, sizeof(buffer), 1, currentfile);
            free(filename);
        }
        else if (firstjpg == false) // keep writing to jpg file 
        {
            fwrite(buffer, sizeof(buffer), 1, currentfile);
        }
    }
}
