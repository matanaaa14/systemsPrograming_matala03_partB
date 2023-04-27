#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

namespace ariel{}

class Fraction {
public:
    int numerator, denominator;
    Fraction(int, int);

    Fraction operator+(const Fraction& other);
    Fraction operator+(float num);
    friend Fraction operator+(float num, const Fraction& fraction);
    //friend Fraction operator+(const Fraction& fraction,float num);
    
    Fraction operator-(const Fraction& other);
    Fraction operator-(float num);
    friend Fraction operator-(float num, const Fraction& fraction);
    //friend Fraction operator-(const Fraction& fraction,float num);

    Fraction operator*(const Fraction& other);
    Fraction operator*(float num);
    friend Fraction operator*(float num, const Fraction& fraction);
    //friend Fraction operator*(const Fraction& fraction,float num);

    Fraction operator/(const Fraction& other);
    Fraction operator/(float num);
    friend Fraction operator/(float num, const Fraction& fraction);
    //friend Fraction operator/(const Fraction& fraction,float num);

    bool operator==(const Fraction& other) const;
    friend bool operator==(float num, const Fraction& fraction);
    friend bool operator==(const Fraction& fraction,float num);

    bool operator<(const Fraction& other);
    friend bool operator<(float num, const Fraction& fraction);
    friend bool operator<(const Fraction& fraction,float num);

    bool operator<=(const Fraction& other);
    friend bool operator<=(float num, const Fraction& fraction);
    friend bool operator<=(const Fraction& fraction,float num);

    bool operator>(const Fraction& other);
    bool operator>(float num);
    friend bool operator>(float num, const Fraction& fraction);
    friend bool operator>(const Fraction& fraction,float num);

    bool operator>=(const Fraction& other);
    friend bool operator>=(float num, const Fraction& fraction);
    friend bool operator>=(const Fraction& fraction,float num);

    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    Fraction operator>>(const Fraction& other);

    friend std::ostream& operator<<(std::ostream& ostreamm, const Fraction& other);

    int GCD(int num1 ,int num2);
    Fraction convert(float num);
};



#endif