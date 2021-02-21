/**
 * Project Euler
 * Problem 002: Even Fibonacci numbers
 */

#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, sum = 2;

    for(int x = a + b; x < 4000000; x = a + b)
    {

        if(x % 2 == 0)
        {
            sum += x;
        }

        a = b;
        b = x;
    }

    fprintf(stdout, "The sum is %d.\n", sum);

}