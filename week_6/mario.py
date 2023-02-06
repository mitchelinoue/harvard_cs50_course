from cs50 import get_int


def main():
    heigth = get_heigth()
    for i in range(heigth):
        print("#" * heigth)


def get_heigth():
    while True:
        try:
            n = int(input("Heigth: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an integer")

main()