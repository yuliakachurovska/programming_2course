#include<stdio.h>
#include<math.h>
#include<stdint.h>
#include<float.h>


void task4_1() {
    double x, y;
    int n;
    printf("Enter x, n = ");
    scanf("%lf %d", &x, &n);
    y = x;
    for(int i = 0; i < n; i++){
        y = sin(y);
    }
    printf("Result = %lf\n", y);
}

void task4_2a() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    printf("%u! = ", n);
    for(int i = 1; i < n; i++){
        printf("%u*", i);
    }
    printf("%u\n", n);
}

void task4_2b() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    printf("%u! = ", n);
    for(int i = n; i > 1; i--){
        printf("%u*", i);
    }
    printf("1\n");
}

void task4_3a() {
    int n, x, y, res;
    printf("n, x = ");
    scanf("%d %d", &n, &x);
    res = 0;
    y = 1;
    for(int i = 0; i <= n; i++){
        res += y;
        y *= x;
    }
    printf("%d\n", res);
}

void task4_4() {
    double x, y;
    unsigned int n, power=1;
    printf("x, n: ");
    scanf("%lf %d", &x, &n);
    y = 0;
    for (int i=1; i <= n; i++){
        power *= x;
        y += i * power;
    }
    printf("y = %lf\n", y);
}

void task4_5() {
    unsigned int n, m;
    printf("n = ");
    scanf("%u", &n);
    m = 1;
    for (int i = n; i > 0; i -= 2) {
        m *= i;
    }
    printf("res = %u", m);
}

void task4_6a() {
    unsigned int n;
    double res;
    printf("n = ");
    scanf("%u", &n);
    res = sqrt(2);
    for (int i = 0; i < n; i++) {
        res = sqrt(2 + res);
    }
    printf("Result = %lf\n", res);
}

void task4_6b() {
    unsigned int n;
    double res;
    printf("n = ");
    scanf("%u", &n);
    res = sqrt(3*n);
    for (int i = n-1; i > 0 ; i -= 1) {
        res = sqrt((3*i) + res);
    }
    printf("Result = %lf\n", res);
}

void task4_7() {
    double x, y, term = 1;
    unsigned n, i;
    printf("n, x = ");
    scanf("%u %lf", &n, &x);
    y = 1;
    for(i=1; i<=n; i++) {
        term *= (x/i);
        y += term;
    }
    printf("y = %lf\n", y);
}

void task4_8() {
    unsigned m, r, k, power;
    printf("m = ");
    scanf("%u", &m);
    power = 1;
    k = 0;
    while(power<=m)
    {power *=  4; k++;}
    printf("k = %u\n", k-1);
}

void task4_9() {
    unsigned m, r, k, power;
    printf("m = ");
    scanf("%u", &m);
    power = 1, 
    r = 0;
    do{power *= 2; r++;}
    while(power <= m);
    printf("r = %u\n", r);
}


void task4_10() {
    float eps = DBL_EPSILON;
    float a = 1.0f;
    do {
        a /= 2.0f;
    } while (1.0f + a != 1.0f);
    printf("Result: %.5e\n", 2 * a);
    printf("Epsilon for type float: %.5e \n", eps);
}

void task4_11() {
    int i = 0, count = 0;
    double x, sum = 0, mul=1;
    double eps = 2 * DBL_EPSILON;
    do {
        printf("a[%d] = ", i++);
        scanf("%lf", &x);
        if (x > eps) {
            sum += x;
            count += 1;
            mul *= x;
        }
    } while (fabs(x) > eps); 
    printf("Summa = %lf\n", sum);
    printf("Arithmetic average = %lf\n", sum/count);    
    printf("Geometry average = %lf\n", pow(mul, 1.0/count)); 
}

void task4_12() {
    unsigned int n;
    double subfact = 1;
    printf("n < 25 = ");
    scanf("%u", &n);
    for (int i=1; i <= n; i++){
        subfact = subfact * i + pow(-1, i);
    }
    printf("!%u = %.0f\n", n, subfact);

}

int main() {
    task4_1();
    task4_2a();
    task4_2b();
    task4_3a();
    task4_4();
    task4_5();
    task4_6a();
    task4_6b();
    task4_7();
    task4_8();
    task4_9();
    task4_10();
    task4_11();
    task4_12();
}