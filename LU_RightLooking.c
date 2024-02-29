#include <stdio.h>
#include <stdlib.h>

#define N 4

void printMatrix(float A[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%.2f\t", A[i][j]);
        }
        printf("\n");
    }
}

void luDecomposition(float A[N][N]) {
    float L[N][N], U[N][N];

    // Initialize L and U matrices
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            L[i][j] = 0.0;
            U[i][j] = 0.0;
        }
    }

    // LU Decomposition with right-looking method
    for(int j = 0; j < N; j++) {
        printf("\n ## For j = %d\n", j);
        // L matrix
        L[j][j] = 1.0;
        for(int i = j + 1; i < N; i++) {
            L[i][j] = A[i][j] / A[j][j];
        }

        // U matrix
        for(int i = j; i < N; i++) {
            U[j][i] = A[j][i];
            printf("\n #### U matrix:\n");
            printMatrix(U);
            for(int k = 0; k < j; k++) {
                U[j][i] -= L[j][k] * U[k][i];
                printf("\n #### For k = %d, U matrix:\n", k);
                printMatrix(U);
            }
        }

        // Print L and U matrices
        printf("Step %d:\n", j + 1);
        printf("L matrix:\n");
        printMatrix(L);
        printf("\nU matrix:\n");
        printMatrix(U);
        printf("\n");
    }
}

int main() {
    // float A[N][N] = {{2, -1, 0}, {-1, 2, -1}, {0, -1, 2}};
    float A[N][N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            A[i][j] = rand() % 10 + 1; // Generate random integer between 1 and 10
        }
    }
    printf("Original matrix A:\n");
    printMatrix(A);
    printf("\n");

    luDecomposition(A);

    return 0;
}
