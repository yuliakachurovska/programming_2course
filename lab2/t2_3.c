#include<stdio.h>
#include<math.h>

//завдання 2_3
int main() {
    double a, b, c;
    double p, S;
    printf("Enter value a, b, c = ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if ((a < b+c) && (b < a+c) && (c < a+b))
    {
        p = (a + b + c) / 2;
        S = sqrt(p * (p-a)*(p-b)*(p-b));
        printf("S = %.3lf", S);
    }
    else {
        printf("This triangle does not exist");
    }
}