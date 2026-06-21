#include <stdio.h>

long long powerMod(long long base, long long exp, long long mod)
{
    long long result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main()
{
    int g, h, p;
    int found = 0;

    printf("===================================\n");
    printf("||      Discrete Logarithm       ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter base (g): ");
    scanf("%d", &g);

    printf("Enter value (h): ");
    scanf("%d", &h);

    printf("Enter modulus (p): ");
    scanf("%d", &p);

    for (int x = 0; x < p; x++)
    {
        if (powerMod(g, x, p) == h)
        {
            printf("\nDiscrete Logarithm = %d\n", x);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nDiscrete logarithm does not exist.\n");

    return 0;
}