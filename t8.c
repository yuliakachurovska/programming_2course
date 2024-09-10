#include<stdio.h>

int main() {
    double a, b;
    double subtraction, multiplication;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    subtraction = a - b;
    multiplication = a * b;
    printf("%.2lf - %.2lf = %.2lf\n", a, b, subtraction);
    printf("%.2lf * %.2lf = %.2lf", a, b, multiplication);

}