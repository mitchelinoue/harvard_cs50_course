#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc == 2 && only_digits(argv[1]))
    {
        int key = atoi(argv[1]);
        string message = get_string("plaintext: ");

        printf("ciphertext: ");

        for (int i = 0, n = strlen(message); i < n; i++)
        {
            printf("%c",rotate(message[i], key));
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
}

bool only_digits(string key)
{
    bool is_number = true;
    int n = strlen(key);
    int index = 0;
    while (is_number == true && index < n)
    {
        if (key[index] > 47 && key[index] < 58)
        {
            index++;
        }
        else
        {
            is_number = false;
        }
    }
    return is_number;
}

char rotate(char c, int n)
{
    if (c > 96 && c < 123)
    {
        c -= 97;
        c = (c + n) % 26;
        c += 97;
    }
    else if (c > 64 && c < 91)
    {
        c -= 64;
        c = (c + n) % 26;
        c += 64;
    }
        return c;
}