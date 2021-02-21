/**
 * Project Euler
 * Problem 013: Large sum
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    short array[100][50];
    char *filename = malloc(20);
    printf("Please input the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        fprintf(stderr, "ERROR: Could not open %s.\n", filename);
        return 1;
    }

    free(filename);

    for(int i = 0; i < 100; i++)
    {
        for(int j = 49; j >= 0; j--)
        {
            int single_digit = fgetc(fp);
            if(single_digit == '\n')
            {
                array[i][j] = fgetc(fp) - '0';
            }
            else
            {
                array[i][j] = single_digit - '0';
            }
        }
    }
    fclose(fp);

    short result[55];
    int digits = 0;
    int adder = 0;

    for(int i = 0; i < 55; i++)
    {
        if(i < 50)
        {
            for(int j = 0; j < 100; j++)
            {
                adder += array[j][i];
            }
        }

        result[i] = adder % 10;
        adder /= 10;
        if(adder == 0)
        {
            digits = i;
            printf("The number has %d digits.\n", digits + 1);
            i = 55;
        }
    }

    for(int i = digits; i >= 0; i--)
    {
        printf("%d", result[i]);
    }
    printf("\n");
}