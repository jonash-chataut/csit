#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void gaussElimination(float a[MAX][MAX], int n) {
    int i, j, k;
    float ratio, x[MAX];

    // Forward Elimination
    for (i = 0; i < n - 1; i++) {
        // Check for zero pivot element
        if (a[i][i] == 0.0) {
            printf("Mathematical Error: Division by zero.\n");
            exit(1);
        }

        for (j = i + 1; j < n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = 0; k <= n; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--) {
        x[i] = a[i][n];
        for (j = i + 1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    // Displaying Solution
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.3f\n", i + 1, x[i]);
    }
}

int main() {
    float a[MAX][MAX];
    int i, j, n;
    printf("\t Compiled by Jonash Chataut\n");

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    gaussElimination(a, n);

    return 0;
}

