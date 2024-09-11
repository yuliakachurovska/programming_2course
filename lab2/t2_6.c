#include<stdio.h>
#include<math.h>

//завдання 2_6
double area(double a, double b, double c)
{
double p = (a+b+c)/2;
double S = sqrt((p * (p-a)*(p-b)*(p-c)));
return S;
}

double lenth(double x1, double x2, double y1, double y2) 
{
double l = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
return l;
}


int main() {
    double Ax, Ay, Bx, By, Cx, Cy;
    double AB, BC, CA;
    double S;

    printf("Enter A(x,y), B(x,y), C(x,y)\n");
    scanf("%lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
    printf("%lf %lf, %lf %lf, %lf %lf\n", Ax, Ay, Bx, By, Cx, Cy);
    
    AB = lenth(Ax, Bx, Ay, By);
    BC = lenth(Bx, Cx, By, Cy);
    CA = lenth(Cx, Ax, Cy, Ay);
    
    if ((AB < BC+CA) && (BC < AB+CA) && (CA < AB+BC))
    {
        S = area(AB, BC, CA);
        printf("AB = %.3lf, BC = %.3lf, CA = %.3lf\n", AB, BC, CA);
        printf("S = %.6lf", S);
    }
    else {
        printf("This triangle does not exist");
    }
}

/*Візьмемо координати прямокутого трикутника, для зручності 
обчислень
(0,0), (0,3), (4,0)
То відповідь виходить 6
*/