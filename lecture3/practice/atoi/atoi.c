#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
//Base case

    int len = strlen(input);
    if (len == 0) // base case is a known value/ending condition, and we know that when there's no values left in the string, there'll be no conversion needed.
                  // To know the base case, it's usefull to know your recursive case first.
    {
        return 0; // This returns zero, which will stop the recursive case. Because this value will be returned instead of the recursive case statement.
                  // The reason why it's zero is because 0 won't affect the final result
                  // Cause anything times zero is zero, and zero + num = num. (This will make sense once you see the recursive case)
    }

    // Recursive case

    int last_char = len - 1;          // index for last character, since computers start counting from 0, and the strlen() function gives you the number of elements.

    int num = input[last_char] - '0'; // The easiest way to convert a single character to the integer it represents is to subtract the value of '0' .
                                      // If we take '3' (ASCII code 51) and subtract '0' (ASCII code 48), we'll be left with the integer 3 , which is what we want.

    input[last_char] = '\0';          // Removes the element you just determined and saved in the num variable, so that the next character becomes the new last character and the string is shortened

    return num + 10*convert(input);   // Recursive return statement. Here's why it works:
                                      // Lets say there are 4 digits in the input string.
                                      // The first digit would be a thousandth, the second digit a hundreth, third digit a tenth, and the last digit would just be itself.
}                                     // When you add them all up, it makes it seem like you are placing each digit one after the other.
                                      // Example: 1456 is the same as 1*1000 + 4*100 + 5*10 + 6*1.
                                      // The formula in the recursive return statement defines the above.
                                      // Lets say there are 3 elements in the input array (ex:1, 2, 3). When this function is first invoked, the computer knows what num is (see line 52).
                                      // However, it doesn't know what the convert(input) part of the recursive return statement is yet.
                                      // Eventually, it gets 3 + 10*(2 + 10*(3 + 10*(0))). [original last character + 10*(new last character + 10*(etc.))]
                                      // 0 is returned when the length of the input array is zero. This is the base case defined earlier.
                                      // Which will stop the computer before it reaches the recursive statement: return num + 10*convert(input) again.
                                      // Any return statement (that's an int, for this function) defined prior to the recursive case will do that.
                                      // It's just that by returning 0, it won't affect the other values that the computer stored in memory
                                      // Once zero is returned, the computer has all the puzzle pieces [i.e., 3 + 10*(2 + 10*(3 + 10*(0)))] and can finally calculate.
                                      // The computer will then return this integer (the result) to the int main(void) function, where it will be outputted to the user.