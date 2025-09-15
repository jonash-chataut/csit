#include <stdio.h>
#include <math.h>

// Function to integrate
double f(double x)
{
    return exp(-x / 2); // Example: f(x) = e^(-x/2)
}

int main()
{
    double a, b;
    int i;
    // Input the integration limits
    printf("***Compiled by Jonash Chataut***\n");
    printf("Enter a and b: ");
    scanf("%lf %lf", &a, &b);

    // Predefined Gauss points and weights for n = 3
    double x[] = {-sqrt(3.0 / 5.0), 0.0, sqrt(3.0 / 5.0)};
    double w[] = {5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0};

    // Compute the integral using Gaussian Integration
    double integral = 0.0;
    for (i = 0; i < 3; i++)
    {
        double t = ((b - a) * x[i] + (b + a)) / 2.0; // Transform to [a, b]
        integral += w[i] * f(t);
    }
    integral *= (b - a) / 2.0; // Scale the result

    printf("Value of integration (%.2f to %.2f) = %.6f\n", a, b, integral);
    return 0;
}
