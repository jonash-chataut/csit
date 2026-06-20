/* Q.N. 1: What is random number and what are its properties. WAP in C to generate 100 random numbers
using Linear Congruential Method where X0=11, m=100, a = 5 and c = 13.*/

#include <stdio.h>
#include <conio.h>
#define SIZE 100
int main()
{
    int x[SIZE], i;
    int m = 100, a = 5, c = 13;
    x[0] = 11;
    for (i = 0; i < 100; i++)
    {
        x[i + 1] = (a * x[i] + c) % m;
    }
    printf("Generation of random numbers using linear congruential method:\n");
    for (i = 0; i < 100; i++)
    {
        printf("%d\t", x[i]);
    }
    return 0;
}