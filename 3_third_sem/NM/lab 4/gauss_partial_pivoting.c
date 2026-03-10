#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void printMatrix(float a[MAX][MAX], float b[MAX], int n)
{
    printf("\t->Compiled by Jonash Chataut<-\n");
    printf("Augmented Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%8.4f ", a[i][j]);
        }
        printf("| %8.4f\n", b[i]);
    }
    printf("\n");
}

void gaussElimination(float a[MAX][MAX], float b[MAX], float x[MAX], int n)
{
    for (int k = 0; k < n - 1; k++)
    {
        // Partial Pivoting
        int maxRow = k;
        float maxVal = fabs(a[k][k]);
        for (int i = k + 1; i < n; i++)
        {
            if (fabs(a[i][k]) > maxVal)
            {
                maxVal = fabs(a[i][k]);
                maxRow = i;
            }
        }

        if (maxRow != k)
        {
            // Swap rows in matrix A
            for (int j = 0; j < n; j++)
            {
                float temp = a[k][j];
                a[k][j] = a[maxRow][j];
                a[maxRow][j] = temp;
            }
            // Swap in vector b
            float temp = b[k];
            b[k] = b[maxRow];
            b[maxRow] = temp;
        }

        // Forward Elimination
        for (int i = k + 1; i < n; i++)
        {
            float factor = a[i][k] / a[k][k];
            for (int j = k; j < n; j++)
            {
                a[i][j] -= factor * a[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

int main()
{
    printf("\t->Compiled by Jonash Chataut<-\n");
    int n;
    float a[MAX][MAX], b[MAX], x[MAX];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the matrix A (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the constants vector b (%d values):\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &b[i]);
    }

    gaussElimination(a, b, x, n);

    printf("\nSolution Vector x:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = %.4f\n", i, x[i]);
    }

    return 0;
}
