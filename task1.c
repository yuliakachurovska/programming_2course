#include<stdio.h>

int main() {
    float x;
    x = 23 + 1;
    printf("23 + 1 = %.2f\n", x);

    x = 0;
    x = 45 * 54 - 11;
    printf("45 * 54 - 11 = %.2f\n", x);

    x = 0;
    x = 15 / 4;  
    printf("15 / 4 = %.2f\n", x);

    x = 0;
    x = 15.0 / 4;
    printf("15.0 / 4 = %.2f\n", x);

    x = 0;
    x = 67 % 5;
    printf("67 %% 5 = %.2f\n", x);

    x = 0;
    x = (2 * 45.1 + 3.2) / 2;
    printf("(2 * 45.1 + 3.2) / 2 = %.2f\n", x);

    return 0;
}