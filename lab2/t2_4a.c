#include<stdio.h>
#include<math.h>

//завдання 2_4 пункт а
double task4_a(double x)
{
double y = x + x + 1;
return y * y;
}
int main() {
    double x, y;
    printf("x = ");
    scanf("%lf", &x);
    printf("y = %.3lf", task4_a(x));

}