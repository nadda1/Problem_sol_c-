//
// Created by Nada H on 4/2/2022.
//
#include <iostream>
using namespace std;

class Fraction {

protected:
    int numer, denom;
public:
    Fraction();

    Fraction(int x, int y);

    Fraction(const Fraction &obj);
    void simplification();
    bool operator<=(Fraction obj);

    bool operator>=(Fraction obj);

    bool operator==(Fraction obj);

    bool operator!=(Fraction obj);


    friend istream &operator>>(istream &input, Fraction &obj);

    friend ostream &operator<<(ostream &output,const  Fraction obj);

    Fraction sumTwoF(Fraction &obj);

    Fraction subtractTwoF (Fraction &obj);

    Fraction multiplyTwoF (Fraction &obj);

    Fraction DivideTwoF(Fraction &obj);




};


