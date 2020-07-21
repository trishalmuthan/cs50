from cs50 import get_string, get_int, get_float


def main():
    
    while True:
        ccNum = get_int("Number: ")
        if ccNum >= 0:
            break
        
    ccNumDigits = countDigits(ccNum)

    digits = []
    temp = ccNum
    for i in range(ccNumDigits):
        digits.append(temp % 10)
        temp = temp // 10
        
    valid = checkSum(digits)
    
    digits.reverse()
    
    if valid:
        if ccNumDigits == 15 and digits[0] == 3 and (digits[1] == 7 or digits[1] == 4):
            print("AMEX")
        elif ccNumDigits == 16 and digits[0] == 5 and (digits[1] == 1 or digits[1] == 2 or digits[1] == 3 or digits[1] == 4 or digits[1] == 5):
            print("MASTERCARD")
        elif (ccNumDigits == 16 or ccNumDigits == 13) and digits[0] == 4:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")
    
def countDigits(num):
    digits = 0
    while (num > 0):
        num = num // 10
        digits += 1
    return digits


def checkSum(digits):
    digitSum = 0
    for i in range(1, len(digits), 2):
        currentValue = 2 * digits[i]
        while currentValue > 0:
            digitSum += currentValue % 10
            currentValue = currentValue // 10
    
    sum2 = 0
    for j in range(0, len(digits), 2):
        sum2 += digits[j]
        
    result = sum2 + digitSum

    if result % 10 == 0:
        return True 
    else:
        return False
        
        
main()
