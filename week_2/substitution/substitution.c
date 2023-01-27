#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    // get key
    string key;
    if (argc == 2)
    {
        key = argv[1];
        validate_key(key);
    }
    else if()




    else
    {
        printf("Usage: %s KEY", argv[0]);
    }

    // validate key

    // get plaintext

    //encipher

    // print ciphertext
}

bool validate_key(string key)
{
    int n = strlen(key);
    if (n != 26)
    {
        printf("Key must contain 26 chatacter.");
        retun 0;
    }
    else
    {
        bool is_char = true;
        int index = 0;
        while (is_char == true && index < n)
        {
            is_char = isalpha()
        }
        return is_char;
    }
}