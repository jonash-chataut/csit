#include <stdio.h>
#include <math.h>

#define MAX 10
#define EPSILON 0.001
#define MAX_ITER 100

int main() {
    int n, i, j, iter = 0;
    float a[MAX][MAX], b[MAX], x[MAX], x_new[MAX], error;
    printf("Compiled by Bibek Pathak\n");
    // Input number of equations
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    // Input coefficient matrix and constants
    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
        printf("b[%d]: ", i+1);
        scanf("%f", &b[i]);
    }

    // Initial guess
    printf("Enter initial guess values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i+1);
        scanf("%f", &x[i]);
    }

    printf("\nIter\t");
    for (i = 0; i < n; i++) printf("x[%d]\t\t", i+1);
    printf("\n");

    do {
        for (i = 0; i < n; i++) {
            float sum = b[i];
            for (j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            x_new[i] = sum / a[i][i];
        }

        // Print current iteration
        printf("%d\t", iter+1);
        for (i = 0; i < n; i++) {
            printf("%f\t", x_new[i]);
        }
        printf("\n");

        // Check for convergence
        error = 0;
        for (i = 0; i < n; i++) {
            error += fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }

        iter++;
    } while (error > EPSILON && iter < MAX_ITER);

    // Final result
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.6f\n", i+1, x[i]);
    }

    return 0;
}

