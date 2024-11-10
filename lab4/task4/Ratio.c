#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Ratio.h"

void output(Ratio x) {
    printf("%d / %u", x.num, x.dem);
}

int input(Ratio* x) {
    printf("x / y\n");
    printf("Enter numerator: \n");
    scanf("%d", &x->num);
    printf("Enter denominator: \n");
    scanf("%u", &x->dem);
    return x->dem != 0;
}

Ratio add(Ratio x, Ratio y) {
    Ratio z;
    z.num = x.num * y.dem + y.num * x.dem;
    z.dem = x.dem * y.dem;
    return z;
}

Ratio mult(Ratio x, Ratio y) {
    Ratio z;
    z.num = x.num * y.num;
    z.dem = x.dem * y.dem;
    return z;
}

unsigned gcd(unsigned n, unsigned m) {
    if (m == 0) {
        return n;
    }
    return gcd(m, n % m);
}

bool bool_greater(Ratio x, Ratio y) {
    return (x.num * y.dem > y.num * x.dem);
}

void reduce(Ratio *x) {
    unsigned g = gcd((unsigned) abs(x->num), x->dem); 
    x->num /= (int) g;
    x->dem /= g;
    if (x->dem < 0) {
        x->num = -x->num;
        x->dem = -x->dem;
    }
}
