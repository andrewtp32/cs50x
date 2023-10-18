// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CITIES 10

// ANSI color codes for boxed in letters
#define GREEN "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define RED "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET "\e[0;39m"

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(int sort_type);
void merge_sort(avg_temp temps[], int l, int r);
void merge(avg_temp Arr[], int lt, int mid, int rt);

int main(int argc, string argv[])
{
    // check if there was an argument
    if (argc != 2)
    {
        printf(RED "ERROR" RESET " Usage: ./wordle 'sort-alg-type' <- '1': Bubble sort, '2': Selection sort, '3': Merge sort\n");
        return 1;
    }

    // check if the user inputted a correct sort alg type
    int sort_type = 0;
    int argv1_int = atoi(argv[1]);
    if (argv1_int >= 1 && argv1_int <= 3)
    {
        sort_type = argv1_int;
    }
    else if (argv1_int < 1 || argv1_int > 3)
    {
        printf(RED "ERROR" RESET "'sort-alg-type' must be either: '1' - Bubble sort, '2' - Selection sort, '3' - Merge sort\n");
        return 1;
    }

    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities(sort_type);

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(int sort_type)
{
    if (sort_type == 1) // bubble sort
    {
        // set swap counter to a non-zero value
        int swap_counter = -1;

        // repeat until the swap counter is 0
        while (swap_counter != 0)
        {
            // reset swap count to 0
            swap_counter = 0;

            // look at each adjacent pair
            for (int i = 0; i < NUM_CITIES - 1; i++)
            {
                // if two adjacent elements are not in order, swap them and add one to the swap counter
                if (temps[i].temp < temps[i+1].temp)
                {
                    // swap
                    avg_temp temportary_holder = temps[i];
                    temps[i] = temps[i+1];
                    temps[i+1] = temportary_holder;

                    // add one to swap count
                    swap_counter++;
                }
            }
        }
    }
    else if (sort_type == 2) // selection sort
    {
        // find index of the last element of the list (aka, last)
        int last_index = NUM_CITIES - 1;

        // repeat until no unsorted elements remain (aka, while last != 0)
        while (last_index != 0)
        {
            // search unsorted part of the data to find smallest value
            int index_of_smallest_val;
            int smallest_val = 200;
            for (int i = 0; i < last_index + 1; i++)
            {
                if (temps[i].temp < smallest_val)
                {
                    smallest_val = temps[i].temp;
                    index_of_smallest_val = i;
                }
            }

            // swap the smallest value with the last element of the unsorted list
            avg_temp temportary_holder = temps[index_of_smallest_val];
            temps[index_of_smallest_val] = temps[last_index];
            temps[last_index] = temportary_holder;

            // substract the "last" variable by 1 (this is so we dont keep adding values to the end of the list)
            last_index--;
        }
    }
    else // merge sort
    {
        int arr_size = sizeof(temps) / sizeof(temps[0]);
        merge_sort(temps, 0, arr_size - 1);
    }
}

void merge(avg_temp Arr[], int lt, int mid, int rt)
{
    int i, j, k;
    int L1 = mid - lt +1;
    int L2 = rt - mid;
    avg_temp left[L1], right[L2]; // creating temporary arrays, additional memory needed

    for (i = 0; i < L1; i ++)
        left[i] = Arr[lt + i];

    for (j = 0; j < L2; j ++)
        right[j] = Arr[mid + 1 + j];

    i = j = 0;
    k = 1;
    while (i < L1 && j < L2)
    {
        if (left[i].temp <= right[j].temp)
        {
            Arr[k] = left[i];
            i++;
        }
        else
        {
            Arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < L1)
        Arr[k++] = left[i++];
    while (j < L2)
        Arr[k++] = right[j++];
}

void merge_sort(avg_temp Arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - 1) / 2;
        merge_sort(Arr, l, mid);
        merge_sort(Arr, mid, r);
        merge(Arr, l, mid, r);
    }
}
