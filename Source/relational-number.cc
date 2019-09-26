#include "relational_number.h"

#include <stdexcept>
#include <string>

RelationalNumber::RelationalNumber(int num, int den):num_(num),den_(den){
  if(den_ == 0)
    //Envía una señal de error
    throw std::domain_error("Zero Denominator");
}

RelationalNumber::RelationalNumber(int number): num_(number), den_(1){}

std::istream& operator>>(std::istream& is, RelationalNumber& number){
 
  std::string raw_relational_number;
  is >> raw_relational_number;
  //Recibe el string que almacena el racional
  //Encuentra el separador "/" e introduce
  //los valores correspondientes a den_ y num_
  size_t mid = raw_relational_number.find("/"); 
  
  number.numerador() = std::stoi(raw_relational_number.substr(0,mid));
  number.denominador() = std::stoi(raw_relational_number.substr(mid+1));

  return is;
}

std::ostream& operator<<(std::ostream &os, const RelationalNumber& number){

  os << number.num_ << "/" << number.den_ << "\n";

  return os;
}

 RelationalNumber RelationalNumber::operator+(const RelationalNumber& number){

  if(den_ == number.denominador())
    return RelationalNumber(num_+number.numerador(),den_);
  else
    return RelationalNumber(num_*number.denominador() + den_*number.numerador(),den_*number.denominador());
 }

RelationalNumber RelationalNumber::operator-(const RelationalNumber& number){

  if(den_ == number.denominador())
    return RelationalNumber(num_-number.numerador(),den_);
  else
    return RelationalNumber(num_*number.denominador() - den_*number.numerador(),den_*number.denominador());
}

RelationalNumber RelationalNumber::operator*(const RelationalNumber& number){

  return RelationalNumber(num_*number.numerador(),den_*number.denominador());
}

RelationalNumber RelationalNumber::operator/(const RelationalNumber& number){

  return RelationalNumber(num_*number.denominador(),den_*number.numerador());
}











