#include <stdio.h>
#include <math.h>
double f(double x) {
    return 1/(x+4); // Example: f(x) = 1/(x+4)
}

int main() {
    double a, b;
    int n,i;
    printf("**\tCompiled By Bibek Pathak\t**\n");
    // Input the integration limits and number of subintervals
    printf("Enter a, b, and n (n must be even): ");
    scanf("%lf %lf %d", &a, &b, &n);

    if (n < 2 || n % 2 != 0) {
        printf("Error: n must be even and at least 2.\n");
        return 1;
    }

    // Compute step size
    double h = (b - a) / n;

    // Compute the integral using the Composite Simpson's 1/3 Rule
    double integral = f(a) + f(b); // First and last terms
    for ( i = 1; i < n; i++) {
        double x_i = a + i * h;
        integral += (i % 2 == 1) ? 4 * f(x_i) : 2 * f(x_i); // Odd or even terms
    }
    integral *= h / 3;
    printf("Integral from %.2f to %.2f = %.6f\n", a, b, integral);

    return 0;
}

