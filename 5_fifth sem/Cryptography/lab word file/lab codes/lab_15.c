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

long long modInverse(long long a, long long mod)
{
    for (long long i = 1; i < mod; i++)
    {
        if ((a * i) % mod == 1)
            return i;
    }
    return 1;
}

int main()
{
    long long p, g, x, k, m;
    long long y, c1, c2, s, decrypted;

    printf("===================================\n");
    printf("||   ElGamal Cryptographic Sys   ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter prime number (p): ");
    scanf("%lld", &p);

    printf("Enter primitive root (g): ");
    scanf("%lld", &g);

    printf("Enter private key (x): ");
    scanf("%lld", &x);

    y = powerMod(g, x, p);

    printf("\nPublic Key (p, g, y) = (%lld, %lld, %lld)\n", p, g, y);

    printf("Enter message (m): ");
    scanf("%lld", &m);

    printf("Enter random key (k): ");
    scanf("%lld", &k);

    c1 = powerMod(g, k, p);
    c2 = (m * powerMod(y, k, p)) % p;

    s = powerMod(c1, x, p);
    decrypted = (c2 * modInverse(s, p)) % p;

    printf("\nCiphertext c1 = %lld\n", c1);
    printf("Ciphertext c2 = %lld\n", c2);
    printf("Decrypted Message = %lld\n", decrypted);

    return 0;
}