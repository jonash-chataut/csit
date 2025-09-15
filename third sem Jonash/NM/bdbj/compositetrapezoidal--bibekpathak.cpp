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
    printf("Enter a, b, and n: ");
    scanf("%lf %lf %d", &a, &b, &n);

    if (n < 1) {
        printf("Error: n must be at least 1.\n");
        return 1;
    }
    // Compute step size
    double h = (b - a) / n;

    // Compute the integral using the Composite Trapezoidal Rule
    double integral = (f(a) + f(b)) / 2.0; // First and last terms
    for ( i = 1; i < n; i++) {
        integral += f(a + i * h);
    }
    integral *= h;
    printf("Integral from %.2f to %.2f = %.6f\n", a, b, integral);
    return 0;
}
