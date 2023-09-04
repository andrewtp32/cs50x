#include <cs50.h>
#include <stdio.h>
#include <string.h>

long get_card_number()
{
    long n = get_long("Number: ");
    return n;
}

long calc_check_sum(long num)
{
    // counter to check the digit that we're on
    int count = 1;
    // sums of the odd and even digits
    long odd_sum = 0;
    long even_sum = 0;

    // iterate through each digit
    do
    {
        // define the digit
        long digit = num % 10;
        // conditional to see what to do with the digit based on its position within the number
        if (count % 2 == 0) // even number
        {
            // printf("even digit: %ld\n", digit);
            long doubled_ = digit * 2;
            // iterate each digit from each doubled_ number and sum
            do
            {
                long doubled_digit = doubled_ % 10;
                even_sum = even_sum + doubled_digit;
            }
            while (doubled_ /= 10);
        }
        else
        {
            // printf("odd digit: %ld\n", digit);
            odd_sum = odd_sum + digit;
        }
        count++;
    }
    while (num /= 10);

    // printf("even sum: %ld, odd sum: %ld\n", even_sum, odd_sum);

    return even_sum + odd_sum;
}

void test(long num, int sum)
{
    // convert long into a string
    char num_string[50];
    sprintf(num_string, "%ld", num);

    // evaluate string
    int str_len = strlen(num_string);

    // printf("Num length: %i\nFirst digit: %c\nSecond digit: %c\nChecksum: %i\n", str_len, num_string[0], num_string[1], sum);

    if (str_len == 15 && sum % 10 == 0 && num_string[0] == '3' && (num_string[1] == '4' || num_string[1] == '7'))
    {
        printf("AMEX\n");
    }
    else if ((str_len == 13 || str_len == 16) && sum % 10 == 0 && num_string[0] == '4')
    {
        printf("VISA\n");
    }
    else if (str_len == 16 && sum % 10 == 0 && num_string[0] == '5' &&
             (num_string[1] == '1' || num_string[1] == '2' || num_string[1] == '3' || num_string[1] == '4' || num_string[1] == '5'))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    // get user input
    long card_num = get_card_number();

    // calculate checksum
    long sum = calc_check_sum(card_num);
    // printf("Checksum: %ld\n", sum);

    // check card length and starting digits
    test(card_num, sum);
}