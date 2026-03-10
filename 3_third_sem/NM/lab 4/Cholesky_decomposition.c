#include <stdio.h>
#include <math.h>

#define MAX 10

// Function to perform Cholesky decomposition
void choleskyDecomposition(double A[MAX][MAX], double L[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            double sum = 0;

            if (j == i)
            { // Diagonal elements
                for (int k = 0; k < j; k++)
                    sum += pow(L[j][k], 2);
                L[j][j] = sqrt(A[j][j] - sum);
            }
            else
            {
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

// Function to display a matrix
void printMatrix(double matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%8.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("\t->Compiled by Jonash Chataut<-\n\t->Cholesky_Decomposition\n");
    int n;
    double A[MAX][MAX], L[MAX][MAX] = {0};
    

    printf("Enter the order of matrix (i.e. n x n): ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix (row-wise):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    // Check if matrix is symmetric
    int isSymmetric = 1;
    for (int i = 0; i < n && isSymmetric; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != A[j][i])
            {
                isSymmetric = 0;
                break;
            }

    if (!isSymmetric)
    {
        printf("Matrix is not symmetric. Cholesky decomposition not possible!! Try again.\n");
        return 1;
    }

    choleskyDecomposition(A, L, n);

    printf("Lower triangular matrix L (Cholesky factor):\n");
    printMatrix(L, n);

    return 0;
}
