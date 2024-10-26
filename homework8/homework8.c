#include <stdio.h>
#define MAX_SIZE 100

void Spiral(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int value = 1;
    int row = n / 2;
    int col = n / 2;

    matrix[row][col] = value++;
    int step = 1;
    while (value <= n * n) {
        for (int i = 0; i < step && value <= n * n; i++) {
            col++;
            matrix[row][col] = value++;
        }
        // Рух вгору
        for (int i = 0; i < step && value <= n * n; i++) {
            row--;
            matrix[row][col] = value++;
        }
        step++; // Збільшуємо крок для наступних лівого та нижнього рухів

        // Рух вліво
        for (int i = 0; i < step && value <= n * n; i++) {
            col--;
            matrix[row][col] = value++;
        }
        // Рух вниз
        for (int i = 0; i < step && value <= n * n; i++) {
            row++;
            matrix[row][col] = value++;
        }
        step++; // Збільшуємо крок для наступних правого та верхнього рухів
    }
}

void output_Matrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE] = {0};
    int n;

    printf("Enter the size of the square matrix n: ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n % 2 == 0) {
        printf("Please enter an odd size within the allowed limit (%d).\n", MAX_SIZE);
        return 1;
    }

    Spiral(matrix, n);
    output_Matrix(matrix, n);
}
