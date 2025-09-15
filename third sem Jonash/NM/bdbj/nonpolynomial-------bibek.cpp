#include <stdio.h>
#include <math.h>

int main() {
    int i, j, k, m, n;
    float a[20][20], b[20], z[20], x[20], fx[20];
    float sum, pivot, term;
    printf("\n-------------BIBEK PATHAK---------------\n");

    printf("Enter the number of data points:\n");
    scanf("%d", &n);
    printf("Enter the degree of polynomial to be fitted:\n");
    scanf("%d", &m);

    for (i = 0; i < n; i++) {
        printf("Enter the data points (xi, fxi) at i = %d:\n", i + 1);
        scanf("%f %f", &x[i], &fx[i]);
    }

    // Forming the normal equations (sum of powers of x)
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= m; j++) {
            sum = 0;
            for (k = 0; k < n; k++)
                sum += pow(x[k], i + j);
            a[i][j] = sum;
        }
    }

    // Forming the right-hand side of equations (sum of fx * powers of x)
    for (i = 0; i <= m; i++) {
        sum = 0;
        for (k = 0; k < n; k++)
            sum += fx[k] * pow(x[k], i);
        b[i] = sum;
    }

    // Gaussian Elimination
    for (k = 0; k <= m; k++) {
        pivot = a[k][k];
        if (fabs(pivot) < 0.000001) {
            printf("Method failed!\n");
            return 1;
        }
        for (i = k + 1; i <= m; i++) {
            term = a[i][k] / pivot;
            for (j = 0; j <= m; j++) {
                a[i][j] -= a[k][j] * term;
            }
            b[i] -= b[k] * term;
        }
    }

    // Back-substitution
    z[m] = b[m] / a[m][m];
    for (i = m - 1; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j <= m; j++) {
            sum += a[i][j] * z[j];
        }
        z[i] = (b[i] - sum) / a[i][i];
    }

    // Printing the polynomial
    printf("The polynomial regression equation is:\n");
    printf("y = %.3f", z[0]);
    for (i = 1; i <= m; i++) {
        printf(" + %.3fx^%d", z[i], i);
    }
    printf("\n");

    return 0;
}

