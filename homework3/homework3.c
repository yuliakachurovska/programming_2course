#include<stdio.h>
#include<math.h>
#include<stdint.h>

void task3_16() {
    double x1, y1, x2, y2;
    double r1, r2, O1O2;
    printf("Enter the coordinates of the first circle (x1, y1) = ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the coordinates of the second circle (x2, y2) = ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter the radius of the circles r1, r2: ");
    scanf("%lf %lf", &r1, &r2);
    O1O2 = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
    if ((r1 + r2) > O1O2) {
        printf("These circles intersect.");
    }
    else {
        printf("These circles do not intersect.");
    }
}


double eReLu_deritative(double a, double x) {
    if (x < 0) {
        return a*exp(x);
    }
    else {
        return 0;
    }
}
void eReLu() {
    double a, x;
    printf("Enter value a, x = ");
    scanf("%lf %lf", &a, &x);
    if (x >= 0) {
        printf("eReLu(a, x) = 0\n");
    }
    else {
        printf("eReLu(a, x) = %lf\n", (a*(exp(x) - 1)));
    }
    printf("eReLu deritative = %lf", eReLu_deritative(a, x));
}

int main() {
    task3_16();
    eReLu();
}