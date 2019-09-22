#ifndef RELATIONAL_NUMBER_H_
#define RELATIONAL_NUMBER_H_

#include <iostream>

class RelationalNumber {

  private:    
    int num_;
    int den_;

  public:
    RelationalNumber(int num=0, int den=1);
    RelationalNumber(int number);
  
    friend std::istream& operator>>(std::istream& is, const RelationalNumber& number);
    friend std::ostream& operator<<(std::ostream& os, const RelationalNumber& number);
    RelationalNumber operator+(const RelationalNumber& number);
    RelationalNumber operator-(const RelationalNumber& number);
    RelationalNumber operator*(const RelationalNumber& number);
    RelationalNumber operator/(const RelationalNumber& number);
    
  
    inline int numerador()   const {return num_;}; 
    inline int denominador() const {return den_;};
    inline int& numerador()        {return num_;};
    inline int& denominador()      {return den_;}; 
};


    inline bool operator==(const RelationalNumber& number1, const RelationalNumber& number2)
        {return (number1.numerador() == number2.numerador() 
            && number1.denominador() == number2.denominador());};
    inline bool operator!=(const RelationalNumber& number1, const RelationalNumber& number2)
        {return !(number1 == number2);};

    inline bool operator<(const RelationalNumber& number1, const RelationalNumber& number2)
        {return(number1.numerador()*number2.denominador() < number2.numerador()*number1.denominador());};
    inline bool operator>(const RelationalNumber& number1,const RelationalNumber& number2)
        {return(number2 < number1);};
    inline bool operator<=(const RelationalNumber& number1, const RelationalNumber& number2)
        {return(number1 > number2);};
    inline bool operator>=(const RelationalNumber& number1, const RelationalNumber& number2)
        {return(number1 < number2);};

#endif //RELATIONAL_NUMBER_H_
