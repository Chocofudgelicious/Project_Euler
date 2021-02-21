/**
 * Project Euler
 * Problem 005: Smallest multiple
 * Version 2
 */

#include <stdio.h>

#define MAX 9223372036854775807

unsigned long long lowest(int);

int main(void)
{
    int factor;
    fprintf(stdout, "What is your factor(between 1 ~ 42): ");
    do
    {
        scanf(" %d", &factor);
    }
    while(factor > 42);

    fprintf(stdout, "The lowest multiple of %d is: %llu.\n", factor, lowest(factor));
}

unsigned long long lowest(int factor)
{
    float quotient = 0.0;
    unsigned long long increment = 0;
    unsigned long long result = 0;

    if(factor == 1)
    {
        increment = 1;
    }
    else if(factor > 1)
    {
        increment = lowest(factor - 1);
    }

    for(unsigned long long i = increment; i < MAX; i+= increment)
    {
        quotient = i % factor;
        if(quotient == 0)
        {
            result = i;
            i = MAX;
        }
    }
    // fprintf(stdout, "The lowest multiple of %d is %llu.\n", factor, increment);
    return result;

}