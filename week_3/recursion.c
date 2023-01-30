#include <cs50.h>
#include <stdio.h>

void draw_heigh(int n);
void draw_width(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw_heigh(height);
}

void draw_heigh(int n)
{
    if (n <=0)
    {
        return;
    }

    draw_heigh(n - 1);

    draw_width(n);

    printf("\n");
}

void draw_width(int n)
{
    if (n <=0)
    {
        return;
    }

    draw_width(n - 1);

    printf("#");

}