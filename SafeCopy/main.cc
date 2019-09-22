#include <fstream>
#include <string>

#include "relational_number.h"


int main(int argc, char *argv[]){

  if(argc != 3){

    std::cout << "MODO DE USO: ./RelationalNumbers archivo1 archivo2" 
    "\n > Dónde archivo uno es el fichero de número racionales"
    "y archivo2 es el fichero en el que se guardarán las operaciones\n";
  }else{

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
        operation_file << line + ":";
        
        idx = line.find(" ");
        raw_number1 = line.substr(0,idx);
        line = line.substr(idx+1);
      
        idx = raw_number1.find("/");
        
        number1.numerador() = std::stoi(raw_number1.substr(0,idx));
        number1.denominador() = std::stoi(raw_number1.substr(idx+1));

        idx = line.find("/");

        number2.numerador() = std::stoi(line.substr(0,idx));
        number2.denominador() = std::stoi(line.substr(idx+1));

      }
    

    }
  }
}
