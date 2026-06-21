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
    long long a, b, m;
    long long A, B, M;
    long long KA, KB;
    long long KMA, KMB;

    printf("===================================\n");
    printf("||   Man in the Middle Attack    ||\n");
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

    printf("Enter private key of Attacker M: ");
    scanf("%lld", &m);

    A = powerMod(g, a, p);
    B = powerMod(g, b, p);
    M = powerMod(g, m, p);

    KA = powerMod(M, a, p);
    KB = powerMod(M, b, p);

    KMA = powerMod(A, m, p);
    KMB = powerMod(B, m, p);

    printf("\nPublic Key of User A = %lld\n", A);
    printf("Public Key of User B = %lld\n", B);
    printf("Public Key of Attacker = %lld\n", M);

    printf("\nKey established by User A = %lld\n", KA);
    printf("Key established by User B = %lld\n", KB);

    printf("\nAttacker's Key with A = %lld\n", KMA);
    printf("Attacker's Key with B = %lld\n", KMB);

    printf("\nCommunication can be intercepted and modified by the attacker.\n");

    return 0;
}