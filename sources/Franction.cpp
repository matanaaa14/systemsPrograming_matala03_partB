#include "Fraction.hpp"
#include <iostream>

using namespace std;

namespace ariel{}
    // implementation of member functions
    Fraction Fraction::operator+(const Fraction& other){
      Fraction f(this->numerator * other.denominator +other.numerator *this->denominator, this->denominator *other.denominator);
      return f;
    }
    
    Fraction Fraction::operator+(float num){
      Fraction temp = convert(num);
      Fraction result(this->numerator * temp.denominator +temp.numerator *this->denominator, this->denominator *temp.denominator) ;
      return result;}
              
    Fraction operator+(float num,const Fraction& fraction){
      Fraction nothing(1,1);// only to be able to use convert function
      Fraction temp = nothing.convert(num);
      Fraction result(fraction.numerator * temp.denominator +temp.numerator *fraction.denominator, fraction.denominator *temp.denominator);   
      return result;}



    Fraction Fraction::operator-(const Fraction& other){
      Fraction f(this->numerator * other.denominator -other.numerator *this->denominator, this->denominator *other.denominator);
      return f;   }
    
    Fraction Fraction::operator-(float num){
      Fraction temp = convert(num);
      Fraction result(this->numerator * temp.denominator -temp.numerator *this->denominator, this->denominator *temp.denominator) ;
      return result;   }
    

    Fraction operator-(float num,const Fraction& fraction){
      Fraction nothing(1,1);// only to be able to use convert function
      Fraction temp = nothing.convert(num);
      cout << "check: " << temp.numerator << "/" << temp.denominator << endl;
      //Fraction result(fraction.numerator * temp.denominator -temp.numerator *fraction.denominator, fraction.denominator *temp.denominator);   
      Fraction result = temp - fraction;
      return result;   }


    Fraction Fraction::operator*(const Fraction& other){
      Fraction f(this->numerator * other.numerator,this->denominator * other.denominator);
      return f; }

    Fraction Fraction::operator*(float num){
      Fraction temp = convert(num);
      Fraction result(this->numerator * temp.numerator, this->denominator *temp.denominator) ;
      return result;   }
    
   

    Fraction operator*(float num,const Fraction& fraction){
      Fraction nothing(1,1);// only to be able to use convert function
      Fraction temp = nothing.convert(num);
      //Fraction result(fraction.numerator * temp.numerator,fraction.denominator *temp.denominator) ;
      Fraction result = temp * fraction;
      return result;     }

    
    Fraction Fraction::operator/(const Fraction& other){
      if(other.numerator == 0){
        perror("division by 0 is illegal\n");
        exit(1);
      }
      Fraction result(this->numerator * other.denominator,this->denominator * other.numerator);
      return result;  }

    Fraction Fraction::operator/(float num){
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
      Fraction nothing(1,1);// only to be able to use convert function
      Fraction temp = nothing.convert(num);
      //Fraction result(fraction.numerator * temp.denominator ,fraction.denominator *temp.numerator) ;
      Fraction result = temp / fraction;
      return result;     }

    bool Fraction::operator==(const Fraction& other) const{
      if(this->numerator != other.numerator || this->denominator != other.denominator)
        return false;
      return true;
    }
    bool operator==(float num, const Fraction& fraction){
      Fraction nothing(1,1);// only to be able to use convert function
      Fraction temp = nothing.convert(num);
      return fraction == temp;
    }
    bool operator==(const Fraction& fraction,float num){
      return num == fraction;
    }

    bool Fraction::operator<(const Fraction& other){
      Fraction stam1 = other;
      Fraction temp = stam1 - *this;
      cout << "check: " << temp.numerator << "/" << temp.denominator << endl;
      if((temp.numerator > 0 & temp.denominator > 0)||(temp.numerator < 0 & temp.denominator < 0) )
          return true;
      return false;
    }
    bool operator<(float num, const Fraction& fraction){
      Fraction nothing(1,1);
      Fraction temp = nothing.convert(num);
      return temp < fraction; 
    }
    
    bool operator<(const Fraction& fraction, float num){
      Fraction fraction2 =fraction;
      Fraction nothing(1,1);
      Fraction temp = nothing.convert(num);
      return fraction2 < temp; 
    }
    
    bool Fraction::operator<=(const Fraction& other){
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
    
    bool operator<=(const Fraction& fraction, float num){
      Fraction nothing(1,1);
      Fraction temp = nothing.convert(num);
      Fraction temp2 = fraction;
      return temp2 <= temp;
    }
    
    bool Fraction::operator>(const Fraction& other){
      if (*this == other){
        return false;
      }
      return !(*this < other);
    }
    
    bool Fraction::operator>(float num){
      Fraction nothing(1,1);
      Fraction temp = nothing.convert(num);
      return *this > temp;
    }
    bool operator>(float num, const Fraction& fraction){
      return fraction < num;
    }
    
    bool operator>(const Fraction& fraction, float num){
      return num < fraction;
    }
    
    bool Fraction::operator>=(const Fraction& other){
      return (*this > other || *this == other);
    }
    bool operator>=(float num, const Fraction& fraction){
      return !(num < fraction);
    }
    
    bool operator>=(const Fraction& fraction, float num){
      return !(fraction < num);
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
      int gcd = GCD(num1, num2);
      this->numerator = num1 / gcd;
      this->denominator = num2 / gcd;
    }
    Fraction Fraction::convert(float num){
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


