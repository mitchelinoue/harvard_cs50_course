# TODO
def main():
    card = get_card()

    sum_1 = 0
    for n in range(len(card) - 2, -1, -2):
        digits = int(card[n]) * 2
        if digits > 9:
           sum_1 += int(str(digits)[0])
           sum_1 += int(str(digits)[1])
        else:
            sum_1 += digits

    for m in range(len(card) - 1, -1, -2):
        sum_1 += int(card[m])

    sum_1_str = str(sum_1)
    length_card = len(card)
    zero_validation = sum_1_str[len(sum_1_str) - 1]

    if length_card == 15 and zero_validation == '0' and card[0] == '3' and (card[1] == '4' or card[1] == '7'):
        print("AMEX")

    elif length_card == 16 and zero_validation == '0' and card[0] == '5' and (card[1] == '1' or card[1] == '2' or card[1] == '3' or card[1] == '4' or card[1] == '5'):
        print("MASTERCARD")

    elif (length_card == 13 or length_card == 16) and zero_validation == '0' and card[0] == '4':
        print("VISA")

    else:
        print("INVALID")

def get_card():
    number = input("Card number: ")
    if len(number) == 13 or len(number) == 15 or len(number) == 16:
        return number
    else:
        print("INVALID")

main()