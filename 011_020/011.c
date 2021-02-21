/**
 * Project Euler
 * Problem 011: Largest product in a grid
 */

#include <stdio.h>
#include <stdlib.h>

int right_side(int array[][20], int, int);
int left_side(int array[][20], int, int);



int main(void)
{
    int array[20][20];

    char *filename = "011_key.txt";
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Could not open file\n");
        return 1;
    }
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            char string[sizeof(int)];
            fgets(string, sizeof(string), fp);
            //printf("string is %s.\n", string);
            array[i][j] = atoi(string);
        }
    }
    fclose(fp);

    int largest = 0;

    for(int i = 0; i < 17; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(j < 17)
            {
                int product = right_side(array, i, j);
                largest = (product > largest) ? product : largest;
            }

            if(j > 2)
            {
                int product = left_side(array, i, j);
                largest = (product > largest) ? product : largest;
            }
        }
    }

    printf("Largest product is : %d.\n", largest);
}

int right_side(int array[][20], int i, int j)
{
    int product = 1;

    for(int k = 0; k < 4; k++)
    {
        product *= array[i+k][j+k];
    }
    return product;
}

int left_side(int array[][20], int i, int j)
{
    int product = 1;

    for(int k = 0; k < 4; k++)
    {
        product *= array[i+k][j-k];
    }
    return product;
}