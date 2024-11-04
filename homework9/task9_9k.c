#include <stdio.h>
#include <stdlib.h>

double** create_matr(size_t n, size_t m) {
    double **matr = (double**) calloc(n, sizeof(double*));
    if (!matr) return NULL;

    for (size_t i = 0; i < n; i++) {
        matr[i] = (double*) calloc(m, sizeof(double));
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

void input_matr(double **matr, size_t n, size_t m) {
    printf("Enter the elements of a %zu x %zu matrix:\n", n, m);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            scanf("%lf", &matr[i][j]);
        }
    }
}

void output_matr(double **matr, size_t n, size_t m) {
    printf("Matrix:\n");
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            printf("%lf ", matr[i][j]);
        }
        printf("\n");
    }
}

double** delete_column(double **matr, size_t n, size_t m, size_t k) {
    if (k >= m) return matr;

    double **new_matr = create_matr(n, m - 1);
    if (!new_matr) return NULL;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (j < k) {
                new_matr[i][j] = matr[i][j];
            } else if (j > k) {
                new_matr[i][j - 1] = matr[i][j];
            }
        }
    }

    delete_matr(matr, n);
    return new_matr;
}

int main() {
    size_t n, m, k;
    printf("Enter the dimensions of the matrix (n x m): ");
    scanf("%zu %zu", &n, &m);

    double **matr = create_matr(n, m);
    if (!matr) {
        printf("Memory allocation error!\n");
        return 1;
    }

    input_matr(matr, n, m);
    output_matr(matr, n, m);
    printf("Enter the column number to delete (0-%zu): ", m - 1);
    scanf("%zu", &k);

    double **new_matr = delete_column(matr, n, m, k);
    if (!new_matr) {
        printf("Memory allocation error while deleting column!\n");
        delete_matr(matr, n);
        return 1;
    }

    printf("Matrix after deleting column %zu:\n", k);
    output_matr(new_matr, n, m - 1);
    delete_matr(new_matr, n);
}
