#include<stdio.h>
#include<math.h>

int main() {
    double x;
    double res;
    printf("x = ");
    scanf("%lf", &x);
    res = log10(x);
    printf("log10(%.3lf) = %.3lf", x, res);
}