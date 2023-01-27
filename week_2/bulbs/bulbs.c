#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string phrase = get_string("Message: ");
    int bit_size = 8;

    for (int i = 0, n = strlen(phrase); i < n; i++)
    {
        int letter_number = phrase[i];
        int array[bit_size];
        for (int j = (bit_size - 1); j > 0; j--)
        {
            if (letter_number == 0 || letter_number % 2 == 0)
            {
                array[j] = 0;
            }
            else
            {
                array[j] = 1;
            }
            letter_number /= 2;
        }
        for (int k = 0; k < bit_size; k++)
        {
            print_bulb(array[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
