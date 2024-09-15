#include<stdio.h>
#include<math.h>

//завдання 2_4 пункт д
double task4_a(double x)
{
double y = (((16 * x+8) * x+4) * x+2) * x+1;
return y;
}
int main() {
    double x, y;
    printf("x = ");
    scanf("%lf", &x);
    printf("y = %.3lf", task4_a(x));

}