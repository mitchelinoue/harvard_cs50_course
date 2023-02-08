import csv
import requests
import datetime as dt
from dateutil.relativedelta import relativedelta


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    old_dict = {}
    new_dict = {}

    for row in reader:
        state = row['state']
        cases = int(row['cases'])
        if state not in old_dict:
            old_dict[state] = [cases]
            new_dict[state] = [cases]

        elif len(old_dict[state]) > 13:
            number = cases - old_dict[state][13]
            old_dict[state].pop(0)
            old_dict[state].append(cases)
            new_dict[state].pop(0)
            new_dict[state].append(number)

        else:
            number = cases - old_dict[state][len(old_dict[state]) - 1]
            old_dict[state].append(cases)
            new_dict[state].append(number)

    return new_dict


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        average_one = int(sum(new_cases[state][0:7]) / 7)
        average_two = int(sum(new_cases[state][7:15]) / 7)
        try:
            percent = ((average_two - average_one) / average_two) * 100
        except ZeroDivisionError:
            percent = 0
            
        print(f"{state} had a 7-day average of {average_two} and an increase of %.2f%%." % percent)


main()
