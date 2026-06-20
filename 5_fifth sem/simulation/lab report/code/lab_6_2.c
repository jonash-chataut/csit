/*Q.N. 2: WAP in C to generate 100 random numbers using Multiplicative Congruential Method where
X0=13, m =1000, a = 15 and c = 7. */

#include <stdio.h>
#define SIZE 100
int main()
{
    long x[SIZE];
    long m = 1000, a = 15, c = 7;
    int i;
    x[0] = 13;

    for (i = 0; i < SIZE - 1; i++)
    {
        x[i + 1] = (a * x[i] + c) % m;
    }
    printf("Generated 100 random numbers:\n\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%ld ", x[i]);
    }
    return 0;
}
