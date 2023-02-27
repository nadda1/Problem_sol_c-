//
// Created by Nada H on 4/18/2022.
//

#include <iostream>
#include "bigDecimal.h"
#include <string>
#include <bits/stdc++.h>
using namespace std ;
bigDecimal::bigDecimal() {
    number="";

}
bigDecimal::bigDecimal(string stringNum) {
    bool assign =bigDecimal::valid(stringNum);
    if(assign)
        number=stringNum;
    else
        std::cout<<"not valid input \n";
}

bigDecimal::bigDecimal(int intNum) {
    string toS = to_string (intNum);
    number=toS;
}
bigDecimal bigDecimal::operator+(bigDecimal b) {

        if (number[0] == '-' ) {
            this->number.erase(0, 1);
            return b - *this;

        }
    if (b.number[0] == '-' ) {
        b.number.erase(0, 1);
        return  *this-b;

    }




{
        string s1 = this->number;
        string s2 = b.number;
        string sum = "";
        int carry = 0;
        while (s1.length() > s2.length()) s2 = '0' + s2;
        while (s1.length() < s2.length()) s1 += '0' + s1;
        for (int i = s1.length() - 1; i >= 0; i--) {
            carry = (s1[i] - '0') + (s2[i] - '0') + carry;
            sum = char((carry % 10) + '0') + sum;
            carry /= 10;
        }
        if (carry == 1) {
            sum = '1' + sum;
        }

        bigDecimal res(sum);
        return res;
    }
}

bigDecimal bigDecimal::operator-(bigDecimal b) {
    if (b.number[0] == '-' ) {
        b.number.erase(0, 1);
        return b + *this;

    }
    if (number[0] == '-' ) {
        this->number.erase(0, 1);
        bigDecimal v= b + *this;
        string finalResult=v.number;
        finalResult='-'+finalResult;
        bigDecimal final(finalResult);
        return final;

    }
    string str1 =this-> number ;
    string str2 =b.number ;
    if(smaller(str1,str2)){
        swap(str1, str2);

        string str = "";

        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        int c = 0;

        for (int i = 0;i <  str2.length(); i++) {

            int sub= ((str1[i] - '0') - (str2[i] - '0') - c);
            if (sub < 0) {
                sub = sub + 10;
                c = 1;
            }
            else
                c = 0;

            str.push_back(sub + '0');

        }
        for (int i = str2.length(); i < str1.length(); i++) {
            int sub = ((str1[i] - '0') - c);
            if (sub < 0) {
                sub = sub + 10;
                c = 1;
            }
            else
                c = 0;

            str.push_back(sub + '0');
        }
        reverse(str.begin(), str.end());
        str.insert(0,"-");
        bigDecimal o(str) ;
        return o;
    }
    else {
        string str = "";
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        int c= 0;
        for (int i = 0; i<str2.length(); i++) {

            int sub= ((str1[i] - '0') - (str2[i] - '0') - c);
            if (sub < 0) {
                sub = sub + 10;
                c= 1;
            }
            else
                c = 0;

            str.push_back(sub + '0');

        }
        for (int i = str2.length(); i < str1.length(); i++) {
            int sub = ((str1[i] - '0') - c);

            if (sub < 0) {
                sub = sub + 10;
                c = 1;
            }
            else
                c= 0;

            str.push_back(sub + '0');
        }

        reverse(str.begin(), str.end());
        bigDecimal o(str) ;
        return o;
    }

}



ostream &operator<<(ostream &os, bigDecimal D) {
    os<<D.number;

}

int bigDecimal::size() {
    return number.length();
}

bigDecimal bigDecimal::operator=(const bigDecimal &otherNum) {
    number=otherNum.number;
    return *this ;
}
bool sign(bigDecimal b) {
    bool found = true;
    for(int i =0 ; i<b.number.length(); i++)
    {
        string  str ="-";
        found = str.find(b.number, found+1);
    }
    if(found)
        return false ;
    else return true;
}

bool bigDecimal::valid(string &s) {
    for (char const &ch : s) {
        if (isdigit(ch) == 1|| s[ch]=='-')
            return true;
    }
    return false;
}

bool bigDecimal::operator==(bigDecimal b) {

    if (this->number == b.number) {
        return true ;
    } else {
        return false ;
    }

}

string bigDecimal:: simplify(string &num) {
    int i =0;
    for(i; i<num.length()&&num[i]=='0';i++);

    if (i==(num.length()))
        num.erase(0,i-1);
    else
        num.erase(0,i);
    return num;

}
bool bigDecimal::smaller(string str1 , string str2 ) {

    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;

}


