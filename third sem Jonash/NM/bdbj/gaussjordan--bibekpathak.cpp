#include <stdio.h>

#define MAX 10

void printMatrix(float a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%8.4f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(float a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        // Make the diagonal element 1
        float diag = a[i][i];
        if (diag == 0) {
            printf("Mathematical Error: Division by zero.\n");
            return;
        }

        for (int j = 0; j <= n; j++) {
            a[i][j] /= diag;
        }

        // Make the other elements in column i zero
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = a[k][i];
                for (int j = 0; j <= n; j++) {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }

        printf("Step %d:\n", i + 1);
        printMatrix(a, n);
    }

    printf("The solution is:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, a[i][n]);
    }
}

int main() {
    float a[MAX][MAX];
    int n;
    printf("Compiled by Bibek Pathak\n\n");

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix coefficients row-wise (including constants):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("\nInitial Augmented Matrix:\n");
    printMatrix(a, n);

    gaussJordan(a, n);

    return 0;
}

