#include "relational_number.h"

#include <stdexcept>
#include <string>

RelationalNumber::RelationalNumber(int num, int den):num_(num),den_(den){
  if(den_ == 0)
    throw std::domain_error("Zero Denominator");
}

RelationalNumber::RelationalNumber(int number): num_(number), den_(1){}

std::istream& operator>>(std::istream& is, RelationalNumber& number){
 
  std::string raw_relational_number;
  is >> raw_relational_number;
  size_t mid = raw_relational_number.find("/"); 
  
  std::string num = raw_relational_number.substr(0,mid);
  std::string den = raw_relational_number.substr(mid,raw_relational_number.size());
  
  number.numerador() = std::stoi(num);
  number.denominador() = std::stoi(den);

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











