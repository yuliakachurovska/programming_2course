#include<stdio.h>
#include<math.h>

//завдання 2_1
int main() {
    double x, res;
    printf("x = ");
    scanf("%lf", &x);
    res = cos(x);
    printf("cos(%.3lf) = %.6lf", x, res);
}