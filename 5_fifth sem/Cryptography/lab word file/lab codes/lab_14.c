#include <stdio.h>

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long modInverse(long long e, long long phi)
{
    long long d;

    for (d = 1; d < phi; d++)
    {
        if ((d * e) % phi == 1)
            return d;
    }

    return -1;
}

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
    long long p, q, n, phi;
    long long e, d;
    long long message;
    long long ciphertext, decrypted;

    printf("===================================\n");
    printf("||        RSA Algorithm          ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter prime number p: ");
    scanf("%lld", &p);

    printf("Enter prime number q: ");
    scanf("%lld", &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("Enter public exponent e: ");
    scanf("%lld", &e);

    if (gcd(e, phi) != 1)
    {
        printf("\nInvalid value of e.\n");
        return 0;
    }

    d = modInverse(e, phi);

    printf("\nPublic Key  = (%lld, %lld)\n", e, n);
    printf("Private Key = (%lld, %lld)\n", d, n);

    printf("\nEnter message: ");
    scanf("%lld", &message);

    ciphertext = powerMod(message, e, n);
    decrypted = powerMod(ciphertext, d, n);

    printf("\nEncrypted Message = %lld\n", ciphertext);
    printf("Decrypted Message = %lld\n", decrypted);

    return 0;
}