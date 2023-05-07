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
#include <limits>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;
#define MAX_INT numeric_limits<int>::max()


int main() {
    Fraction temp{2147483647,1};
    Fraction temp2{2147483647,1};
    //    CHECK_EQ(2.0 * (Fraction{-1, 4} + Fraction{-1, 2}), 2.0 * Fraction{-1, 4} + 2.0 * Fraction{-1, 2});
    Fraction a1(-1,4);
    Fraction a2(-1,2);
    Fraction b1 = temp + temp2;
    cout << b1 << endl;

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
