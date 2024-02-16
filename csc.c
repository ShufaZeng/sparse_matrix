#include <stdlib.h>
#include <stdio.h>

// Define CSC matrix structure
typedef struct {
    double* val;    // Array of non-zero values
    int* row_ptr;   // Array of row pointers
    int* col_idx;   // Array of column indices
    int rows;       // Number of rows
    int cols;       // Number of columns
    int nnz;        // Number of non-zero elements
} CSCMatrix;

// Define vector structure
typedef struct {
    double* data;   // Array of elements
    int size;       // Size of the vector
} Vector;

// Function to perform matrix-vector multiplication
Vector csc_matrix_vector_multiply(CSCMatrix A, Vector v) {
    Vector result;
    result.size = A.rows;
    result.data = (double*)malloc(sizeof(double) * result.size);

    // Initialize result vector with zeros
    for (int i = 0; i < result.size; i++)
        result.data[i] = 0.0;

    // Perform matrix-vector multiplication
    for (int j = 0; j < A.cols; j++) {
        for (int k = A.row_ptr[j]; k < A.row_ptr[j + 1]; k++) {
            int i = A.col_idx[k];
            result.data[i] += A.val[k] * v.data[j];
        }
    }

    return result;
}

int main() {
    // Example CSC matrix
    CSCMatrix A;
    A.rows = 3;
    A.cols = 3;
    A.nnz = 4;
    double val[] = {1.0, 2.0, 3.0, 4.0};
    int row_ptr[] = {0, 1, 2, 4};
    int col_idx[] = {0, 1, 1, 2};
    A.val = val;
    A.row_ptr = row_ptr;
    A.col_idx = col_idx;

    // Example vector
    Vector v;
    v.size = 3;
    double data[] = {1.0, 2.0, 3.0};
    v.data = data;

    // Perform matrix-vector multiplication
    Vector result = csc_matrix_vector_multiply(A, v);

    // Output the result
    printf("Result: ");
    for (int i = 0; i < result.size; i++)
        printf("%f ", result.data[i]);
    printf("\n");

    // Free memory
    free(result.data);

    return 0;
}

