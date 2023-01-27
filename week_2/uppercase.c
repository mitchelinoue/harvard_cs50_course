#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");

    for (int i = 0; i <strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32); // segundo a tabela de valores de caractéres, maiúsculo está separado em 32 para o minúsculo
        }
        else
        {
            printf("%c", s[i]);
        }
    }


    // 2º modo de fazer uppercase

    printf("\n");

    string name = get_string("Before 2:");
    printf("After 2:  ");
    for (int i = 0, n=strlen(s); i < n; i++)
    {
        printf("%c", toupper(name[i]));
    }
    printf("\n");

}