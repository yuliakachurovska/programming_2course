#include<stdio.h>

int main() {
    double A, B, C;
    double avarage_arithmetic, avarage_harmonic; 

    printf("Enter a string in the format \nA=xx.xxx, B=xxExx, C=xxx.xxxx:\n");
    scanf("A=%lf, B=%lf, C=%lf", &A, &B, &C);
    printf("A = %lf, B = %.4e, C = %lf\n", A, B, C);
    //f-десятковий з фіксованою крапкою, e-науковий
    
    avarage_arithmetic = (A + B + C) / 3;
    avarage_harmonic = 3 / ((1/A) + (1/B) + (1/C));
    printf("Average arithmetic = %.4f\nAverage harmonic = %.4f\n", avarage_arithmetic, avarage_harmonic);
}