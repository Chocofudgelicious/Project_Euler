/**
	Project Euler
	Problem 015: Lattice paths
	*/

#include <stdio.h>

#define n 18


unsigned long long calculate_grid(int, int, unsigned long long array[][n + 1]);

int main(void)
{

	unsigned long long array[n][n + 1];
	unsigned long long sum = calculate_grid(n - 1, n, array);


	printf("The total is: %llu.\n", sum * 2);
	return sum * 2;
}

unsigned long long calculate_grid(int i, int j, unsigned long long array[][n + 1])
{
	if (i == 0 || j == 0)
	{
		array[i][j] = 1;
	}
	else
	{
		array[i][j] = calculate_grid(i - 1, j, array) + calculate_grid(i, j - 1, array);
	}

	return array[i][j];
}

