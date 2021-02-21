/**
 * Project Euler
 * Problem 007: 10001st prime
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define U_32_MAX 2147483647;
bool is_prime(int);

int main(void)
{
    int n = 0;
    printf("Which is the nth prime number you wish to find? : ");
    scanf("%d", &n);

    int count = 1;
    int crawler = 3;

    while(count != n)
    {
        if(is_prime(crawler))
        {
            count++;
            //printf("%5dth prime number is: %d\n", count, crawler);
        }

        crawler += 2;
    }
    printf("%5dth prime number is: %d\n", count, crawler - 2);
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