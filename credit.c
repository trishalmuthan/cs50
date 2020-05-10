#include <stdio.h>
#include <cs50.h>

int countDigits(long num);
bool checkSum(int digits[], int length);

int main(void)
{
    //Gets input as a long while ccNum < 0
    long ccNum;
    do
    {
        ccNum = get_long("Number: ");
    }
    while (ccNum < 0);
    
    //Calls the countDigits method and stores it in a variable called ccNumDigits
    int ccNumDigits = countDigits(ccNum);
    
    //Creates an array of the size of ccNumDigits and adds every digit in the number to this array.
    int digits[ccNumDigits];
    long temp = ccNum;
    for (int i = 0; i < ccNumDigits; i++)
    {
        digits[i] = temp % 10;
        temp /= 10;
    }
    
    //Determine if it passes luhn's algorithm
    bool valid = checkSum(digits, ccNumDigits);
    
    
    //Reverse the array so we have better access to the digits at the beginning of the number
    int swap;
    int start = 0;
    int end = ccNumDigits - 1;
    while (start < end)
    {
        swap = digits[start];
        digits[start] = digits[end];
        digits[end] = swap;
        start++;
        end--;
    }
    
    //Check if it had passes luhn's algorithm
    if (valid)
    {
        //AMEX check parameters
        if ((ccNumDigits == 15) && (digits[0] == 3 && digits[1] == 7))
        {
            printf("AMEX\n");
        }
        
        //MASTERCARD check parameters
        else if ((ccNumDigits == 16) && ((digits[0] == 5) && (digits[1] == 1 || digits[1] == 2 || digits[1] == 3 || digits[1] == 4 || digits[1] == 5)))
        {
            printf("MASTERCARD\n");
        }
        
        //VISA check parameters
        else if ((ccNumDigits == 13 || ccNumDigits == 16) && (digits[0] == 4))
        {
            printf("VISA\n");
        }
        
        //None of the if statements are satisfied so we print invalid
        else
        {
            printf("INVALID\n");
        }
    }
    
    //It did not pass luhn's algorithm so we print invalid
    else
    {
        printf("INVALID\n");
    }
    
    
}

//Counts the number of digits in the given long num
int countDigits(long num)
{
    int digits = 0;
    while (num > 0)
    {
        num /= 10;
        digits++;
    }
    return digits;
}

//Determines whether a given array of digits is passes luhn's algorithm
bool checkSum(int digits[], int length)
{
    //Multiplies by 2 and adds all the digits of every other digit starting from the second to last digit going up
    int digitSum = 0;
    int currentValue;
    for (int x = 1; x < length; x += 2)
    {
        currentValue = 2 * digits[x];
        while (currentValue > 0)
        {
            digitSum += currentValue % 10;
            currentValue  /= 10;
        }
    }
    
    //Normally sums up all the other digits
    int sum2 = 0;
    for (int y = 0; y < length; y += 2)
    {
        sum2 += digits[y];
    }
    
    //Adds the two values together and returns true if the result ends with a 0, otherwise returns false
    int result = sum2 + digitSum;
    
    if (result % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
