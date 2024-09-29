#include<stdio.h>
#include<math.h>
#include<stdint.h>
#include<float.h>

void task13_b(){
    double a1=1, b1=1, ak, bk, p_n = 1.0;
    int n;

    printf("n = ");
    scanf("%d", &n);
    if(n == 1){
        printf("1\n");
    }
    else{
        for(int k=2; k<=n; k++){
            ak = (sqrt(b1) + a1) / 5.0;
            bk = (2*b1) + (5*a1*a1);
            p_n *= ak * bk;
            a1 = ak;
            b1 = bk;
        }
    }
    printf("Product(%d) = %lf", n, p_n);
}

void task5_16h(){
    double x, eps, y = 0.0, ak;
    int k = 1;

    do {
        printf("x (|x| < 1) = ");
        scanf("%lf", &x);
    } while (fabs(x) >= 1);

    do {
        printf("eps = ");
        scanf("%lf", &eps);
    } while (eps <= 0);

    ak = 2 * x; 
    y = ak;
    while (fabs(ak) >= eps) {
        k++;
        ak *= (x * x * (2 * k - 3)) / (2 * k - 1);
        y += ak;
    }
    printf("y(%.3lf) = %lf\n",x ,y);
}

int main(){
    task13_b();
    task5_16h();
}