#include <stdio.h>

#define N 5
#define ITERATIONS 5

void initialize(double u[N][N]) {
    // Set boundary conditions
    for (int i = 0; i < N; i++) {
        u[0][i] = 100.0;       // Top boundary
        u[N - 1][i] = 0.0;     // Bottom boundary
        u[i][0] = 0.0;         // Left boundary
        u[i][N - 1] = 0.0;     // Right boundary
    }

    // Set interior points to 0
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            u[i][j] = 0.0;
        }
    }
}

void print_grid(double u[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6.2f ", u[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    double u[N][N], u_new[N][N];

    initialize(u);

    printf("Initial Grid:\n");
    print_grid(u);

    for (int iter = 1; iter <= ITERATIONS; iter++) {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                u_new[i][j] = 0.25 * (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1]);
            }
        }

        // Copy new values into u
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                u[i][j] = u_new[i][j];
            }
        }

        printf("After iteration %d:\n", iter);
        print_grid(u);
    }

    return 0;
}

