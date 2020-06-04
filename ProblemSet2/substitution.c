#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool isValidKey(string key);
int countLetters(string str);
void encipher(string key, string plainText);
int indexOf(string haystack, char needle);

int main(int argc, string argv[])
{   
    //Make sure there are only 2 command line arguments and if not return 1
    if (argc != 2)
    {
        return 1;
    }

    //Call the isValidKey method to make sure the key is valid, and if it isn't, then we return 1
    if (argc == 2)
    {
        if (!isValidKey(argv[1]))
        {
            return 1;
        }
    }
    
    //Get the key and the input plain text
    string key = argv[1];
    string plainText = get_string("plaintext: ");
    //Then we call the encipher method
    encipher(key, plainText);
    
    
}

void encipher(string key, string plainText)
{
    //Create a char array to hold the string and a \0 at the end
    char finalString[strlen(plainText) + 1];
    //Create a lowercase and uppercase string
    string lowerAlpha = "abcdefghijklmnopqrstuvwxyz";
    string upperAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //Traverse through every character in plainText
    for (int i = 0; i < strlen(plainText); i++)
    {
        //If the character is lowercase, then we get its position in the lowercase alphabet and add the lowercase version of the character at that position
        //in the key to the next spot in the finalString array
        if (islower(plainText[i]))
        {
            int location = indexOf(lowerAlpha, plainText[i]);
            finalString[i] = tolower(key[location]);
        }
        
        //If the character is uppercase, then we get its position in the uppercase alphabet and add the uppercase version of the character at that position
        //in the key to the next spot in the finalString array
        else if (isupper(plainText[i]))
        {
            int location = indexOf(upperAlpha, plainText[i]);
            finalString[i] = toupper(key[location]);
        }
        
        //If it isn't a letter, then we just add it like it is in plaintext to the next spot in finalString array
        else
        {
            finalString[i] = plainText[i];
        }
    }
    //We set the last character in the finalString array to \0 to cut off the string
    finalString[strlen(plainText)] = '\0';
    //We convert the array to an actual string
    string toReturn = finalString;
    //We print the enciphered string
    printf("ciphertext: %s\n", toReturn);
}

//Returns the index of the char needle in the string haystack
int indexOf(string haystack, char needle)
{
    for (int x = 0; x < strlen(haystack); x++)
    {
        if (haystack[x] == needle)
        {   
            return x;
        }
    }
    return -1;
}

//Returns true if the key is valid and false otherwise
bool isValidKey(string key)
{
    //Return false if the length of the key is 26
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    //We make sure for every character there is exactly 1 match. In total there should be 26 matches. Otherwise return false.
    int match = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (tolower(key[j]) == c)
            {
                match++;
                break;
            }
        }
    }
    
    if (match != 26)
    {
        printf("Key must contain one of every character.\n");
        return false;
    }

    //Return true if the key is valid
    return true;
}

