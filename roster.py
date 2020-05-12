import sys
import csv
import cs50

db = cs50.SQL("sqlite:///students.db")


def main():
    if len(sys.argv) != 2:
        print("Usage: python roster.py HOUSENAME")
        return
    
    house = sys.argv[1]
    rows = db.execute("SELECT first, middle, last, house, birth FROM students WHERE house = ?", house)
    
    for row in rows:
        if row['middle']:
            name = f"{row['first']} {row['middle']} {row['last']}"
        else:
            name = f"{row['first']} {row['last']}"

        print(f"{name}, born {row['birth']}")
    
main()
