#include<stdio.h>
#include<math.h>
#include<stdint.h>

void task1() {
int a, b, c, sum, inv_numb;
unsigned number;
printf("n = ");
scanf("%u", &number);
if (number >= 100 && number <=999) {
    a = number % 10; //останнє число
    b = (number / 10) % 10; // Друге число
    c = number / 100; //Перше
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    sum = a + b + c;
    printf("Summa = %d\n", sum);
    inv_numb = 100*a + 10*b + c;
    printf("Inverse string = %d", inv_numb);
}
else {
    printf("Incorrect input! Try again.");
    }
}

void task2() {
int a, b, c;
int p1, p2, p3, p4, p5, p6;
unsigned number;
printf("\nn = ");
scanf("%u", &number);
if (number >= 100 && number <=999) {
    a = number % 10; //останнє число
    b = (number / 10) % 10; // Друге число
    c = number / 100; //Перше
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    p1 = c*100 + b*10 + a;
    p2 = c*100 + a*10 + c;
    p3 = b*100 + c*10 + a;
    p4 = b*100 + a*10 + c;
    p5 = a*100 + c*10 + b;
    p6 = a*100 + b*10 + c;
    printf("%d\n%d\n%d\n%d\n%d\n%d\n", p1, p2, p3, p4, p5, p6);
}
else {
    printf("Incorrect input! Try again.");
    }
}

//long long unsigned і вивід %xu
//%x - шістнадцятковий вивід
void task3a() {
    int a, b, c;
    long long multi;
    printf("Enter numbers a, b, c = ");
    scanf("%d, %d, %d", &a, &b, &c);
    if (fabs(a) < pow(2,10) && fabs(b) < pow(2,10) && fabs(c) < pow(2,10)) {
        multi = (long long) a * b * c;
        printf("a * b * c = %llx", multi);
    }
}

void task3b() {
    int a, b, c;
    long long multi;
    printf("Enter numbers a, b, c = ");
    scanf("%d, %d, %d", &a, &b, &c);
    if (fabs(a) < pow(2,21) && fabs(b) < pow(2,21) && fabs(c) < pow(2,21)) {
        multi = (long long) a * b * c;
        printf("a * b * c = %llx", multi);
    }
}

uint16_t mult(uint8_t x, uint8_t y) {
    uint16_t z = x * y; //(int)
    printf("%hu", z);
    return z;

}

void task4() {
    uint8_t x, y;
    uint16_t z;
    printf("x y: ");
    scanf("%hhu %hhu", &x, &y);
    printf("%hhu, %hhu\n", x, y);
    z = mult(x, y);
    printf("z = %hu", z);
}

void task5() {
    int x, y, Z, M;
    printf("Enter x, y:");
    scanf("%d %d", &x, &y);
    M = x>y ? x:y;
    printf("Max number = %d\n", M);
    Z = x<y ? x:y;
    printf("Min number = %d", Z);
}

void task6() {
    double x, y, z;
    double max_number, min_number;
    printf("Enter x, y, z = ");
    scanf("%lf %lf %lf", &x, &y, &z);
    max_number = x;
    if (fabs(y) > fabs(max_number)) {
        max_number = y;
    }
    if (fabs(z) > fabs(max_number)) {
        max_number = z;
    }
    printf("Max number = %.4lf\n", max_number);

    min_number = x;
    if (fabs(y) < fabs(min_number)) {
        min_number = y;
    }
    if (fabs(z) < fabs(min_number)) {
        min_number = z;
    }
    printf("Min number = %.4lf", min_number);

}

void task7_a() {
    double a, b, c;
    double x1, x2, D;
    printf("ax^2+bx+c. Enter value a, b, c = ");
    scanf("%lf %lf %lf", &a, &b, &c);
    D = (b*b) - (4*a*c);
    if (D < 0) {
        printf("There are no solutions!");
    }
    if (D == 0) {
        x1 = (-b) / (2*a);
        printf("x = %.4lf", x1);
    }
    if (D > 0) {
        x1 = (-b - sqrt(D)) / (2*a);
        x2 = (-b + sqrt(D)) / (2*a);
        printf("x1 = %.4lf, x2 = %.4lf", x1, x2);
    }
}

void task7_b() {
    double a, b, c;
    double x1, x2, D;
    double flag;
    printf("ax^4+bx^2+c. Enter value a, b, c = ");
    scanf("%lf %lf %lf", &a, &b, &c);
    D = (b*b) - (4*a*c);
    flag = 1;
    if (D < 0) {
        printf("There are no solutions!\n");
        flag = 0;
    }
    if (D == 0) {
        x1 = (-b) / (2*a);
        //printf("x = %.4lf\n", x1);
    }
    if (D > 0) {
        x1 = (-b - sqrt(D)) / (2*a);
        x2 = (-b + sqrt(D)) / (2*a);
       //printf("x1 = %.4lf, x2 = %.4lf\n", x1, x2);
    }
    if (flag == 1){
        if (x1 >= 0 && x2 >= 0) {
            printf("x1 = %lf, x2 = %lf, x3 = %lf, x4 = %lf", sqrt(x1), -(sqrt(x1)), sqrt(x2), -(sqrt(x2)));    
        }
        if (x1 < 0 && x2 < 0) {
            printf("There are no solutions!");
        }
        if (x1 < 0 && x2 > 0) {
            printf("x1 = %lf, x2 = %lf", sqrt(x2), -(sqrt(x2)));
        }
        if (x1 > 0 && x2 < 0) {
            printf("x1 = %lf, x2 = %lf", sqrt(x1), -(sqrt(x1)));
        }
    }
}

int main() {
    task1();
    task2();
    task3a();
    task3b();
    task4();
    task5();
    task6();
    task7_a();
    task7_b();
}