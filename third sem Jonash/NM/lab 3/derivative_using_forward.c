#include <stdio.h>
int main()
{
    int n, i;
    printf("***Compiled by Jonash Chataut***\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    if (n < 2)
    {
        printf("Error: At least 2 data points are required.\n");
        return 1;
    }

    double x[n], y[n];
    printf("Enter the data points (x, y):\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d], y[%d]: ", i, i);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double target_x;
    printf("Enter the point at which to compute the derivative: ");
    scanf("%lf", &target_x);

    int index = -1;
    // Find the index where x[i] <= target_x < x[i+1]
    for (i = 0; i < n - 1; i++)
    {
        if (x[i] <= target_x && target_x < x[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Error: The point x = %.2f is outside the range of the data.\n", target_x);
        return 1;
    }
    // Calculating the derivative using forward difference
    double h = x[index + 1] - x[index];
    double derivative = (y[index + 1] - y[index]) / h;
    printf("f'(%.2f) = %.6f\n", target_x, derivative);
    return 0;
}
