/**
 * Project Euler
 * Problem 008: Largest product in a series
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

int largest_product(short[], int);
bool check_zero(short[], int, int);
unsigned long long products(short[], int, int);
int count_letters(char *);

int main(void)
{
    char *string = malloc(MAX + 1);
    if(string == NULL)
    {
        fprintf(stderr, "Could not allocate memory to string.\n");
        return 1;
    }
    printf("Input digits(Maximum of %d digits): ", MAX);
    scanf("%s", string);
    //string = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

    short array[MAX];

    for(int i = 0; i < MAX; i++)
    {
        char c = *(string + i);
        // fprintf(stdout, "c is: %c.\n", c);
        array[i] = c - '0';
        // printf("Array[%d] is %d\n", i, array[i]);
    }
    free(string);

    int series;
    printf("Enter number of adjacent integers: ");
    do
    {
        scanf("%d", &series);
    }
    while(series > MAX);

    int result = largest_product(array, series);
    printf("The products of: ");
    for(int i = result; i < result + series; i++)
    {
        printf("%d ", array[i]);
    }
    printf("is: %llu.\n", products(array, result, series));

}

int largest_product(short array[], int series)
{
    unsigned long long largest = 0;
    int tag = 0;
    for(int i = 0; i < MAX - series + 1; i++)
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
    }
    return tag;
}

// Returns false if has no zero, else returns true.
bool check_zero(short array[], int start, int series)
{
    for(int i = start; i < start + series; i++)
    {
        if(array[i] == 0)
        {
            return true;
        }
    }
    return false;
}

unsigned long long products(short array[], int start, int series)
{
    unsigned long long result = 1;
    for(int i = start; i < start + series; i++)
    {
        result *= array[i];
    }
    return result;
}

int count_letters(char *string);
{
    int count = 0;
    for(int i = 0; *(string + i) != '\0'; i++)
    {
        count++
    }
    return count
}