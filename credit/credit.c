#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    int digits;
    int half_1;
    int half_2;
    do
    {
        card = get_long("Number: ");

        if (card < 10000000000000000 && card > 999999999999999)
        {
            digits = 16;
            half_1 = 8;
            half_2 = 8;
        }
        else if (card < 1000000000000000 && card > 99999999999999)
        {
            digits = 15;
            half_1 = 7;
            half_2 = 8;
        }
        else if (card < 10000000000000 && card > 999999999999)
        {
            digits = 13;
            half_1 = 6;
            half_2 = 7;
        }
    }
    while (card < 0);

    int sum1 = 0;
    int single_digit_1;
    long x = 10;
    long y = 100;

    for (int i = 0; i < half_1; i++)
    {
        single_digit_1 = ((card % y) / x) * 2;
        x *= 100;
        y *= 100;

        if (single_digit_1 >= 10)
        {
            sum1 += single_digit_1 % 10;
            sum1 += single_digit_1 / 10;
        }
        else
        {
            sum1 += single_digit_1;
        }

    }

    int sum2 = 0;
    int single_digit_2;
    long z = 1;
    long a = 10;

    for (int i = 0; i < half_2; i++)
    {
        single_digit_2 = (card % a) / z;
        z *= 100;
        a *= 100;
        sum2 += single_digit_2;

    }

    int sum = sum1 + sum2;

    if ((sum % 10 == 0) && digits == 15 && ((card % 1000000000000000) / 10000000000000 == 34
                                            || (card % 1000000000000000) / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if ((sum % 10 == 0) && digits == 16 && ((card % 10000000000000000) / 100000000000000 == 51
             || (card % 10000000000000000) / 100000000000000 == 52 || (card % 10000000000000000) / 100000000000000 == 53
             || (card % 10000000000000000) / 100000000000000 == 54 || (card % 10000000000000000) / 100000000000000 == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((sum % 10 == 0) && (digits == 13 || digits == 16)  && ((card % 10000000000000) / 1000000000000 == 4
             || (card % 10000000000000000) / 1000000000000000 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}