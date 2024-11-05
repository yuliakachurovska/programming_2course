#ifndef RATIO_H
#define RATIO_H
#include <stdbool.h>

typedef struct {
    int num;
    unsigned dem;
} Ratio;

Ratio add(Ratio x, Ratio y); 
Ratio mult(Ratio x, Ratio y);
bool bool_greater(Ratio x, Ratio y);
void reduce(Ratio* x);
void output(Ratio x);
int input(Ratio* x);

#endif
