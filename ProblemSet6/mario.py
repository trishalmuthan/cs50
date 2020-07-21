from cs50 import get_string, get_int, get_float


def main():
    # Prompts user for height input and repeats until valid input is found
    while True:
        height = get_int("Height: ")
        if height <= 8 and height > 0:
            break
    # Uses for loop to call printLine for every line number up to height
    for i in range(1, height+1):
        printLine(i, height)
    
    
def printLine(n, height):
    # Find the number of spaces at the beginning of the line and print the correct number of spaces
    begSpaces = height - n
    for j in range(begSpaces):
        print(" ", end="")
    # Print correct number of hashes depending on line number
    for k in range(n):
        print("#", end="")
    
    # Print two spaces as gap
    print(" ", end="")
    print(" ", end="")
    
    # Print correct number of hashes depending on line number
    for m in range(n):
        print("#", end="")
    
    # New line
    print()
    
    
main()
