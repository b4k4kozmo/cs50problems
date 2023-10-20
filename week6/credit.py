from cs50 import get_int


def main():
    while True:
        credit_card = get_int("Number: ")
        if credit_card >= 0:
            break

    if check_validity(credit_card):
        print_card_type(credit_card)
    else:
        print("INVALID")


def check_validity(credit_number):
    return checksum(credit_number)


def checksum(credit_number):
    sum = 0
    for i in range(len(str(credit_number))):
        if i % 2 == 0:
            sum += credit_number % 10
        else:
            digit = 2 * (credit_number % 10)
            sum += digit // 10 + digit % 10

        credit_number //= 10

    return sum % 10 == 0


def print_card_type(credit_number):
    if (credit_number >= 34e13 and credit_number < 35e13) or (
        credit_number >= 37e13 and credit_number < 38e13
    ):
        print("AMEX")
    elif credit_number >= 51e14 and credit_number < 56e14:
        print("MASTERCARD")
    elif (credit_number >= 4e12 and credit_number < 5e12) or (
        credit_number >= 4e15 and credit_number < 5e15
    ):
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
