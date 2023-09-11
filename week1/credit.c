#include <cs50.h>
#include <stdio.h>

// functions
long get_cc_number(void);
long checksum_func(long creditNumber);
void finalCheck(long checkSum, long creditNumber);

int main(void)
{
    long creditNumber = get_cc_number();
    long checkSum = checksum_func(creditNumber);
    finalCheck(checkSum, creditNumber);
}

long get_cc_number(void)
{
    long creditNum;
    do
    {
        creditNum = get_long("enter your credit card number: ");
    }
    while (creditNum <= 0);
    return creditNum;
}

long checksum_func(long creditNumber)
{
    long sum = 0;
    long lastDigit;
    long ccnum = creditNumber;

    while (ccnum > 0)
    {
        lastDigit = ccnum % 10;
        sum += lastDigit;
        ccnum = ccnum / 100;
    }
    ccnum = creditNumber / 10;
    long twoX;
    while (ccnum > 0)
    {
        lastDigit = ccnum % 10;
        twoX = lastDigit * 2;
        sum += (twoX / 10) + (twoX % 10);
        ccnum = ccnum / 100;
    }
    sum = sum % 10;
    if (sum == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void finalCheck(long checkSum, long creditNumber)
{
    long validCC = creditNumber;
    long digitFinder = 10;
    long length = 0;
    long firstDigit;
    long firstTwo;

    while (validCC > 0)
    {
        validCC /= 10;
        length++;
    }

    validCC = creditNumber;
    for (int i = 0; i < length - 2; i++)
    {
        digitFinder *= 10;
    }
    firstDigit = validCC / digitFinder;
    firstTwo = validCC / (digitFinder / 10);

    if (checkSum == 1)
    {
        if (length == 15 && (firstTwo == 34 || firstTwo == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (firstTwo > 50 && firstTwo < 56))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && firstDigit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}