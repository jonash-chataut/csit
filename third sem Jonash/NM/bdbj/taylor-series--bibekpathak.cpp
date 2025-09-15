#include <stdio.h>

// Function f(x, y) = x + y
double f(double x, double y) {
    return x + y;
}

// Derivative f'(x, y) = 1 + x + y
double df(double x, double y) {
    return 1 + x + y;
}

int main() {
    double x0, y0, x, h;
    int n, i;

    // Initial values
    printf("Compiled by Bibek Pathak\n");
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    printf("Enter number of steps: ");
    scanf("%d", &n);

    printf("\nStep-by-step values:\n");
    printf("x\t\ty\n");

    for (i = 0; i < n; i++) {
        double fx = f(x0, y0);
        double dfx = df(x0, y0);
        double y1 = y0 + h * fx + (h * h / 2.0) * dfx;
        x0 = x0 + h;
        y0 = y1;
        printf("%.4lf\t%.6lf\n", x0, y0);
    }

    return 0;
}

