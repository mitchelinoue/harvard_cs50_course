import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py DATABASE_FILE SEQUENCE_FILE")

    # TODO: Read database file into a variable
    file_database = sys.argv[1]
    csv_list = []
    with open(f"{file_database}", "r") as file1:
        reader1 = csv.DictReader(file1)
        for row in reader1:
            csv_list.append(row)

    # TODO: Read DNA sequence file into a variable
    file_sequence = sys.argv[2]
    with open(f"{file_sequence}", "r") as file2:
        reader2 = csv.reader(file2)
        for row in reader2:
            sequence = row

    str_sequence = list(csv_list[0].keys())
    str_sequence.pop(0)

    # TODO: Find longest match of each STR in DNA sequence
    matches = []
    for i in range(0, len(str_sequence), 1):
        number = longest_match(sequence[0], str_sequence[i])
        matches.append(number)

    # TODO: Check database for matching profiles
    for i in range(0, len(csv_list), 1):
        str_list = list(csv_list[i].values())
        str_list.pop(0)
        str_list_int = [eval(i) for i in str_list]
        if str_list_int == matches:
            print(csv_list[i]["name"])
            return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
