#include <stdio.h>

void function(int [][2]);

int main(void)
{
    int array[2][2] = {{ 1, 2 }, { 3, 4 }};
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            fprintf(stdout, "%d %d is %p.\n", i, j, array[i]);
        }
    }

    // int *array2[1] = malloc(sizeof(int));
    // *array2 = &array[0];
    function(array);
}

void function(int array[][2])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            fprintf(stdout, "function() %d %d is %d.\n", i, j, array[i][j]);
        }
    }
}