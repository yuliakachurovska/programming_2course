#include<stdio.h>
#include<math.h>

//f(x) = softPlus(x) = ln(1 + e^x);
double softPlus(double x) {
    double f_x = log(x);
    return f_x;
}

double softPlus_deritative(double x) {
    double f_dx = 1 / ((1/exp(x)) + 1);
    return f_dx;
}

int main() {
    double x;
    printf("x = ");
    scanf("%lf", &x);
    printf("ln(1 + e^%.4lf) = %.4lf", x, softPlus(x));
    printf("\nf`(x) = %.6lf", softPlus_deritative(x));
}

//прописати тести