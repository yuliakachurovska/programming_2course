#include<stdio.h>
#include<math.h>
#include<stdint.h>
#include<float.h>

void task4_12b() {
    int n, x;
    long long res = 0;
    printf("n, x = ");
    scanf("%d %d", &n, &x);

    for(int i = 0; i <= n; i++) {
        res += pow(x, 3*(n - i));
    }

    printf("Result: %lld\n", res);
}

double z_i(double y) {
    if (y >= 1) {
        return y;
    } else {
        return 2;
    }
}

void task4_23() {
    int i;
    unsigned n;
    double z, y, min;
    printf("n = ");
    scanf("%u", &n);
    printf("y[1] = ");
    scanf("%lf", &y);

    z = z_i(y);
    min = fabs(z);

    for (i = 2; i <= n; i++) {
        printf("y[%d] = ", i);
        scanf("%lf", &y);

        z = z_i(y);
        if (fabs(z) < min) {
            min = fabs(z);
        }
    }
    printf("min = %lf\n", min);
}

int main() {
    task4_12b();
    task4_23();
}