#include <stdio.h>
#include <math.h>

int main() {
    float x1 = 10e-4f;
    double y1 = 10e-4;
    long double z1 = 10e-4L;
    printf("float: %.2f, double: %.2f, long double: %.2Lf\n", x1, y1, z1);

    float x2 = 24.33E5f;
    double y2 = 24.33E5;
    long double z2 = 24.33E5L;
    printf("float: %.2f, double: %.2f, long double: %.2Lf\n", x2, y2, z2);

    float x3 = (float)M_PI;
    double y3 = M_PI;
    long double z3 = (long double)M_PI;
    printf("float: %.2f, double: %.2f, long double: %.2Lf\n", x3, y3, z3);

    float x4 = (float)exp(1.0);
    double y4 = exp(1.0);
    long double z4 = (long double)exp(1.0);
    printf("float: %.2f, double: %.2f, long double: %.2Lf\n", x4, y4, z4);

    float x5 = (float)sqrt(5);
    double y5 = sqrt(5);
    long double z5 = (long double)sqrt(5);
    printf("float: %.2f, double: %.2f, long double: %.2Lf\n", x5, y5, z5);

    float x6 = (float)log(10);
    double y6 = log(10);
    long double z6 = (long double)log(10);
    printf("float: %.2f, double: %.2f, long double: %.2Lf\n", x6, y6, z6);
    
    return 0;
}