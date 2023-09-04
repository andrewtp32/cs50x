// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <string.h>
#include <stdio.h>

string replace(string input);

int main(int argc, string argv[])
{
    // check for if there is exatly one (1) command line arguement
    if (argc != 2)
    {
        printf("Incorrect amount of command-line arguements.\nMust input exactly one (1) command-line arguement.\n");
        return 1;
    }
    else
    {
        string output = replace(argv[1]);
        printf("%s\n", output);
        return 0;
    }
}

string replace(string input)
{
    // get length of the input string
    int length = strlen(input);
    // for loop through each index of the string
    for (int i = 0; i < length; i++)
    {
        // printf("%c\n", input[i]);
        // use switch statement to test if a character meets the vowel conditions
        switch (input[i])
        {
            case 'a':
                input[i] = '6';
                break;

            case 'e':
                input[i] = '3';
                break;

            case 'i':
                input[i] = '1';
                break;

            case 'o':
                input[i] = '0';
                break;

            default:
                break;
        }
    }
    return input;
}
