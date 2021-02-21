/**
 * Project Euler
 * Problem 012: Highly divisible triangular number
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX 20000

int check_divisors(unsigned long long);

int main(void)
{
    int n_divisors = 0;
    printf("Please enter the number of divisors: ");
    scanf("%d", &n_divisors);

    unsigned long long sum = 0;

    for(int i = 1; i < MAX; i++)
    {
        sum += i;
        int check = check_divisors(sum);
        // if(i > 10000)
        // {
        //     printf("The %dth triangle number has %d divisors.\n", i, check);
        // }

        if(check >= n_divisors)
        {
            printf("The %dth triangle number %llu has %d divisors.\n", i, sum, check);
            return 0;
        }

    }

}

int check_divisors(unsigned long long sum)
{
    int d_count = 0;
    for(int i = 1; i <= sqrt(sum); i++)
    {
        if(i == 1)
        {
            d_count += (sum == 1) ? 1 : 2;
        }
        else
        {
            if((sum % i) == 0)
            {
                if(i == sqrt(sum))
                {
                    d_count++;
                }
                else
                {
                    d_count += 2;
                }
            }
        }

    }
    return d_count;
}
