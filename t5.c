#include<stdio.h>

/*  5a
int main() {
    double x, x_4;
    printf("x = ");
    scanf("%lf", & x);
    x_4= x * x;
    x_4 *= x_4;
    printf("(%lf)^4 = %lf", x, x_4);
} 
*/
// 5b
int main() {
    double x, x_6;
    printf("x = ");
    scanf("%lf", & x);
    x_6 = x * x;
    x_6 *= x_6;
    x_6 *= x * x;
    printf("(%lf)^6 = %lf", x, x_6);
}