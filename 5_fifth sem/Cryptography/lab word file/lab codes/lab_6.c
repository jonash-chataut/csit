#include <stdio.h>

int main()
{
    int a, b, temp;

    printf("===================================\n");
    printf("||      Euclidean Algorithm      ||\n");
    printf("|| Compiled by :- Jonash Chataut ||\n");
    printf("===================================\n\n");

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    printf("\nGCD = %d\n", a);

    return 0;
}