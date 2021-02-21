#include <stdio.h>
#include <cs50.h>

int collatz(int);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Please input a number in the command line.\n");
        return 1;
    }

    int n = atoi(argv[1]);

    if(n < 1)
    {
        printf("Please input a number.\n");
        return 2;
    }

    printf("The number of steps is: %d\n", collatz(n));
}

int collatz(int n)
{
    if(n == 1)
        return 0;
    else if(n % 2 == 0)
        return 1 + collatz(n / 2);
    else
        return 1 + collatz((3 * n) + 1);


    return -1;
}