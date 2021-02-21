#include <stdio.h>
#include <stdlib.h>


void function(int [][n]);

int main(void)
{
    int array [n][n];
    function(array);
}

void function(int [][n])
{
    printf("%d, %d", array[0][0], array[1][1]);
}
