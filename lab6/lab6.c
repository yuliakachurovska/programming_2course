#include<stdio.h>
#include<math.h>
#include<stdint.h>
#include<float.h>
// молодший біт - той що з кінця перший

void task6_1(){
    unsigned char n; //8 бітове
    printf("n = ");
    scanf("%hhu", &n);
    unsigned long long m = 1<<n; //64 біт
    printf("%llu\n", m);
}

void task6_2(){
    int n;
    unsigned k;
    printf("n = ");
    scanf("%d",&n);
    printf("k = ");
    scanf("%u",&k);
    printf("%d", n | (1 << k));
}

void task6_3(){
    unsigned char n;
    scanf("%hhu",&n);
    unsigned long long m;
    scanf("%llu",&m);
    printf("%llu", m &~(1 << n));
}

void task6_4(){
    unsigned n, b1, b2, b3, b4, m;
    scanf("%u",&n);
    b1 = n & 0xFF; //або замість 0xFF можна записати 255
    b2 = n >> 8 & 0xFF;
    b3 = n >> 16 & 0xFF;
    b4 = n >> 24;
    m = (b1<<24) | (b3<<16) | (b2<<8) | b4;
    printf("%u, %x", m, m); 
}

void task6_5() {
    int n;
    unsigned count = 0;
    printf("n = ");
    scanf("%d",&n);
    unsigned max_count = 0;
    while (n & 1) {
        n>>=1;
        count++;
    }
    n>>=1;
    if(max_count < count) {
        max_count = count;
    }
    printf("Max count = %u", max_count);
}

int divisor(unsigned n) {
    int k = 1;
    while (n % k == 0 && k <= n) {
        k *= 2;
    }
    return k / 2;
}

void task6_6() {
    unsigned n;
    printf("n = ");
    scanf("%u", &n);

    if (divisor(n) != ((-n) & n)) {
        printf("%u uncorrect\n", n);
    } else {
        printf("%u correct\n", n);
    }
}

void task6_7() {
    uint16_t x = 0x0001;
    printf("%s-endian\n", *((uint8_t *) &x) ? "little" : "big");

}


int main() {
    task6_1();
    task6_2();
    task6_3();
    task6_4();
    task6_5();
    task6_6();
    task6_7();
}

