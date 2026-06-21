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
    long long p, g;
    long long a, b;
    long long A, B;
    long long keyA, keyB;

    printf("===================================\n");
    printf("|| Diffie-Hellman Key Exchange   ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter prime number (p): ");
    scanf("%lld", &p);

    printf("Enter primitive root (g): ");
    scanf("%lld", &g);

    printf("Enter private key of User A: ");
    scanf("%lld", &a);

    printf("Enter private key of User B: ");
    scanf("%lld", &b);

    A = powerMod(g, a, p);
    B = powerMod(g, b, p);

    keyA = powerMod(B, a, p);
    keyB = powerMod(A, b, p);

    printf("\nPublic Key of User A = %lld\n", A);
    printf("Public Key of User B = %lld\n", B);

    printf("\nShared Secret Key at User A = %lld\n", keyA);
    printf("Shared Secret Key at User B = %lld\n", keyB);

    if (keyA == keyB)
        printf("\nKey Exchange Successful.\n");
    else
        printf("\nKey Exchange Failed.\n");

    return 0;
}