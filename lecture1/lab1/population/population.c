#include <cs50.h>
#include <stdio.h>

int get_start_size_int(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);

    return n;
}

int get_end_size_int(int n)
{
    int m;
    do
    {
        m = get_int("End size: ");
    }
    while (m < n);

    return m;
}

int calc_num_years(int total, int end)
{
    int counter = 0;

    while (total < end)
    {
        total = total + (total / 3) - (total / 4);
        counter++;
    }

    return counter;
}

void print_num_years(int n)
{
    printf("Years: %i\n", n);
}

int main(void)
{
    // TODO: Prompt for start size
    int start_size = get_start_size_int();

    // TODO: Prompt for end size
    int end_size = get_end_size_int(start_size);

    // TODO: Calculate number of years until we reach threshold
    int num_years = calc_num_years(start_size, end_size);

    // TODO: Print number of years
    print_num_years(num_years);
}
