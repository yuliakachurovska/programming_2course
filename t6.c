#include<stdio.h>

int main() {
    double C;
    double F;
    printf("C(Enter degrees Celsius(C)) = ");
    scanf("%lf", & C);
    F = ((9*C)/5) + 32;
    printf("F = %g", F);
}