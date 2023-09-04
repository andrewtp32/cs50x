#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("What is your name: ");
    printf("Before: %s\n", s);
    printf("After:  ");

    // for (int i = 0; i < strlen(s); i++) // (c)
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
        /* // (b)
        // if (s[i] >= 'a' && s[i] <= 'z') // (a)
        if (islower(s[i]))
        {
            // printf("%c", s[i] - 32); // (a) subtract 32 bc that will bring us to the uppercase ascii
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }
        */ // (b)
    }

    printf("\n");
}