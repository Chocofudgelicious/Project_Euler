/**
 * Project Euler
 * Problem 009: Special Pythagorean triplet
 * Version 2
 */

#include <stdio.h>

int main(void)
{
    int problem = 1000;
    for(int c = problem / 2; c > 2; c--)
    {
        for(int b = problem - c - 1; b > 2; b--)
        {
            int a = problem - c - b;
            unsigned long product = a * b * c;
            if(a*a + b*b == c*c)
            {
                printf("For %d %d %d, the product is %lu.\n", a, b, c, product);
                return 0;
            }
        }
    }
}
