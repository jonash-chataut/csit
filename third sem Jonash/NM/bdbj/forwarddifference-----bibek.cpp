#include <stdio.h>

// Function to calculate the factorial
long factorial(int num) {
    long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    printf("\n-------------BIBEK PATHAK---------------\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Arrays to store the x and f(x) values
    double x[n], fx[n], fd[n];

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

    // Calculate h and s
    double h = x[1] - x[0];
    double s = (xp - x[0]) / h;

    // Calculate the first forward differences
    for (int i = 0; i < n; i++) {
        fd[i] = fx[i];
    }

    // Calculate the forward differences
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            fd[j] = fd[j] - fd[j - 1];
        }
    }

    // Calculate the interpolated value
    double v = fd[0];  // Start with the first value of forward differences
    double p = 1;  // Initialize the multiplication factor

    // Apply the forward difference formula
    for (int i = 1; i < n; i++) {
        p *= (s - i + 1);  // Calculate p
        v += (fd[i] * p) / factorial(i);  // Add the contribution of each forward difference term
    }

    // Output the result
    printf("The interpolated value at xp = %.2lf is: %.4lf\n", xp, v);

    return 0;
}

