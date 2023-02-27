#include <iostream>
#include "bigDecimal.h"
#include <bits/stdc++.h>
#include <cstring>
#include <string>
using namespace std ;


int main() {

    cout<<endl ;
    string st="000098";
    bigDecimal f (st);

    string w = f.simplify(st);
    cout<<"000098"<<" ==> after  simplification ==> "<< w<< endl ;
    cout<<".............................\n";

    bigDecimal s4("34");
    bigDecimal s5 ("45");
    bigDecimal s6;
    s6=s4-s5;
    cout<<"34-45 = "<<s6.simplify(s6.number)<<endl ;

    cout<<".............................\n";
    bigDecimal subtract1("5");
    bigDecimal subtract2 ("-5");
    bigDecimal sResult;
    sResult=subtract1-subtract2;
    cout<<"5-(-5) = "<< sResult<< endl ;
    cout<<".............................\n";

    bigDecimal s7("-200");
    bigDecimal s8 ("20");
    bigDecimal s9;
    s9=s7+s8;
    cout<<"-200 +20 = "<<s9.simplify(s9.number)<<endl ;
    cout<<".............................\n";

    bigDecimal s10("180");
    bigDecimal s11 ("-20");
    bigDecimal s12;
    s12=s10+s11;
    cout<<"180+(-20) = "<<s12.simplify(s12.number)<<endl ;
    cout<<".............................\n";

    bigDecimal e1("-5");
    bigDecimal e2("5");
    bigDecimal l ;
    l=e1-e2;
    cout<< "-5- 5 = "<< l << endl ;
    cout<<".............................\n";

    bigDecimal num1("123456789012345678901234567890");
    bigDecimal num2("113456789011345678901134567890");
    bigDecimal num3 = num1 + num2;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num2 + num1 = " << num3 << endl;
}
