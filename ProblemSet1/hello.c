#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Gets the user's name and puts it into a string variable
    string name = get_string("What is your name?\n");
    //Prints the message hello, _ into the terminal with the correct name
    printf("hello, %s\n", name);
}
