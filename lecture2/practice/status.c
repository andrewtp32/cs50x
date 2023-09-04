#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1; // error code. use "echo $?" in command line (after executing program) to view the return of main.
    }
    else
    {
        printf("hello, %s\n", argv[1]);
        return 0; // if it goes well. use "echo $?" in command line (after executing program) to view the return of main.
    }
}