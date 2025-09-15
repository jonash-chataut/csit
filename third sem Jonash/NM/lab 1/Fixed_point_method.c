#include <stdio.h>
#include <math.h>

// Function to evaluate the polynomial f(x)
float func(float x, int a3, int a2, int a1, int a0) {
    return (a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * x + a0);
}

// Rearranged equation for fixed-point iteration, x = g(x)
// Example: We rearrange f(x) = 0 into x = g(x)
// For f(x) = ax^3 + bx^2 + cx + d, we might choose g(x) = - (ax^3 + bx^2 + d) / c (just an example)
float g(float x, int a3, int a2, int a1, int a0) {
    return (-(a3 * pow(x, 3) + a2 * pow(x, 2) + a0) / a1); // Example transformation
}

int main() {
    int a3, a2, a1, a0;
    float x0, x1, E, Era;
    printf("*****Fixed Point Method*****\n Compilied by -> Bipana\n");
    // Input the coefficients for the cubic polynomial
    printf("Enter coefficients a3, a2, a1, and a0: \na3 = ");
    scanf("%d", &a3);
    printf("a2 = ");
    scanf("%d", &a2);
    printf("a1 = ");
    scanf("%d", &a1);
    printf("a0 = ");
    scanf("%d", &a0);
    // Input initial guess and error precision
    printf("Enter initial guesses and Error precision: \nx0 = ");
    scanf("%f", &x0);
    printf("Error(E) = ");
    scanf("%f", &E);

    // Fixed-Point Iteration loop
    while (1) {
        x1 = g(x0, a3, a2, a1, a0);  // Apply fixed-point iteration
        
        Era = fabs(x1 - x0) / fabs(x1);  // Calculate relative error

        if (Era < E) {  // If error is within tolerance
            printf("Root found: %f\n", x1);  // Print the root
            break;
        } else {
            x0 = x1;  // Update x0 for the next iteration
        }
    }

    return 0;
}

