# TODO
from cs50 import get_float

def main():
    cash = get_cash()

    quarters = calculate_quarters(cash)
    cash -= quarters * 0.25

    dimes = calculate_dimes(cash)
    cash -= dimes * 0.10


    nickels = calculate_nickels(cash)
    cash -= nickels * 0.05


    pennies = calculate_pennies(cash)
    cash -= pennies * 0.01

    coins = quarters + dimes + nickels + pennies

    print(f"{coins}")

def get_cash():
    while True:
        try:
            n = get_float("Change owed: ")
            if n > 0:
                return n
        except ValueError:
            print("Invalid Value")

def calculate_quarters(cash):
    quarters = int(cash / 0.25)
    return quarters

def calculate_dimes(cash):
    dimes = int(cash / 0.10)
    return dimes

def calculate_nickels(cash):
    nickels = int(cash / 0.05)
    return nickels

def calculate_pennies(cash):
    pennies = int(cash / 0.01)
    return pennies


main()