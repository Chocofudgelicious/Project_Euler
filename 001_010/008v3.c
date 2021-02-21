/**
 * Project Euler
 * Problem 008: Largest product in a series
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 1000

int largest_product(unsigned short[], int);
bool check_zero(unsigned short[], int, int);
unsigned long long products(unsigned short[], int, int);
int count_letters(char *);

int digits = 0;
int new_zero = 0;

int main(void)
{
    char *string = malloc(MAX + 1);
    if(string == NULL)
    {
        fprintf(stderr, "Could not allocate memory to string.\n");
        return 1;
    }
    int file = 0;
    printf("Input via file or prompt? ('0' for file, '1' for prompt): ");
    scanf("%d", &file);
    if(file == 0)
    {
        char filename[20];
        printf("Input file name: ");
        scanf("%s", filename);
        // fprintf(stdout, "%s\n", filename);

        FILE *fp = fopen(filename, "r");
        if(fp == NULL)
        {
            fprintf(stderr, "ERROR: Could not open %s.\n", filename);
            return 1;
        }

        fgets(string, MAX + 1, fp);
        digits = count_letters(string);
        fclose(fp);

    }
    else
    {
        printf("Input digits(Maximum of %d digits): ", MAX);
        do
        {
            scanf("%s", string);
            digits = count_letters(string);
        }
        while(digits > MAX);
    }

    fprintf(stdout, "Digits: %d.\n", digits);
    unsigned short array[digits];

    for(int i = 0; i < digits; i++)
    {
        char c = *(string + i);
        // fprintf(stdout, "c is: %c.\n", c);
        array[i] = c - '0';
        // printf("Array[%d] is %d \t", i, array[i]);
    }

    free(string);

    int series;
    printf("Enter number of adjacent integers: ");
    do
    {
        scanf("%d", &series);
    }
    while(series > digits);

    int result = largest_product(array, series);
    printf("The products of: ");
    for(int i = result; i < result + series; i++)
    {
        printf("%d ", array[i]);
    }
    printf("is: %llu.\n", products(array, result, series));

}

int largest_product(unsigned short array[], int series)
{
    unsigned long long largest = 0;
    int tag = 0;
    for(int i = 0; i < digits - series + 1; i++)
    {
        if(!check_zero(array, i, series))
        {
            unsigned long long product_i = products(array, i, series);
            if(product_i > largest)
            {
                largest = product_i;
                tag = i;
            }
        }
        else
        {
            i = (new_zero < digits - series) ? new_zero : i;
        }
    }
    return tag;
}

// Returns false if has no zero, else returns true.
bool check_zero(unsigned short array[], int start, int series)
{
    for(int i = start; i < start + series; i++)
    {
        if(array[i] == 0)
        {
            new_zero = i + 1;
            return true;
        }
    }
    return false;
}

unsigned long long products(unsigned short array[], int start, int series)
{
    unsigned long long result = 1;
    for(int i = start; i < start + series; i++)
    {
        result *= array[i];
    }
    return result;
}

int count_letters(char *string)
{
    int count = 0;
    for(int i = 0; *(string + i) != '\0'; i++)
    {
        count++;
    }
    return count;
}