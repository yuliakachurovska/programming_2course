#include<stdio.h>
#include<math.h>

//приклад пропису функції

double area(double a, double b, double c)
{double p = (a + b + c) / 2;
return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main() {
    double a, b, c;
    double p, S;
    printf("Enter value a, b, c = ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if ((a < b+c) && (b < a+c) && (c < a+b))
    {
        S = area(a, b, c);
        printf("S = %.3lf", S);
    }
    else {
        printf("This triangle does not exist");
    }
}
