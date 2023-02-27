//
// Created by Nada H on 4/2/2022.
//

#include "FractionCalc.h"
#include "Fraction.h"

FractionCalc::FractionCalc() {

}

void FractionCalc::FractionCalculator() {

    bool Exit=true ;
    while (Exit)
    {
        cout<<"enter your choice\n";
        cout<<"(1) Sum two Fractions \n";
        cout<< " ( 2) subtract two fractions \n ";
        cout<< " (3) multiple two fractions \n ";
        cout<< " (4) divide two fractions \n ";
        cout<<"(5) Exit";
        int choice ;
        cin>> choice ;
        if(choice==1){
            Fraction f1, f2 ,f3;
            cout<<"enter the first fraction numbers first the numerator second the denominator";
            cin>>f1 ;
            cout<<"enter the second fraction numbers first the numerator second the denominator";
            cin>>f2 ;

           f3=f1.sumTwoF(f2);
           f3.simplification();


        }
        else if(choice==2){
            Fraction f1, f2 ,f3;
            cout<<"enter the first fraction numbers first the numerator second the denominator";
            cin>>f1 ;
            cout<<"enter the second fraction numbers first the numerator second the denominator";
            cin>>f2 ;

            f3=f1.subtractTwoF(f2);
            f3.simplification();



        }
        else if(choice==3){
            Fraction f1, f2 ,f3;
            cout<<"enter the first fraction numbers first the numerator second the denominator";
            cin>>f1 ;
            cout<<"enter the second fraction numbers first the numerator second the denominator";
            cin>>f2 ;

            f3=f1.multiplyTwoF(f2);
            f3.simplification();


        }
        else if(choice==4){
            Fraction f1, f2 ,f3;
            cout<<"enter the first fraction numbers first the numerator second the denominator";
            cin>>f1 ;
            cout<<"enter the second fraction numbers first the numerator second the denominator";
            cin>>f2 ;
            f3=f1.DivideTwoF(f2);
            f3.simplification();


        }
        else if(choice==5){
            Exit=false ;
            break;

        }

    }

}
