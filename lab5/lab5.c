#include<stdio.h>
#include<math.h>
#include<stdint.h>
#include<float.h>

void task5_1a() {
    int i;
    double a, sum, eps, index;
    printf("a = ");
    scanf("%lf", &a);
    sum = 0;
    eps = 2*DBL_EPSILON;
    i = 1;
    index = 0;
    while(sum < a) {
        sum += 1.0/i;
        i++;
        index += 1;
    }
    printf("Summa = %lf, n = %.0lf\n", sum, index);
}

void task5_2a() {
    unsigned long long F0, F1, F;
    F0 = 0;
    F1 = 1;
    size_t i, n;
    printf("Index = ");
    scanf("%zu", &n);
    for(i = 2; i <= n; i++) {
        F = F0 + F1;
        F0 = F1;
        F1 = F;
    }
    printf("F = %zu\n", F1);
}

void task5_2b() {
    unsigned long long F0, F1, F;
    double a;
    int index=0;
    F0 = 0;
    F1 = 1;
    printf("a = ");
    scanf("%lf", &a);
    do{
        F = F0 + F1;
        F0 = F1;
        F1 = F;
        index += 1;
    } while(F1 < fabs(a));
    printf("Index F = %d\n", index);
}

void task5_3() {
    unsigned n, a0, ai, steps, max_steps, number_with_max_steps;
    printf("n = ");
    scanf("%d", &n);
    max_steps = 0;
    number_with_max_steps = 0;
    for (int i = 1; i < n; i++) {
        a0 = i;
        ai = a0;
        steps = 0;
        while(ai != 1){
            if(ai % 2 == 0){
                ai = ai / 2;
            } 
            else{
                ai = 3 * ai + 1;
            }
            steps++;
        }
        if (steps > max_steps) {
            max_steps = steps;
            number_with_max_steps = i;
        }
    }
    printf("Number with max steps: %d\n", number_with_max_steps);
    printf("Max steps: %d\n", max_steps);
}



void task5_4a() {
    unsigned int n;
    double p=1.0, f=1.0;
    printf("n = ");
    scanf("%u", &n);
    for (int i=1; i <= n; i++){
        f *= i;
        p *= (1 + 1.0 / f);
    }
    printf("P_n = %lf \n", p);
}

void task5_4b() {
    unsigned int n;
    double p=1.0;
    printf("n = ");
    scanf("%u", &n);
    for (int i=1; i <= n; i++){
        p *= (1 + (pow(-1, i+1) * i) / 2.0);
    }
    printf("P_n = %lf \n", p);
}

void task5_5() {
    int x_1=-99, x_2=-99, x_3=-99, x_n, n=0;
    while (1) {
        x_n = x_3 + x_1 + 100;
        x_1 = x_2;
        x_2 = x_3;
        x_3 = x_n;
        n++;
    if (x_n > 0) {
        break;
        }
    }
    printf("x_n = %d, n = %d\n", x_n, n);
}

void task5_6c(){
    double x_k = 0.5;
    int n;
    printf("n = ");
    scanf("%d", &n); 
    for (int k = n; k > 0; k--) {
        if (k % 2 == 0) {
            x_k = 1.0 /(2 + x_k);
        } else {
            x_k = 1.0 /(1 + x_k);
        }
    }
    printf("result = %lf\n", x_k+1.0);
}

void task5_7() {
    double n, k, i, a1, a2, b1, b2, ak, bk, s = 6.0;
    scanf("%lf", &n);
    a1 = b2 = 0;
    a2 = b1 = 1;
    if (n == 1) {
        printf("2\n");
    } else if (n == 2) {
        printf("6\n");
    }
    else {
        for(int i = 3; i <= n; i++) {
            bk = b2 + a2;
            ak = (a2 / i) + (a1 * bk);
            a1 = a2;
            a2 = ak;
            b1 = b2;
            b2 = bk;
            s += (pow(2, i) / (ak + bk));
        }
        printf("%lf\n", s);
    }
}

void task5_8a(){
    double x, eps, y, t;
    int i ;
    printf("x = ");
    scanf("%lf",&x);
    do{
        printf("eps = ");
        scanf("%lf",&eps);

    }while(eps <= 0);
    t = 1;
    y = t;
    i = 1;
    while(t > eps){
        t *= (x / i);
        y += t;
        i++;
    }
    printf("y = %lf, math e^x = %lf, eps = %lf\n", y, exp(x), eps);
}

void task5_8b(){
    double x, eps, y, t, k;
    int i ;
    printf("x = ");
    scanf("%lf",&x);
    do{
        printf("eps = ");
        scanf("%lf",&eps);

    }while(eps <= 0);
    t = x;
    y = t;
    i = 1;
    while(fabs(t) > eps){
        t *= (pow(-x, 2)) / (i * (2 * i + 1));
        y += t;
        i++;
    }
    printf("y = %lf\n",y);
}

int main() {
    task5_1a();
    task5_2a();
    task5_2b();
    task5_3();
    task5_4a();
    task5_4b();
    task5_5();
    task5_6a();
    task5_7();
    task5_8a();
    task5_8b();

}