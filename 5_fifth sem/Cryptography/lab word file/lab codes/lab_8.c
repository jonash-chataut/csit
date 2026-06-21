#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long power(long long x, long long y, long long p)
{
    long long result = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            result = (result * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }

    return result;
}

int millerTest(long long d, long long n)
{
    long long a = 2 + rand() % (n - 4);
    long long x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return 1;

    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return 0;

        if (x == n - 1)
            return 1;
    }

    return 0;
}

int isPrime(long long n, int k)
{
    if (n <= 1 || n == 4)
        return 0;

    if (n <= 3)
        return 1;

    long long d = n - 1;

    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
    {
        if (!millerTest(d, n))
            return 0;
    }

    return 1;
}

int main()
{
    long long n;
    int k = 5;

    printf("===================================\n");
    printf("|| Miller-Rabin Primality Test   ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter a number: ");
    scanf("%lld", &n);

    if (isPrime(n, k))
        printf("\n%lld is Probably Prime.\n", n);
    else
        printf("\n%lld is Composite.\n", n);

    return 0;
}