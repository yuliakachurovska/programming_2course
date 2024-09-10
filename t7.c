#include<stdio.h>
#include<math.h>

int main() {
    int c, f, r;
    double x, z, d;
    printf("x = ");
    scanf("%lf", & x);
    c = ceil(x); //округлення зверху
    f = floor(x); //округлення знизу
    r =  round(x); //заокруглення
    z = (int)x; //ціла частина
    d = fabs(x-z); //дробова частина
    printf("c = %d, f = %d, r = %d, z = %lf, d = %lf", c, f, r, z, d);
}