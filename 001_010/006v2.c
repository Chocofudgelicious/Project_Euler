/**
 * Project Euler
 * Problem 006: Sum square difference
 */

#include <stdio.h>
#include <math.h>
#include <time.h>

void difference(int);

int main(void)
{
    unsigned int n;
    fprintf(stdout, "To what number should the program calculate? : ");
    scanf("%d", &n);
    fprintf(stdout, "The number is %d.\n", n);

    clock_t start = clock();
    difference(n);
    clock_t stop = clock();

    printf("Elapsed: %4fms\n", (double)(stop - start) * 1000 / CLOCKS_PER_SEC);
}

void difference(int n)
{
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
    long long result = sum - product;

    fprintf(stdout, "The sum of the squares is: %llu.\n", product);
    fprintf(stdout, "The square of the sum is %d.\n", sum);
    fprintf(stdout, "The difference is: %lld.\n", result);
}