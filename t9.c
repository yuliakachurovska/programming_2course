#include<stdio.h>

int main() {
    double avarage_arithmetic, avarage_harmonic; 
    double a, b;
    printf("a, b = ");
    scanf_s("%lf %lf", &a, &b);
    printf("a = %lf, b = %lf\n", a, b);
    avarage_arithmetic = (a + b) / 2;
    avarage_harmonic = 2 / ((1/a) + (1/b));
    printf("Avarage arithmetic = %lf\nAvarage harmonic = %lf", avarage_arithmetic, avarage_harmonic);
}