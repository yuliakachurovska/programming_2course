#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double sum_sqrt(const double* arr, int n) {
    double sum = 0;
    const double* beg = arr;
    const double* end = arr + n;
    for(; beg < end; beg++) {
        double n_arr = *beg;
        sum += pow(n_arr, 2);
    }
    return sum;
}

void task1() {
    unsigned n;
    printf("Enter n: ");
    scanf("%u", &n);

    double *arr = malloc(n * sizeof(*arr));
    if(arr){
        for (int i = 0; i < n; i++) {
        printf("Enter element [%d] = ", i + 1);
        scanf("%lf", &arr[i]);
        }
        double result = sum_sqrt(arr, n);
        printf("Sum of squares: %lf\n", result);
        free(arr);
    }
    else{
        printf("Memory allocation failed.\n");
    }
}

typedef struct Stack {
    int data;
    struct Stack* addr;
} Stack;


void task2() {
    Stack* s = NULL;
    int x;

    do {
        printf("Enter a number (0 to stop): ");
        scanf("%d", &x);

        if (x != 0) {
            Stack* t = (Stack*)malloc(sizeof(Stack));
            if (t == NULL) {
                printf("Memory allocation failed.\n");
                return;
            }
            t->data = x;
            t->addr = s;
            s = t;
        }
    }while (x != 0);

    printf("Stack:\n");
    while (s != NULL) {
        printf("%d\t", s->data);
        Stack* temp = s;
        s = s->addr;
        free(temp);
    }
}

int input_vect(double** arr, size_t n){
    *arr = malloc(n * sizeof(**arr));
    if(*arr == NULL){
        return 1;
    }
    for(size_t i = 0; i < n; i++){
        printf("Enter element [%zu]: ", i + 1);
        scanf("%lf", &(*arr)[i]);
    }
    return 0;
}

void delete_vect(double* arr){
    if(arr){
        free(arr);
    }
}

void output_vect(const double* arr, size_t n){
    for(size_t i = 0; i < n; i++){
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

int subt_vec(const double* arr1, const double* arr2, double** arr3, size_t n){
    if(arr1 == NULL || arr2 == NULL){
        return 1;
    }
    *arr3 = (double*)malloc(n * sizeof(**arr3));
    if(*arr3 == NULL){
        return 1;
    }
    for(size_t i = 0; i < n; i++){
        (*arr3)[i] = arr1[i] - arr2[i];
    }
    return 0;
}

void task3(){
    size_t n;
    double *vect1 = NULL, *vect2 = NULL, *vect3 = NULL;
    printf("Enter the number of elements: ");
    scanf("%zu", &n);
    if(input_vect(&vect1, n) || input_vect(&vect2, n)){
        printf("Failed to allocate memory or read input.\n");
        delete_vect(vect1);
        delete_vect(vect2);
        return;
    }
    if(subt_vec(vect1, vect2, &vect3, n)){
        printf("Failed to allocate memory for the result vector.\n");
        delete_vect(vect1);
        delete_vect(vect2);
        return;
    }
    printf("Result of subtraction:\n");
    output_vect(vect3, n);
    delete_vect(vect1);
    delete_vect(vect2);
    delete_vect(vect3);
}

//task4
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

void delete_matr(double **matr, size_t n){
    if(!matr) return;
    for(size_t i = 0; i < n; i++){
        free(matr[i]);
    }
    free(matr);
}

void input_matr(double **matr, size_t n){
    printf("Enter the elements of a %zu x %zu matrix:\n", n, n);
    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < n; j++){
            scanf("%lf", &matr[i][j]);
        }
    }
}

void output_matr(double **matr, size_t n){
    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < n; j++){
            printf("%.3lf\t", matr[i][j]);
        }
        printf("\n");
    }
}

double** mult_matr(double **matr1, double **matr2, size_t n){
    double **result = create_matr(n);
    if(!result) return NULL;

    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < n; j++){
            result[i][j] = 0;
            for(size_t k = 0; k < n; k++){
                result[i][j] += matr1[i][k] * matr2[k][j];
            }
        }
    }
    return result;
}

void task4(){
    size_t n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%zu", &n);

    double **matr1 = create_matr(n);
    double **matr2 = create_matr(n);

    if(!matr1 || !matr2){
        printf("Memory allocation error.\n");
        delete_matr(matr1, n);
        delete_matr(matr2, n);
        return;
    }

    input_matr(matr1, n);
    input_matr(matr2, n);

    printf("Matrix 1:\n");
    output_matr(matr1, n);

    printf("Matrix 2:\n");
    output_matr(matr2, n);

    double **matr3 = mult_matr(matr1, matr2, n);
    if(!matr3){
        printf("Memory allocation error during matrix multiplication.\n");
        delete_matr(matr1, n);
        delete_matr(matr2, n);
        return;
    }

    printf("The result of matrix multiplication:\n");
    output_matr(matr3, n);

    delete_matr(matr1, n);
    delete_matr(matr2, n);
    delete_matr(matr3, n);
}

int main() {
    task1();
    task2();
    task3();
    task4();
}
