/**
 * Project Euler
 * Problem 010: Summation of primes
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int);

int main(void)
{
    unsigned long long sum = 2;
    for(int i = 1; i < 2000000; i += 2)
    {
        if(is_prime(i))
        {
            sum += i;
        }
    }
    printf("%llu is the sum.\n", sum);
}


bool is_prime(int n)
{
    bool result = true;
    if(n <= 1)
    {
        result = false;
        return result;
    }
    else if(n % 2 == 0)
    {
        return false;
    }
    else
    {
        for(int k = 2; k <= sqrt(n); k++)
        {
            if(n % k == 0)
            {
                return false;
            }
        }
    }
    return result;
}