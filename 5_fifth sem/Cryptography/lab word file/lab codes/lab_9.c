#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int phi(int n)
{
    int result = n;

    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;

            result -= result / p;
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}

long long powerMod(long long a, long long b, long long mod)
{
    long long result = 1;

    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % mod;

        a = (a * a) % mod;
        b /= 2;
    }

    return result;
}

int main()
{
    int a, n;

    printf("===================================\n");
    printf("||       Euler's Theorem         ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of n: ");
    scanf("%d", &n);

    if (gcd(a, n) != 1)
    {
        printf("\nEuler's Theorem is not applicable.\n");
        printf("gcd(%d, %d) != 1\n", a, n);
        return 0;
    }

    int totient = phi(n);
    long long result = powerMod(a, totient, n);

    printf("\nEuler Totient φ(%d) = %d\n", n, totient);
    printf("%d^%d mod %d = %lld\n", a, totient, n, result);

    if (result == 1)
        printf("\nEuler's Theorem Verified.\n");

    return 0;
}