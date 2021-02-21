#include <stdio.h>
#include <stdlib.h>


void function(int*, int*);

int main(void)
{
    int *x = malloc(4);
    *x = 1;
    int *y = malloc(4);
    *y = 2;

    function(x, y);

    printf("x is %d, y is %d.\n", *x, *y);
}

void function(int *x, int *y)
{
    int z = *y;
    *y = *x;
    *x = z;
}