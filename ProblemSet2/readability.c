#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);
float avgLetters(int letters, int words);
float avgSentences(int sentences, int words);
float calcColeman(double avgLetters, double avgSentences);


int main(void)
{
    //Get input and store in string
    string input = get_string("Text: ");
    
    //Calculate number of letters, words, and sentences and store these numbers in variables
    int letters = count_letters(input);
    int words = count_words(input);
    int sentences = count_sentences(input);
    
    //Calculate the average letters and sentences per 100 words and store the values in variables
    float averageLetters = avgLetters(letters, words);
    float averageSentences = avgSentences(sentences, words);
    
    //Calculate the grade level using the average letters and sentences and round the result to the nearest integer
    float coleman = calcColeman(averageLetters, averageSentences);
    int rounded = roundf(coleman);
    
    //If the final grade level is less than 1 then print before grade level 1
    if (rounded < 1)
    {
        printf("Before Grade 1\n");
    }
    //If the final grade level is greater than or equal to 16 then print grade 16+
    else if (rounded >= 16)
    {
        printf("Grade 16+\n");
    }
    //Else print grade _ (with the correct rounded grade level)
    else
    {
        printf("Grade %i\n", rounded);
    }
}

//Calculates the grade level using the coleman-liau equation
float calcColeman(double avgLetters, double avgSentences)
{
    return 0.0588 * avgLetters - 0.296 * avgSentences - 15.8;
}

//Calculates the average letters per 100 words
float avgLetters(int letters, int words)
{
    return (((float) letters) / ((float) words)) * 100;
}

//Calculates the average sentences per 100 words
float avgSentences(int sentences, int words)
{
    return (((float) sentences) / ((float) words)) * 100;
}

//Counts the number of letters in the input string
int count_letters(string input)
{
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            count++;
        }
    }
    return count;
}

//Counts the number of words in the input strings
int count_words(string input)
{
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (isspace(input[i]))
        {
            count++;
        }
    }
    return count + 1;
}

//Counts the number of sentences in the input strings
int count_sentences(string input)
{
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if ('.' == input[i] || '!' == input[i] || '?' == input[i])
        {
            count++;
        }
    }
    return count;
}
