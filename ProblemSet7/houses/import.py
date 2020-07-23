from cs50 import SQL
from sys import argv, exit
from csv import DictReader, reader

db = SQL("sqlite:///students.db")

if len(argv) < 2:
    print("Usage error, import.py characters.csv ")
    exit(1)

with open(argv[1], "r") as database:
        reader = DictReader(database)

        for row in reader:
            currentName = row['name'].split()
            if len(currentName) < 3:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", currentName[0], None, currentName[1], row['house'], row['birth'])
            else:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", currentName[0], currentName[1], currentName[2], row['house'], row['birth'])

