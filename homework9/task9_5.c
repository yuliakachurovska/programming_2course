#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** create_matr(size_t n) {
    double **matr = (double**) calloc(n, sizeof(double*));
    if (!matr) return NULL;

    for (size_t i = 0; i < n; i++) {
        matr[i] = (double*) calloc(n, sizeof(double));
        if (!matr[i]) {
            for (size_t j = 0; j < i; j++) {
                free(matr[j]);
            }
            free(matr);
            return NULL;
        }
    }
    return matr;
}

void delete_matr(double **matr, size_t n) {
    if (!matr) return;
    for (size_t i = 0; i < n; i++) {
        free(matr[i]);
    }
    free(matr);
}

void input_matr(double **matr, size_t n) {
    printf("Enter the elements of a %zu x %zu matrix:\n", n, n);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            scanf("%lf", &matr[i][j]);
        }
    }
}

double determinant(double **matrix, int n) {
    double det = 1;
    for (int i = 0; i < n; i++) {
        double maxEl = fabs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(matrix[k][i]) > maxEl) {
                maxEl = fabs(matrix[k][i]);
                maxRow = k;
            }
        }

        if (maxRow != i) {
            det = -det;
            for (int k = 0; k < n; k++) {
                double temp = matrix[maxRow][k];
                matrix[maxRow][k] = matrix[i][k];
                matrix[i][k] = temp;
            }
        }

        det *= matrix[i][i];

        for (int k = i + 1; k < n; k++) {
            double coeff = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < n; j++) {
                if (i == j) {
                    matrix[k][j] = 0;
                } else {
                    matrix[k][j] += coeff * matrix[i][j];
                }
            }
        }
    }
    return det;
}

int rank_of_matrix(double **matrix, int n) {
    int rank = 0;
    
    for (int size = 1; size <= n; size++) {
        for (int i = 0; i <= n - size; i++) {
            for (int j = 0; j <= n - size; j++) {

                double **submatrix = create_matr(size);
                for (int sub_i = 0; sub_i < size; sub_i++) {
                    for (int sub_j = 0; sub_j < size; sub_j++) {
                        submatrix[sub_i][sub_j] = matrix[i + sub_i][j + sub_j];
                    }
                }

                if (determinant(submatrix, size) != 0) {
                    rank = size;
                }
                delete_matr(submatrix, size);
            }
        }
    }
    return rank;
}

void task9_5() {
    size_t n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%zu", &n);
    double **matrix = create_matr(n);
    if (!matrix) {
        printf("Memory allocation failed\n");
        return;
    }
    input_matr(matrix, n);
    double det = determinant(matrix, n);
    printf("The determinant of the matrix is: %.2f\n", det);
    int rank = rank_of_matrix(matrix, n);
    printf("The rank of the matrix is: %d\n", rank);
    delete_matr(matrix, n);
}

int main() {
    task9_5();
}
