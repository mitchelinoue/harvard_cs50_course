#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
       printf("Missing command-line argument\n");
       return 1; // número escondido que mostra se houve erro no resolver do programa
    }
    else
    {
        printf("hello, %s\n", argv[1]);
        return 0; // número escondido que mostra deu tudo certo ao rodar o programa
    }
}