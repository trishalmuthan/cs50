from sys import argv, exit
from csv import DictReader, reader


def main():
    # Check command line args
    if len(argv) != 3:
        print("Usage error: dna.py database.csv sequence.txt")
        exit(1)

    # Open csv file
    with open(argv[1], "r") as database:
        # Make a reader on the database
        readData = reader(database)
        # Get first line of database (all the strs) except name
        strs = next(readData)[1:]
        # Open txt file
        with open(argv[2], "r") as sequence:
            # Read text into string
            s = sequence.read()
            nums = []
            # For every str in strs
            for seq in strs:
                # Append the max number of repetitions to a list
                nums.append(maxNum(seq, s))
        # Print the matching person or print no match
        match(readData, nums)


# Find max number of repetitions
def maxNum(seq, full):
    # Store length and make variables
    length = len(seq)
    currentMax = 0
    counter = 0
    # Traverse string until before you go out of bounds
    for i in range(0, len(full)-length+1):
        counter = 0
        # Check if current window is equal to sequence, if so increment counter and increase i by length to follow next window
        # Then use while loop to keep doing that while there are repetitions
        if full[i: i+length] == seq:
            counter += 1
            i += length
            while(full[i: i+length] == seq):
                counter += 1
                i += length
        # If the counter is higher than the current max number of repetitions, replace it
        if counter > currentMax:
            currentMax = counter
    # Return the max number of repetitions
    return currentMax


# Print the corresponding name or no match
def match(reader, nums):
    # Goes through every row in the csv file
    for row in reader:
        # Stores the name
        name = row[0]
        # Store all the numbers for the current row in a list
        values = []
        for val in row[1:]:
            values.append(int(val))
        # Compare the list from the counted values from the txt file and the current row list
        # If they are the same, we've found our person and we print and return
        if values == nums:
            print(name)
            return
    # We haven't found a match so we print No Match
    print("No Match")


main()
