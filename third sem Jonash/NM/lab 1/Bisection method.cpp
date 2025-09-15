#include <stdio.h>
#include <math.h>

int a3, a2, a1, a0;

float func(float x) {
    return (a3 * x * x * x + a2 * x * x + a1 * x + a0);
}

int main() {
	printf("*****Bisection method*****\n Compilied by -> Bipana\n");
    float x0, x1, x2, E, Era;
    printf("Enter coefficients a3, a2, a1, and a0: \na3 = ");
    scanf("%d", &a3);
    printf("a2 = ");
    scanf("%d", &a2);
    printf("a1 = ");
    scanf("%d", &a1);
    printf("a0 = ");
    scanf("%d", &a0);
    printf("Enter initial guesses x0, x1 and Error precision: \nx0 = ");
    scanf("%f", &x0);
    printf("x1 = ");
    scanf("%f", &x1);
    printf("Error(E) = ");
	scanf("%f", &E);
    // Ensure the initial guesses have opposite signs, otherwise the method won't work.
    if (func(x0) * func(x1) > 0) {
        printf("The Bisection method cannot proceed with these initial guesses.\n");
        return 1;
    }

    while (1) {
        // Midpoint
        x2 = (x0 + x1) / 2;
        
        // Calculate the error
        Era = fabs((x2 - x1) / x2);
        
        if (Era < E) {
            printf("Root = %f\n", x2);
            break;
        }
        
        // Update the interval
        if (func(x0) * func(x2) < 0) {
            x1 = x2;
        } else {
            x0 = x2;
        }
    }

    return 0;
}

