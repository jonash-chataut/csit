#include <stdio.h>

// Function to calculate the Lagrange basis polynomial L(i, x)
double lagrange(double x[], double y[], int n, double xp) {
    double result = 0.0;

    // Loop over each data point and calculate L(i, x) * y[i]
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        result += term; // Add each term to the result
    }

    return result;
}

int main() {
    int n;
    printf("\n-------------BIBEK PATHAK---------------\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Arrays to store the x and f(x) values
    double x[n], y[n];

    // Input the data points (x and f(x))
    printf("Enter the data points (x and f(x)):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("f(x[%d]): ", i);
        scanf("%lf", &y[i]);
    }

    // Read the value of x at which interpolation is needed
    double xp;
    printf("Enter the value of x at which interpolated value is needed (xp): ");
    scanf("%lf", &xp);

    // Calculate the interpolated value at xp using Lagrange interpolation
    double result = lagrange(x, y, n, xp);

    // Output the result
    printf("The interpolated value at xp = %.2lf is: %.4lf\n", xp, result);

    return 0;
}

