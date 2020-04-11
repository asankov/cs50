import sys
import csv

def main():
    if len(sys.argv) != 3:
        print("Invalid number of arguments.")
        return

    dataset, dna_sequence = sys.argv[1], sys.argv[2]

    with open(dataset, newline='') as csvfile:
        with open(dna_sequence, newline='') as dnafile:
            dna = dnafile.readlines()[0]

        reader = csv.DictReader(csvfile)
        for row in reader:
            found = True
            for key, value in row.items():
                if key == 'name':
                    name = value
                    continue

                if dna.count(key) > int(value):
                    continue

                if dna.find(key * int(value)) == -1:
                    found = False

            if found:
                print(name)
                return

        print("No match")

main()
