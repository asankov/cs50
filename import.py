import sys
import csv
import cs50

db = cs50.SQL("sqlite:///students.db")


def main():
    if len(sys.argv) != 2:
        print("Usage: python import.py FILENAME")
        return
    
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        
        for row in reader:
            names = row["name"].split(" ")
            first_name, middle_name, last_name = names[0], None, names[1]
            
            if len(names) == 3:
                middle_name = names[1]
                last_name = names[2]
                
            if middle_name:
                db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first_name, middle_name, last_name, row["house"], int(row["birth"]))
            else:
                db.execute("INSERT INTO students(first, last, house, birth) VALUES(?, ?, ?, ?)", first_name, last_name, row["house"], int(row["birth"]))
    
main()
