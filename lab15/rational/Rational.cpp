#include "Rational.h"
using namespace std;

void Rational::show(){
    cout<<nom<<"/"<<denom<<"\n";
}

int Rational::input(){
    cout<<"Input nom"<<"\n";
    cin>>nom;
    cout<<"Input denom"<<"\n";
    cin>>denom;
    reduce();
    return 0;
}

Rational::Rational() : nom(1), denom(1) {}

Rational Rational::add(const Rational &x){
    int t = (int)(this->nom * x.denom + denom * x.nom);
    unsigned y = x.denom + denom;
    return Rational(t, y);
}

unsigned Rational::gcd(unsigned x, unsigned y) {
    while (y != 0) {
        unsigned temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

Rational Rational::mult(const Rational &x){
    int t = (int)(this -> nom * x.nom);
    unsigned y = x.denom * denom;
    return Rational(t, y);
}

void Rational::reduce(){
    int nsd;
    if(nom>=0){
        nsd = (int)gcd(nom, denom);
    }
    else{
        nsd = (int)gcd(-nom, denom);
        nom /= nsd;
        denom /= nsd;
    }
}