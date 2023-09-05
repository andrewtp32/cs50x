#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void print_in_binary(string message);

int main(void)
{
    // TODO
    string message = get_string("Message: ");

    // convert the given string into an array which every element resembles the ascii number of the equiveleent char in the string
    print_in_binary(message);

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void print_in_binary(string message)
{
    int len = strlen(message);
    // iterate through string
    for (int i = 0; i < len; i++)
    {
        int decimal_num = (int) message[i];
        // redefine the array every iteration of for loop (int message_int_arr[BITS_IN_BYTE]; doesnt do enough to reset it to default on its own. gotta add the {0, ... , 0} part)
        int message_int_arr[BITS_IN_BYTE] = {0, 0, 0, 0, 0, 0, 0, 0};
        // printf("%i", decimal_num);

        // convert decimal number into a binary number (represented as an array)
        for (int j = BITS_IN_BYTE - 1; decimal_num > 0; j--)
        {
            // assign the remainder value to the jth index
            message_int_arr[j] = decimal_num % 2;
            // printf("decimal: %i\n", decimal_num);
            // printf("binary : %i\n", message_int_arr[j]);
            decimal_num /= 2;
        }

        // iterate through the array and print based on the contents of the elements
        for (int k = 0; k < BITS_IN_BYTE; k++)
        {
            print_bulb(message_int_arr[k]);
        }
    printf("\n");
    }
}