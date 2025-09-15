#include <stdio.h>

#define N 5        // Grid size (N x N)
#define ITER 5     // Number of iterations

// Define constant source term f(x,y) = 100
double f(int i, int j, double h) {
    return 100.0;
}

int main() {
    double u[N][N], u_new[N][N];
    double h = 1.0 / (N - 1);  // Grid spacing

    // Initialize u and u_new arrays to 0 (including boundaries)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            u[i][j] = 0.0;
            u_new[i][j] = 0.0;
        }

    // Perform Jacobi iterations
    for (int iter = 0; iter < ITER; iter++) {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                u_new[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] +
                                      u[i][j+1] + u[i][j-1] -
                                      h * h * f(i, j, h));
            }
        }

        // Copy new values back into u
        for (int i = 1; i < N - 1; i++)
            for (int j = 1; j < N - 1; j++)
                u[i][j] = u_new[i][j];
    }

    // Print the resulting grid
    printf("Solution after %d iterations:\n", ITER);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%8.4f ", u[i][j]);
        printf("\n");
    }

    return 0;
}

