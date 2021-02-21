/**
 * Project Euler
 * Problem 003: Largest prime factor
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned long sum = 0;
    unsigned long number = 600851475143;
    unsigned long prime = 0;

    for(unsigned long i = 1; i <= sqrt(number); i++)
    {
        sum = 0;
        for(unsigned long j = 1; j <= sqrt(i); j += 2)
        {
            if(i % j == 0)
            {
                sum += j;
                //fprintf(stdout, "Sum is %4i.\n", sum);
            }
        }

        if(sum == 1 && number % i == 0)
        {
            prime = i;
            fprintf(stdout, "Prime factor of: %7lu.\n", prime);
        }

    }
    fprintf(stdout, "The largest prime number is: %lu.\n", prime);
}
