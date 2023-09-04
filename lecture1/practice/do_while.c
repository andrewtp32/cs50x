#include <stdio.h>
#include <cs50.h>

int get_size(void)
{
	int n;
	
	do 
	{
		n = get_int("Size: "); 
	}
	while (n < 1);
	
	return n;
}

void print_grid(int size)
{
	for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				{
					printf("#");
				}
			printf("\n");
		}
}

int main(void)
{
	// get size of grid
	int n = get_size();
	
	// print the grid
	print_grid(n);	
}