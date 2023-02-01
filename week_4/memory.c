#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // using valgrind at the compiled program to see memory related bugs (index starting at 0 and not freeing malloc x)
    int *x = malloc(3 * sizeof(int));

    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
}