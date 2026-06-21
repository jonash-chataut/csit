#include <stdio.h>

int extendedGCD(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main()
{
    int a, b, x, y, gcd;

    printf("===================================\n");
    printf("|| Extended Euclidean Algorithm  ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    gcd = extendedGCD(a, b, &x, &y);

    printf("\nGCD = %d\n", gcd);
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    printf("\nVerification:\n");
    printf("%d(%d) + %d(%d) = %d\n", a, x, b, y, gcd);

    return 0;
}