#include <fstream>
#include <string>

#include "relational_number.h"


int main(int argc, char *argv[]){

  if(argc != 3){

    std::cout << "MODO DE USO: ./RelationalNumbers archivo1 archivo2" 
    "\n > Dónde archivo uno es el fichero o (racional1) de número racionales"
    "y archivo2 es el fichero o (racional2) en el que se guardarán las operaciones\n";
  }else{
/*
    std::string raw_relational = argv[1];
    if(raw_relational.find("/") != std::string::npos){
      size_t pos = raw_relational.find("/");
      RelationalNumber n1(std::stoi(raw_relational.substr(0,pos)),std::stoi(raw_relational.substr(pos+1)));
      raw_relational = argv[2];
      pos = raw_relational.find("/");
      if(pos != std::string::npos){
      RelationalNumber n2(std::stoi(raw_relational.substr(0,pos)),std::stoi(raw_relational.substr(pos+1)));
      std::cout << n1 + n2 << " "<< n1 - n2 << " " << n1*n2 << " " << n1/n2 << "\n"; 
}
}else{
  */
    std::ifstream relational_pairs(argv[1]);
    std::ofstream operation_file(argv[2]);


    if(!relational_pairs.is_open() || !operation_file.is_open())
      std::cout << "No puede abrise el fichero\n";
    else{
      std::string line;
      std::string raw_number1;
      RelationalNumber number1;
      RelationalNumber number2;
      size_t idx;
      while(std::getline(relational_pairs,line)){
       // operation_file << line + ":\n";
        
        idx = line.find(" ");
        raw_number1 = line.substr(0,idx);
        line = line.substr(idx+1);
      
        idx = raw_number1.find("/");
        
        number1.numerador() = std::stoi(raw_number1.substr(0,idx));
        number1.denominador() = std::stoi(raw_number1.substr(idx+1));

        idx = line.find("/");

        number2.numerador() = std::stoi(line.substr(0,idx));
        number2.denominador() = std::stoi(line.substr(idx+1));

        operation_file << raw_number1 + " + " + line + " = ";
        operation_file << number1 + number2; 
        operation_file << raw_number1 + " - " + line + " = "; 
        operation_file << number1 - number2;
        operation_file << raw_number1 + " * " + line + " = ";
        operation_file << number1 * number2;
        operation_file << raw_number1 + " / " + line + " = ";
        operation_file << number1 / number2;

      //}
    
      }
    }
  }
}
