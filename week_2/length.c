#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("What is your name? ");
    int n = strlen(name); // strlen() é uma função da bliblioteca <string.h>

    printf("%i\n", n);
}