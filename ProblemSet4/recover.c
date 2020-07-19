#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Check for correct input
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    
    
    //Check if file opened properly
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    
    //Define a buffer array, an output file, a boolean to check if jpeg is open, an int for the filename, and a char array to store the filename
    BYTE buffer[512];
    FILE *outptr;
    bool isOpen = false;
    int numFile = 0;
    char filename[8];
    
    while (true)
    {
        //Read 512 bytes into buffer and check if we are at the end of the file (size < 1)
        int size = fread(buffer, sizeof(buffer), 1, inptr);
        if (size < 1)
        {
            break;
        }
        
        //If it is a new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If a jpeg is already open, close it
            if (isOpen)
            {
                fclose(outptr);
            }
            //store the new file name in filename array
            sprintf(filename, "%03i.jpg", numFile);
            //open and write the contents of the buffer array into a new jpeg file
            outptr = fopen(filename, "w");
            fwrite(buffer, sizeof(buffer), 1, outptr);
            //set isOpen to true and increment the file number by 1
            isOpen = true;
            numFile++;
        }
        //If it's not a new jpeg, write the contents of the buffer array into the already open file
        else
        {
            fwrite(buffer, sizeof(buffer), 1, outptr);
        }
    }
    
    //Close the input and output files
    fclose(inptr);
    fclose(outptr);
}
