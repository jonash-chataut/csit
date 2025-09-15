#include <stdio.h>

int main()
{
    int n, i, j;
    printf("***Compiled by Jonash Chataut***\n");
    printf("Enter number of data points: ");
    scanf("%d", &n);

    if (n < 2)
    {
        printf("Error: At least 2 data points are required.\n");
        return 1;
    }

    double x[n], y[n];
    printf("Enter (x, y) for each point:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d], y[%d]: ", i, i);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double a;
    printf("Enter the point to compute derivative: ");
    scanf("%lf", &a);

    // Compute divided differences
    double dd[n];
    for (i = 0; i < n; i++)
        dd[i] = y[i];
    for (i = 1; i < n; i++)
    {
        for (j = n - 1; j >= i; j--)
        {
            dd[j] = (dd[j] - dd[j - 1]) / (x[j] - x[j - i]);
        }
    }

    // Compute derivative at x = a
    double result = dd[1];
    for (i = 2; i < n; i++)
    {
        double term = dd[i];
        for (j = 0; j < i - 1; j++)
        {
            term *= (a - x[j]);
        }
        result += term;
    }

    printf("f'(%.2f) = %.6f\n", a, result);

    return 0;
}
