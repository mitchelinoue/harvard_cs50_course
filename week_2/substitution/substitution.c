#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

bool quantity(int n);
bool alphanumeric(string key, int n);
bool unique(string key, int n);

int main(int argc, string argv[])
{
    string key;
    int n;

    if (argc != 2)
    {
        printf("Usage: %s KEY\n", argv[0]);
        return 1;
    }

    key = argv[1];
    n = strlen(key);
    if (!quantity(n))
    {
        printf("Key must contain 26 character.\n");
        return 1;
    }

    if (!alphanumeric(key, n))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    if (!unique(key, n))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int m = strlen(plaintext);
    printf("ciphertext: ");

    for (int i = 0; i < m; i++)
    {
        if (plaintext[i] > 96 && plaintext[i] < 123)
        {
            int c = plaintext[i] - 97;

            printf("%c", tolower(key[c]));
        }
        else if (plaintext[i] > 64 && plaintext[i] < 91)
        {
            int c = plaintext[i] - 65;

            printf("%c", toupper(key[c]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

bool quantity(int n)
{
    if (n != 26)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool alphanumeric(string key, int n)
{
    bool is_char = true;
    int index = 0;
    while (is_char == true && index < n)
    {
        if (isalpha(key[index]))
        {
            is_char = true;
            index++;
        }
        else
        {
            is_char = false;
        }
    }
    return is_char;
}

bool unique(string key, int n)
{
    bool is_unique = true;
    int index = 0;
    while (is_unique == true && index < n)
    {
        if (strchr(key, key[index]) == strrchr(key, key[index]))
        {
            is_unique = true;
            index++;
        }
        else
        {
            is_unique = false;
        }
    }
    return is_unique;
}
