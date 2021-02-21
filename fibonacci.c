/**
 * Trying out a fibonacci program.
 * Calculating the nth number of the sequence.
 */

#include <stdio.h>

unsigned int fib(int);



int main(void)
{
    int n;
    printf("The nth number to calculate: ");
    scanf("%d", &n);

    printf("The %dth number is: %u.\n", n, fib(n));
}

unsigned int fib(int n)
{
    unsigned int result = 0;
    unsigned int a = 0;
    unsigned int b = 0;

    if(n < 1)
    {
        result = 0;
    }
    else if(n == 1 || n == 2)
    {
        result = 1;
    }
    else
    {
        a = fib(n - 2);
        b = fib(n - 1);
        result = a + b;
    }
    return result;
}
