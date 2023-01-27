// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string word = argv[1];
        printf("%s\n", replace(word));
        return 0;
    }
    else
    {
        printf("Missing command-line argument\n");
        return 1;
    }
}

string replace(string word)
{
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int letter_number = word[i];
        if (letter_number == 97)
        {
            word[i] = 54;
        }
        else if (letter_number == 101)
        {
            word[i] = 51;
        }
        else if (letter_number == 105)
        {
            word[i] = 49;
        }
        else if (letter_number == 111)
        {
            word[i] = 48;
        }
    }
    return word;
}
