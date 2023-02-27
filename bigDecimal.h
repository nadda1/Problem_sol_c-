//
// Created by Nada H on 4/18/2022.
//

#ifndef PROBLEM1_BIGDECIMAL_H
#define PROBLEM1_BIGDECIMAL_H
#include <string>
#include <fstream>
using namespace std ;
class bigDecimal {
public:
    string number ;
    bigDecimal();
    bigDecimal(string stringNum);
    bigDecimal(int intNum);
    int size();
    bigDecimal operator+(bigDecimal b);
    bigDecimal operator-(bigDecimal b);
    bigDecimal operator= (const bigDecimal &otherNum);
    bool operator==(bigDecimal b );

    friend ostream& operator<< (ostream& output, bigDecimal D);
    bool valid( string& s);
    friend bool sign (bigDecimal b);
    bool smaller(string n , string m );
    string  simplify(string &a);
};


#endif //PROBLEM1_BIGDECIMAL_H
