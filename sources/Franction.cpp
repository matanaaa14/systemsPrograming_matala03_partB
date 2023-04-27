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
      if((temp.numerator > 0 || temp.denominator > 0)||(temp.numerator < 0 || temp.denominator < 0) )
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
      return false;
    }
    bool operator<=(const Fraction& fraction1, const Fraction& fraction2){
      return false;
    }
    
    bool operator<=(const Fraction& f, double num){
      return false;
    }
    
    bool Fraction::operator>(const Fraction& other){
      return false;
    }
    
    bool Fraction::operator>(float num){
      return false;
    }
    bool operator>(const Fraction& fraction1, const Fraction& fraction2){
      return false;
    }
    
    bool operator>(const Fraction& f, double num){
      return false;
    }
    
    bool Fraction::operator>=(const Fraction& other){
      return false;
    }
    bool operator>=(const Fraction& fraction1, const Fraction& fraction2){
      return false;
    }
    
    bool operator>=(const Fraction& f, double num){
      return false;
    }
    
    Fraction& Fraction::operator++(){
      return *this;

    }
    
    Fraction Fraction::operator++(int){
      Fraction fb(1,2);
      return fb;
    }
    
    Fraction& Fraction::operator--(){
    return *this;
    }
    
    Fraction Fraction::operator--(int){
        Fraction fc(1,2);
        return fc;
    }
    
    Fraction Fraction::operator>>(const Fraction& other){
      Fraction f(1,2);
      return f;      }
    
    ostream& operator<<(ostream& os,const Fraction& other){
        ostream& stam = cout;
        stam << "hello" <<endl;
        return stam;
      }
    
    // implementation of friend functions

  
    /*/Fraction& operator++(Fraction& f){
      return *this;
    }/*/
    
    /*/Fraction& operator--(Fraction& f){
      Fraction f3(1,2);
      return f;      }/*/
    
    Fraction operator>>(const Fraction& f, int num){
      Fraction q(1,2);
      return q;     }
    
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


