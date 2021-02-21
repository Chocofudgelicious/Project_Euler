/**
 * Project Euler
 * Problem 004: Largest palindrome product
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int main(void)
{

    int array[7];
    int digits = 0;
    unsigned int largest = 0;

    for(int i = 100; i < 1000; i++)
    {
        for(int j = 100; j < 1000; j++)
        {
            unsigned int product = i * j;

            if(product > largest)
            {
                unsigned int product0 = product;
                bool test;
                for(int k = 1; k < 8; k++)
                {
                    if(product >= 1)
                    {
                        array[k-1] = product % 10;
                        product /= 10;
                    }
                    else
                    {
                        digits = k - 1;
                        k = 8;
                    }
                }

                for(int d = 0; d < digits/2; d++)
                {
                    test = (array[d] == array[digits - d - 1]) ? true : false;
                    if(!test)
                    {
                        d = digits/2;
                    }
                }

                if(test)
                {
                    largest = product0;
                }
            }
        }
    }
    fprintf(stdout, "%d.\n", largest);
}