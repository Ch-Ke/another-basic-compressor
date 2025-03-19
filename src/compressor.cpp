#include "../include/compressor.hpp"
#include <string>
#include <sstream>

Compressor::Compressor(){}

Compressor::~Compressor(){}

std::string Compressor::encode(std::string const &inputString){
  int n = inputString.size();
  std::ostringstream stringStream;
  for(int i = 0; i < n; i++){
    int count = 1;
    while(i + 1 < n && inputString[i] == inputString[i+1]){
      count++;
      i++;
    }
    stringStream << count << inputString[i];
  }
  return stringStream.str(); // convert output stringstream to string
}

