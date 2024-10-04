#include<stdio.h>
#include<math.h>
#include<stdint.h>
#include<float.h>

void task6_12(){
    unsigned m;
    int i, j;
    printf("m = ");
    scanf("%u", &m);
    printf("i, j = ");
    scanf("%d %d", &i, &j);
    int bit_i = (m >> i) & 1;
    int bit_j = (m >> j) & 1;

    if (bit_i != bit_j) { //Перевіримо чи i та j не однакові для коректності дій
        m ^= (1 << i);
        m ^= (1 << j);
    }
    printf("Decimal: %u\n", m);
    printf("Hexadecimal: %X\n", m);
}

void task6_27(){
    unsigned long long n, k;
    printf("n = ");
    scanf("%llu", &n);
    printf("k = ");
    scanf("%llu", &k);
    unsigned long long p = n ^ k;
    int i = 0;
    printf("Different bits in positions: ");
    while (p){
        if (p & 1) {
            printf("%d ", i);
        }
        p >>= 1;
        i++;
    }
}

int main(){
    task6_12();
    task6_27();
}