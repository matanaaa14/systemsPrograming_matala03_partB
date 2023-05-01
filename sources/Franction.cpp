#include "Fraction.hpp"
#include <iostream>

using namespace std;

namespace ariel{}
    // implementation of member functions
    Fraction Fraction::operator+(const Fraction& other)const{
      Fraction f(this->numerator * other.denominator +other.numerator *this->denominator, this->denominator *other.denominator);
      return f;
    }
    
    Fraction Fraction::operator+(float num)const{
      Fraction temp = convert(num);
      Fraction result(this->numerator * temp.denominator +temp.numerator *this->denominator, this->denominator *temp.denominator) ;
      return result;}
              
    Fraction operator+(float num,const Fraction& fraction){
      Fraction temp = fraction.convert(num);
      Fraction result(fraction.numerator * temp.denominator +temp.numerator *fraction.denominator, fraction.denominator *temp.denominator);   
      return result;}



    Fraction Fraction::operator-(const Fraction& other)const{
      Fraction f(this->numerator * other.denominator -other.numerator *this->denominator, this->denominator *other.denominator);
      return f;   }
    
    Fraction Fraction::operator-(float num)const{
      
      Fraction temp = convert(num);
      Fraction result(this->numerator * temp.denominator -temp.numerator *this->denominator, this->denominator *temp.denominator) ;
      return result;   }
    

    Fraction operator-(float num,const Fraction& fraction){
      Fraction temp = fraction.convert(num);
      cout << "check: " << temp.numerator << "/" << temp.denominator << endl;
      //Fraction result(fraction.numerator * temp.denominator -temp.numerator *fraction.denominator, fraction.denominator *temp.denominator);   
      Fraction result = temp - fraction;
      return result;   }


    Fraction Fraction::operator*(const Fraction& other)const{
      Fraction f(this->numerator * other.numerator,this->denominator * other.denominator);
      return f; }

    Fraction Fraction::operator*(float num)const{
      Fraction temp = convert(num);
      Fraction result(this->numerator * temp.numerator, this->denominator *temp.denominator) ;
      return result;   }
    
   

    Fraction operator*(float num,const Fraction& fraction){
      Fraction temp = fraction.convert(num);
      //Fraction result(fraction.numerator * temp.numerator,fraction.denominator *temp.denominator) ;
      Fraction result = temp * fraction;
      return result;     }

    
    Fraction Fraction::operator/(const Fraction& other)const{
      if(other.numerator == 0){
        perror("division by 0 is illegal\n");
        exit(1);
      }
      Fraction result(this->numerator * other.denominator,this->denominator * other.numerator);
      return result;  }

    Fraction Fraction::operator/(float num)const{
      if(num == 0){
        perror("division by 0 is illegal\n");
        exit(1);
      }
      Fraction temp = convert(num);
      Fraction result(this->numerator * temp.denominator , this->denominator *temp.numerator) ;
      return result;   }
    

    Fraction operator/(float num,const Fraction& fraction){
      if(fraction.numerator == 0){
        perror("division by 0 is illegal\n");
        exit(1);
      }
      Fraction temp = fraction.convert(num);
      //Fraction result(fraction.numerator * temp.denominator ,fraction.denominator *temp.numerator) ;
      Fraction result = temp / fraction;
      return result;     }

    bool Fraction::operator==(const Fraction& other) const{
      if(this->numerator != other.numerator || this->denominator != other.denominator)
        return false;
      return true;
    }
    bool operator==(float num, const Fraction& fraction){
      Fraction temp = fraction.convert(num);
      return fraction == temp;
    }
    bool operator==(const Fraction& fraction,float num){
      return num == fraction;
    }

    bool Fraction::operator<(const Fraction& other)const{
      Fraction stam1 = other;
      Fraction temp = stam1 - *this;
      cout << "check: " << temp.numerator << "/" << temp.denominator << endl;
      if((temp.numerator > 0 & temp.denominator > 0)||(temp.numerator < 0 & temp.denominator < 0) )
          return true;
      return false;
    }
    bool operator<(float num, const Fraction& fraction){
      Fraction temp = fraction.convert(num);
      return temp < fraction; 
    }
    
    bool Fraction::operator<(float num)const{
      Fraction fraction2 =*this;
      Fraction temp = convert(num);
      return fraction2 < temp; 
    }
    
    bool Fraction::operator<=(const Fraction& other)const{
      Fraction temp = *this;
      if(temp < other || temp == other)
        return true;
      return false;
    }
    bool operator<=(float num ,const Fraction& fraction){
      Fraction temp1 = fraction;
      Fraction temp2 = temp1.convert(num);
      if(temp1 < temp2 || temp1 == temp2)
        return true;
      return false;
    }
    
    bool Fraction::operator<=(float num)const{
      Fraction temp = convert(num);
      Fraction temp2 = *this;
      return temp2 <= temp;
    }
    
    bool Fraction::operator>(const Fraction& other)const{
      if (*this == other){
        return false;
      }
      return !(*this < other);
    }
    
    bool Fraction::operator>(float num)const{
      Fraction temp = convert(num);
      return *this > temp;
    }
    bool operator>(float num, const Fraction& fraction){
      Fraction temp = fraction;
      return temp < num;
    }
    
    
    bool Fraction::operator>=(const Fraction& other)const{
      return (*this > other || *this == other);
    }
    bool operator>=(float num, const Fraction& fraction){
      return !(num < fraction);
    }
    
    bool Fraction::operator>=(float num)const{
      return (!(*this < num));
    }
    
    Fraction& Fraction::operator++(){
      Fraction temp(this->numerator + this->denominator, this->denominator);
      this->numerator = temp.numerator;
      this->denominator = temp.denominator;
      return *this;
    }
    
    Fraction Fraction::operator++(int){
      Fraction temp(this->numerator + this->denominator, this->denominator);
      this->numerator = temp.numerator;
      this->denominator = temp.denominator;
      return *this;
    }
    
    Fraction& Fraction::operator--(){
      Fraction temp(this->numerator - this->denominator, this->denominator);
      this->numerator = temp.numerator;
      this->denominator = temp.denominator;
      return *this;
    }
    
    Fraction Fraction::operator--(int){
      Fraction temp(this->numerator - this->denominator, this->denominator);
      this->numerator = temp.numerator;
      this->denominator = temp.denominator;
      return *this;
    }
    
    ostream& operator<<(ostream& output,const Fraction& other){
        return output << other.numerator << "/" << other.denominator;
      }
    
    // implementation of friend functions

  
    /*/Fraction& operator++(Fraction& f){
      return *this;
    }/*/
    
    /*/Fraction& operator--(Fraction& f){
      Fraction f3(1,2);
      return f;      }/*/
    
    istream& operator>>(istream& input, Fraction& fraction){
      char slash;
      input >> fraction.numerator >> slash >> fraction.denominator; 
      Fraction temp(fraction.numerator,fraction.denominator);
      fraction = temp;
      return input;
  }
    
    Fraction::Fraction(int num1, int num2){
      if(num2 == 0){
        __throw_invalid_argument("ERROR: denominator can't be-0\n");
        exit(1);
      }
      int gcd = GCD(num1, num2);
      this->numerator = num1 / gcd;
      this->denominator = num2 / gcd;
    }
    Fraction::Fraction(){
      this->denominator = 1;
      this->denominator = 1;
    }
    Fraction::Fraction(float num){
      Fraction temp = convert(num);
      this->numerator = temp.getNumerator();
      this->denominator = temp.getDenominator();
    }
    Fraction Fraction::convert(float num)const{
      int Int = 0;
      if(num < 0.001 && num > -0.001)
        return Fraction(0,1);
      if(num > 1 || num < -1)
        Int = (int) num;
      int temp = (int)(num * 1000);
      temp = temp % 1000;
      return Fraction(temp + (Int * 1000),1000);
    }
    int Fraction::GCD(int num1, int num2){
      if( num2 == 0)
        return num1;
      return GCD(num2, num1 % num2);
    }

    int Fraction::getDenominator(){
      return this->denominator;
    }
    int Fraction::getNumerator(){
      return this->numerator;
    }


