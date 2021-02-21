/**
 * Project Euler
 * Problem 005: Smallest Multiple
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int);

int main(void)
{
    unsigned long max = 1;
    int factors = 11;
    unsigned long result = 0;

    for(int i = 1; i < factors; i++)
    {
        // if(is_prime(i))
        // {
        //     max *= i;
        //     if(i < factors/2)
        //     {
        //         max *= i;
        //     }
        //     fprintf(stdout, "current max is: %d.\n", max);
        // }

        max *= i;
    }



    for(unsigned long j = 1; j < max; j += 2520)
    {
        //fprintf(stdout, "test for %lu. ", j);
        bool test = true;
        for(int k = factors; k >= 1; k--)
        {
            float quotient = j % k;
            if(quotient != 0.0)
            {
                test = false;
                k = 0;
            }


        }
        if(test)
        {
            result = j;
            fprintf(stdout, "Result is %lu.\n", result);
            fprintf(stdout, "max is %lu. ", max);
            return 0;
        }
    }

}

bool is_prime(int n)
{
    int test = 0;
    bool result = true;
    for(int k = 1; k <= sqrt(n); k++)
    {
        if(n % k == 0)
        {
            test++;
        }

        if(test > 1)
        {
            result = false;
            return result;
        }
    }

    return result;
}