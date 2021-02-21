/**
Project Euler
Problem 014: Longest Collatz sequence
*/

#include <stdio.h>

unsigned int collatz(int);

int main(void)
{
	int limit = 0;
	printf("The longest Collatz chain between 1 and ? : ");
	scanf("%u", &limit);

	unsigned int longest_chain = 0;
	int largest = 0;

	for (int i = 1; i < limit; i++)
	{
		unsigned int temp = collatz(i);
		if (temp > longest_chain)
		{
			longest_chain = temp;
			largest = i;
		}
	}
	printf("The number with the longest chain is: %d, with the chain of %u.\n", largest, longest_chain);

}


unsigned int collatz(int n)
{
	unsigned int count = 0;

	if (n == 1)
		count = 0;
	else if (n % 2 == 0)
		count += collatz(n / 2) + 1;
	else
		count += collatz((3 * n) + 1) + 1;

	return count;
}