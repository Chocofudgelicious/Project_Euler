/**
 * Project Euler
 * Problem 009: Special Pythagorean triplet
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int);
bool is_square(float);
bool is_integer(float);

#define MAX 10000

int main(void)
{
    int sum = 0;
    unsigned long product = 0;

    for(int c = 1; c < MAX; c++)
    {
        for(int b = 2; b < c; b++)
        {
            float c_sq = c*c;
            //printf("c^2 = %f. ", c_sq);
            float b_sq = b*b;
            //printf("b^2 = %f. ", b_sq);
            float a = c_sq - b_sq;
            if(is_integer(a))
            {
                if(is_square(a))
                {
                    int a_int = (int)sqrt(a);
                    sum = a_int + b + c;
                    product = a_int * b * c;

                    printf("The triple\t%d\t%d\t%d has sum: %4d and product %lu.\n", b, a_int, c, sum, product);

                    if(sum >= 1200)
                    {
                        c = MAX;
                        b = c;
                    }
                }
            }
        }
    }
}


bool is_prime(int n)
{
    bool result = true;
    if(n == 1)
    {
        result = false;
        return result;
    }
    else
    {
        int test = 0;
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
    }
    return result;
}

bool is_square(float n)
{
    float root = sqrt(n);
    return (is_integer(root));
}

bool is_integer(float n)
{
    return (floorf(n) == n);
}