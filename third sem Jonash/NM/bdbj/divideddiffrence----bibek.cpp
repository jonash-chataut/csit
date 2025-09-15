#include <stdio.h>

// Function to calculate the divided difference table
void dividedDifference(double x[], double fx[], int n) {
    // Creating the divided difference table
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            fx[i] = (fx[i] - fx[i - 1]) / (x[i] - x[i - j]);
        }
    }
}

// Function to compute the interpolated value at xp using divided differences
double interpolate(double x[], double fx[], int n, double xp) {
    double result = fx[0];  // Initialize the result with the first term
    double term;

    for (int i = 1; i < n; i++) {
        term = fx[i];
        for (int j = 0; j < i; j++) {
            term *= (xp - x[j]);
        }
        result += term;  // Add each term to the result
    }

    return result;
}

int main() {
    int n;
    printf("\n-------------BIBEK PATHAK---------------\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Arrays to store the x values and f(x) values
    double x[n], fx[n];

    // Input the data points
    printf("Enter the data points (x and f(x)):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("f(x[%d]): ", i);
        scanf("%lf", &fx[i]);
    }

    // Read the value at which interpolation is needed
    double xp;
    printf("Enter the value of x at which interpolated value is needed (xp): ");
    scanf("%lf", &xp);

    // Step 1: Calculate the divided difference table
    dividedDifference(x, fx, n);

    // Step 2: Compute the interpolated value at xp
    double result = interpolate(x, fx, n, xp);

    // Output the result
    printf("The interpolated value at xp = %.2lf is: %.4lf\n", xp, result);

    return 0;
}

