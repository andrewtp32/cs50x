// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // initialiaze booleans to check if each condition is met
    bool is_lowercase = false;
    bool is_uppercase = false;
    bool is_number = false;
    bool is_symbol = false;
    // iterate through for loop
    for (int i = 0, length = strlen(password); i < length; i++)
    {
        if (islower(password[i]))
        {
            is_lowercase = true;
        }
        else if (isupper(password[i]))
        {
            is_uppercase = true;
        }
        else if (isdigit(password[i]))
        {
            is_number = true;
        }
        else if (ispunct(password[i]))
        {
            is_symbol = true;
        }
        else
        {
            ;
        }
    }
    // return bool based on condition
    if (is_lowercase * is_uppercase * is_number * is_symbol == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
