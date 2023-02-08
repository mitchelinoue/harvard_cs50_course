# TODO
def main():
    heigth = get_heigth()
    for i in range(heigth):
        print(" " * (heigth - (i + 1)), end = "")
        print("#" * (i + 1))


def get_heigth():
    while True:
        try:
            n = int(input("Heigth: "))
            if n > 0 and n < 9:
                return n
        except ValueError:
            print("Not an integer")

main()