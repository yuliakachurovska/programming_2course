#include<stdio.h>
#include<math.h>

double volume_of_cone(double r, double h) {
    double S_baze = M_PI * r * r;
    double V = (S_baze * h)/3;
    return V;
}

int main() {
    double r, h;
    printf("Enter the values of r and h  = ");
    scanf("%lf %lf", &r, &h);
    printf("r = %lf, h = %lf", r, h);
    printf("\nV = %.4lf", volume_of_cone(r, h));
}