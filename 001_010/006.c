/**
 * Project Euler
 * Problem 006: Sum square difference
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int n;
    fprintf(stdout, "To what number should the program calculate? : ");
    scanf("%d", &n);
    fprintf(stdout, "The number is %d.\n", n);

    unsigned long long product = 0;
    unsigned int sum = 0;

    for(int i = 1; i <= n; i++)
    {
        product += i * i;
    }

    for(int j = 1; j <= n; j++)
    {
        sum += j;
    }

    sum *= sum;
    long long difference = sum - product;

    fprintf(stdout, "The sum of the squares is: %llu.\nThe square of the sum is %d.\nThe difference is: %lld.\n", product, sum, difference);
}