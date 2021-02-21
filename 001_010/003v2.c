/**
 * Project Euler
 * Problem 003: Largest prime factor
 * version 2
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned long limit = 600851475143;
    unsigned long prime = 0;

    for(unsigned long i = 1; i <= sqrt(limit); i += 2)
    {
        if(limit % i == 0)
        {
            unsigned long sum = 0;
            for(unsigned long j = 1; j <= sqrt(i); j += 2)
            {
                if(i % j == 0)
                {
                    sum++;
                }

            }
            if(sum == 1)
            {
                prime = i;
            }
        }
    }

    fprintf(stdout, "The largest prime is %lu.\n", prime);
}