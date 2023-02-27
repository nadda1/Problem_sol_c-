//
// Created by Nada H on 4/2/2022.
//

#include "Fraction.h"
#include <iostream>
using namespace std;
Fraction::Fraction()
{

}
Fraction :: Fraction(int x,int y)
{
    numer=x;
    denom=y;

}
Fraction ::Fraction(const Fraction &obj)
{

    numer = obj.numer;
    denom=obj.denom;

}


bool Fraction :: operator == (Fraction obj)
{

    if (numer==obj.numer&&denom==obj.denom)
        return true;
    else
        return false;


}

bool Fraction :: operator != (Fraction obj)
{

    if((numer/denom)!=(obj.numer/obj.denom))
        return true ;
    else
        return false;

}


bool Fraction :: operator >= (Fraction obj)
{

    if((numer/denom)>=(obj.numer/obj.denom))
        return true ;
    else
        return false;
}

bool Fraction :: operator <= (Fraction obj)
{

    if((numer/denom)<=(obj.numer/obj.denom))
        return true ;
    else
        return false;
}

istream & operator >> (istream & input , Fraction & obj)
{
    input>>obj.numer;
    input>>obj.denom;
    return input;
}

ostream & operator << (ostream & output,const Fraction  obj)
{
    if (obj.denom==0)
        output<<"can not divide by zero"<<endl;
    else{

        output<<obj.numer<<"/"<<obj.denom;
    }
    return output;
}
Fraction Fraction ::sumTwoF(Fraction  &obj)
{
    Fraction result ;
    result.numer= numer*obj.denom+ obj.numer*denom;
    result.denom= denom*obj.denom ;
    return result;
}

Fraction Fraction ::subtractTwoF(Fraction  &obj)
{
    Fraction result ;
    result.numer= numer*obj.denom - obj.numer*denom;
    result.denom= denom*obj.denom ;
    return result;
}

Fraction Fraction ::multiplyTwoF(Fraction  &obj)
{ Fraction result ;
    result.numer= numer*obj.numer;
    result.denom= denom*obj.denom ;
    return result;
}


Fraction Fraction ::DivideTwoF(Fraction  &obj)
{
    Fraction result ;
    result.numer= numer* obj.denom;
    result.denom= denom*obj.denom ;
    int a =(int)result.numer;
    int b =(int)result.denom;
    simplification();
    return result;
}

void Fraction::simplification() {
    bool e = true;
    float u, d;
    while(e) {
        for (int  i = (numer * denom); i > 1; i--) {
            if ((numer % i == 0) && (denom % i == 0)) {
                u = numer / i;
                d = denom / i;


            } else {
                e = false;
            }
        }
    }
    if(u/d==1)
        cout<<"simplest form = 1"<<endl ;
    else
        cout << "simplest form=" << u << "/" << d << endl;



}
