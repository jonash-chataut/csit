#include <stdio.h>

int power(int x, unsigned int y, int p)
{
    int result = 1;

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

int main()
{
    int n;

    printf("===================================\n");
    printf("||    Primitive Root Finder      ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter a number: ");
    scanf("%d", &n);

    int phi_n = phi(n);

    int factors[100], count = 0;
    int temp = phi_n;

    for (int i = 2; i * i <= temp; i++)
    {
        if (temp % i == 0)
        {
            factors[count++] = i;

            while (temp % i == 0)
                temp /= i;
        }
    }

    if (temp > 1)
        factors[count++] = temp;

    printf("\nPrimitive Roots of %d are:\n", n);

    for (int g = 2; g < n; g++)
    {
        int flag = 1;

        for (int i = 0; i < count; i++)
        {
            if (power(g, phi_n / factors[i], n) == 1)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
            printf("%d ", g);
    }

    printf("\n");

    return 0;
}