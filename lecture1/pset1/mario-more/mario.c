#include <cs50.h>
#include <stdio.h>

void print_spaces(int height, int row)
{
    int num_spaces = height - row;
    for (int i = 0; i < num_spaces; i ++)
    {
        printf(" ");
    }
}

void print_hashes(int row)
{
    for (int i = 0; i < row; i ++)
    {
        printf("#");
    }
}

int get_height()
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    return n;
}

void build_pyramid(int height)
{
    char hash = '#';
    // for loop each line
    for (int row = 1; row < height + 1; row++)
    {
        // print the spaces
        print_spaces(height, row);

        //print the hashes
        print_hashes(row);

        printf("  ");

        //print the hashes
        print_hashes(row);

        printf("\n");
    }
}

int main(void)
{
    // get user input (any int 1 through 8)
    int height = get_height();
    // printf("%i\n", height);

    // build pyramid (based on user input int)
    build_pyramid(height);
}