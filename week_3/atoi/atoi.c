#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO 528/
    int index = strlen(input);

    if (index <= 0)
    {
        return 0;
    }

    int number = input[index - 1] - 48;

    input[strlen(input) - 1] = input[strlen(input)];

    convert(input);

    return number + 
}