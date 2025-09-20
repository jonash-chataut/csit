#include <stdio.h>
#include <stdlib.h>
int count = 0;
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int gcd(int a, int b)
{
    if (b != 0)
    {
        return gcd(b, a % b);
    }
    else
    {
        return a;
    }
}
void toh(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        return; // base case
    }
    toh(n - 1, src, helper, dest);
    printf("%d Move disk %d from %c to %c\n", ++count, n, src, dest);
    toh(n - 1, helper, dest, src);
}
int main()
{
    printf("*****Recursion*****\n Complied by -> Jonash \n");
    int choice, n, a, b;
    while (1)
    {
        printf("1. Factorial\n2. Fibonacci\n3. GCD\n4. Tower of Hanoi\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &n);
            printf("Factorial of %d is %d\n", n, factorial(n));
            break;
        case 2:
            printf("Enter the number: ");
            scanf("%d", &n);
            printf("Fibonacci of %d is %d\n", n, fibonacci(n));
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
            break;
        case 4:
            printf("Enter the number of disks: ");
            scanf("%d", &n);
            toh(n, 'A', 'B', 'C');
            printf("Total number of moves: %d\n", count);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!!!\n");
        }
    }
    return 0;
}
