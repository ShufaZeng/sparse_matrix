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

    // LU Decomposition with left-looking method
    for(int i = 0; i < N; i++) {
        printf("\n ## For i = %d\n", i);
        // U matrix
        for(int j = i; j < N; j++) {
            U[i][j] = A[i][j];
            for(int k = 0; k < i; k++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

        // L matrix
        for(int j = i + 1; j < N; j++) {
            L[j][i] = A[j][i];
            for(int k = 0; k < i; k++) {
                L[j][i] -= L[j][k] * U[k][i];
            }
            L[j][i] /= U[i][i];
        }
        // Print L and U matrices
        printf("L matrix:\n");
        printMatrix(L);
        printf("\nU matrix:\n");
        printMatrix(U);        
    }
}

int main() {
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
