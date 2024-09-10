#include<stdio.h>
#include<math.h>

//задача з пари з годинником

int main() {
    double hours, minute, second;
    double angle;

    printf("Angle = ");
    scanf("%lf", &angle);
    
    hours = (int)angle;
    hours /= 30;
    hours = (int)hours;
    minute = fmod(angle, 30);
    minute = (minute / 30) * 60;
    second = (minute - (int)minute) * 60;

    printf("hours = %.0lf, minute = %.0lf, second = %.1lf", hours, minute, second);

}