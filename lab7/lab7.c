#include<stdio.h>
#include<math.h>
#include<stdint.h>
#include<float.h>
#define N 5
#define SIZE 10
#define SIZE_3 5
#define SIZE5 50
#define SIZE6 20

void task1(){
    int mas[N] = {1,2,3,4,5};
    double a;
    scanf("%lf", &a);
    int count = 0;
    for(int i=0; i<N; i++){
        if(mas[i]<a){
            count++;
        }
    }
    printf("K = %d", count);
}

void task2(){
    int mas[] = {5, 112, 4, 3};
    int n = sizeof(mas)/sizeof(mas[0]);
    for(int i=n-1; i>=0; i--){
        printf("%d\t", mas[i]);
    }

}

double sum(double arr[SIZE]){
    double res = 0;
    for(int i=0; i<SIZE; i++){
        if(arr[i]>M_E){
            res += arr[i];
        }
    }
    return res;
}

void task3(){
    double a[SIZE];
    for(int i=0; i<SIZE; i++){
        printf("a[%d] = ", i+1);
        scanf("%lf", &a[i]);
    }
    printf("Summa = %lf", sum(a));
}

int input_arr(int a[SIZE_3]){
    for(int i=0; i<SIZE_3; i++){
        printf("a[%d] = ", i);
        int r = scanf("%d", &a[i]);
        if(r!=1) return i;
    }
    return SIZE_3;
}

int maximum(int a[SIZE_3]){
    int max = a[0];
    for(int i=1; i<SIZE_3; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

void task4(){
    int arr[SIZE_3];
    int m = input_arr(arr);
    if(m!=SIZE_3){
        printf("Error!");
        return;
    }
    printf("%d", maximum(arr));
}

int input_arr1(int a[SIZE5]){
    for(int i=0; i<SIZE5; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
        if(a[i]==0) return i-1;
    }
    return SIZE5;
}

void odd_even(int a[], int n){
    int odd=0, even=0;
    for(int i=0; i<n; i++){
        if(a[i]%2){
            odd += 1;
        }
        else{
            even++;
        }
    }
    printf("%d %d", odd, even);
}

void task5(){
    int arr[SIZE5];
    int m = input_arr1(arr);
    odd_even(arr, m);
}

void input_vect(double v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        scanf("%lf", &v[i]);
    }
}

void output_vect(const double v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", v[i]); 
    }
    printf("\n");
}

void add_vect(const double v1[], const double v2[], double v3[], int n) {
    for (int i = 0; i < n; i++) {
        v3[i] = v1[i] + v2[i];
    }
}

double mult_vect(const double v1[], const double v2[], int n) {
    double product = 0.0;
    for (int i = 0; i < n; i++) {
        product += v1[i] * v2[i];
    }
    return product;
}

void task6() {
    double v1[SIZE6];
    double v2[SIZE6];
    double v3[SIZE6];
    int n;
    printf("n = ");
    scanf("%d", &n);

    if (n > SIZE6) {
        printf("Error: n > 20");
        return;
    }

    printf("Enter first vector:\n");
    input_vect(v1, n);
    printf("Enter second vector:\n");
    input_vect(v2, n);
    printf("Scalar product: %.2lf\n", mult_vect(v1, v2, n));
    add_vect(v1, v2, v3, n);
    printf("Summa: ");
    output_vect(v3, n);
}

int main(){
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
}

