/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction f1(2,3);
    Fraction f2(1,5);
    Fraction f3(2,10);
    Fraction temp1 =f1 * f3;
    Fraction temp2 =f3 * 0.25;
    Fraction temp3 = 3 * f3;
    if(f3 == f2){
        cout << "good" << endl;
    }
    cout << temp1.numerator <<"/" << temp1.denominator <<endl;
    cout << temp2.numerator <<"/" << temp2.denominator <<endl;
    cout << temp3.numerator <<"/" << temp3.denominator <<endl;

    /*/
    Fraction a(5,3), b(14,21);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a+b << endl; 
    cout << "a-b" << a-b << endl; 
    cout << "a/b" << a/b << endl; 
    cout << "a*b" << a*b << endl; 
    cout << "2.3*b" << 2.3*b << endl; 
    cout << "a+2.421" << a+2.421 << endl; 
    Fraction c = a+b-1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;
    /*/

}