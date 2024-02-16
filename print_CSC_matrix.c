#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    int nnz;
    double *val;
    int *row_ptr;
    int *col_idx;
} CSCMatrix;

void print_matrix(const CSCMatrix *matrix) {
    int i, j, k;
    int rows = matrix->rows;
    int cols = matrix->cols;
    double *val = matrix->val;
    int *row_ptr = matrix->row_ptr;
    int *col_idx = matrix->col_idx;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int found = 0;
            for (k = row_ptr[j]; k < row_ptr[j+1]; k++) {
                if (col_idx[k] == i) {
                    printf("%.1f\t", val[k]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("0.0\t");
            }
        }
        printf("\n");
    }
}

int main() {
    CSCMatrix C;
    C.rows = 5;
    C.cols = 5;
    C.nnz = 6;
    double val[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    int row_ptr[] = {0, 2, 4, 5, 6};
    int col_idx[] = {0, 1, 1, 2, 3, 4};
    C.val = val;
    C.row_ptr = row_ptr;
    C.col_idx = col_idx;

    print_matrix(&C);

    return 0;
}
