#include <stdio.h>
#include <cs50.h>

void printLine(int n, int height);

int main(void)
{
    int height;
    //Prompts user for height input and uses a do-while to reject values greater than 8 or less than 1.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //Use a for loop to to call the printLines method for every line number up to height.
    for (int i = 1; i <= height; i++)
    {
        printLine(i, height);
    }
}

void printLine(int n, int height)
{
    //Find the number of spaces at the beginning of the line
    int begSpaces = height - n;
    //Use a for loop to print the correct number of spaces at the beginning of the line
    for (int x = 0; x < begSpaces; x++)
    {
        printf(" ");
    }
    //Use a for loop to print the correct number of spaces depending upon the line number
    for (int t = 0; t < n; t++)
    {
        printf("#");
    }
    //Print two spaces as the gap in the middle
    printf(" ");
    printf(" ");
    //Use a for loop to print the correct number of spaces depending upon the line number
    for (int t = 0; t < n; t++)
    {
        printf("#");
    }
    //Go to the next line
    printf("\n");
}
