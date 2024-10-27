#include<stdio.h>
#include<math.h>
#include<stdint.h>
#include<float.h>
#define SIZE_7 10

//task1
void output_matrix(int A[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    } 
}

void task1(){
    int k=3;
    int A[3][3] = {{1,2,3,}, {4,5,6}, {7,8,9}};
    unsigned N, M;
    printf("Enter N, M: ");
    scanf("%u %u", &N, &M);
    int f=0;
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            if(A[i][j] == M){
                A[i][j] = N;
                f = 1;
                break;
            }
        }
    }
    if(!f){
            printf("The number M is not in the matrix.\n");
        }
    output_matrix(A);   
}

//task2
void output_matrix2(double A[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%.3lf\t", A[i][j]);
        }
        printf("\n");
    } 
}

void task2(){
    int k=3;
    double A[3][3] = {{1.0, 2,3}, {4,5,6}, {7,8,9}};
    unsigned i, j;
    double a;
    printf("Enter i, j: ");
    scanf("%u %u", &i, &j);
    printf("Enter a: ");
    scanf("%lf", &a);
    if(i<3 && j<3){
        A[i][j] = a;
        output_matrix2(A);
    }
    else{
        printf("Index i and j are incorrect!");
    }
}

//task3
void input_matrix3(double A[20][20], int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%lf", &A[i][j]);
        }
    }
}

void output_matrix3(double A[20][20], int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%.3lf\t", A[i][j]);
        }
        printf("\n");
    } 
}

void task3(){
    double A[20][20];
    int m, n;
    printf("Enter m, n: ");
    scanf("%d %d", &m, &n);
    input_matrix3(A, m, n);
    output_matrix3(A, m, n);
}

//task4
void input_matrix4(double A[25][25], int m, int n) {
    for(int i = 0; i < m; i++) {
        printf("Enter row %d: ", i + 1);
        for(int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
}

void output_matrix4(double A[25][25], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%6.2lf ", A[i][j]);
        }
        printf("\n");
    }
}

void task4(){
    double A[25][25];
    int m, n;
    printf("Enter m, n: ");
    scanf("%d %d", &m, &n);
    input_matrix4(A, m, n);
    output_matrix4(A, m, n);
}

//task5
void transposicion(double A[20][20], int m, int n){ //для зручності ставлю обмеження в 20 для матриці
    if(n == m){
        for(int i = 0; i < m; i++){
            for(int j = i + 1; j < n; j++){
                double temp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = temp;
            }
        }
    }
}

void output_matrix5(double A[20][20], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%6.2lf ", A[i][j]);
        }
        printf("\n");
    }
}

void task5(){
    double A[20][20];
    int m, n;
    printf("Enter m, n: ");
    scanf("%d %d", &m, &n);
    if(m==n){
        input_matrix3(A, m, n);  //використовую ввід з завдання 3
        printf("Your matrix:\n");
        output_matrix5(A, m, n); //не транспонована матриці
        transposicion(A, m, n);
        printf("Transposicion:\n");
        output_matrix5(A, m, n);
    }
    else{
        printf("Matrix must be square to transpose.\n");
    }
}

//task6
void input_matrix6(double A[100][100], int m, int n) {
    for(int i = 0; i < m; i++) {
        printf("Enter row %d: ", i + 1);
        for(int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
}

void output_matrix6(double A[100][100], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%6.2lf ", A[i][j]);
        }
        printf("\n");
    }
}

void task6(){
    int k, flag=0;
    double A[100][100];
    double res=0;
    int M, N;
    printf("Enter k: ");
    scanf("%d", &k);
    printf("Enter M, N: ");
    scanf("%d %d", &M, &N);
    input_matrix6(A, M, N);
    output_matrix6(A, M, N);
    if(M<100 && N<100){
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(i-j == k){
                    res += A[i][j];
                    flag += 1;
                }
            }
        }
        if(flag == 0){
            printf("res = 0");
        }
        else{
            printf("res = %lf", res);
        }
    }
    else{
        printf("The entered values ​​of N or M are incorrect. They should be less than 100!");
    }
}

//task7
double determinant(double matrix[SIZE_7][SIZE_7], int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        double det = 0;
        double submatrix[SIZE_7][SIZE_7];
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x) continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix, n - 1);
        }
        return det;
    }
}

void input_matrix7(double A[SIZE_7][SIZE_7], int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter row %d: ", i + 1);
        for(int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
}

void task7() {
    double matrix[SIZE_7][SIZE_7];
    int n;
    printf("Enter the size of the square matrix n: ");
    scanf("%d", &n);
    if (n > SIZE_7) {
        printf("Matrix size exceeds the allowed limit of %d.\n", SIZE_7);
        return;
    }
    input_matrix7(matrix, n);
    double det = determinant(matrix, n);
    printf("d(A) = %.2lf\n", det);
}

int main(){
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
}