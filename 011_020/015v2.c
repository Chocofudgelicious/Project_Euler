/**
Project Euler
Problem 015: Lattice paths
Version 2
*/

#include <stdio.h>
#include <stdlib.h>

int *n;

void calculate_grid(int, unsigned long long array[][*n]);

int main(void)
{
	n = malloc(sizeof(int));
	printf("Size of the grid n x n (1 ~ 33) n = ");
	do
	{
		scanf("%d", n);
	}
	while(*n > 33);

	unsigned long long array[*n][*n];

	for(int i = 0; i < *n; i++)
	{
		if(i == 0)
		{
			array[i][i] = 1;
		}
		else
		{
			array[i][i] = 2*array[i - 1][i - 1] + array[i][i - 1];
		}

		if(i < *n - 1)
		{
			calculate_grid(i, array);
		}
	}

	unsigned long long sum = array[*n - 1][*n - 1] * 2;

	printf("The total is: %llu.\n", sum);

}

void calculate_grid(int i, unsigned long long array[][*n])
{
	for(int j = i + 1; j < *n; j++)
	{
		if(i == 0)
		{
			array[j][i] = 1;
		}
		else
		{
			array[j][i] = array[j - 1][i] + array[j][i - 1];
		}
	}
}

