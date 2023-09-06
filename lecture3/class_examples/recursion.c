#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    // ends the ravelling of recursion. one the conditon is met, the unraveling begins.
    if (n <= 0)
    {
        return;
    }

    draw(n - 1);

    for (int i =0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}