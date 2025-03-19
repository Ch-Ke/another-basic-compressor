#include "../include/compressor.hpp"
#include "../include/charVector.hpp"
#include <string>
#include <iostream>
#include <cctype>

Compressor::Compressor(){}

Compressor::~Compressor(){}

std::string Compressor::encode(std::string const &inputString){
  size_t n = inputString.size();
  if(inputString == "" || n < 2){
    return inputString;
  }
  CharVector v(n);
  for(size_t i = 0; i < n; i++){
    int count = 1;
    while(i + 1 < n && inputString[i] == inputString[i+1]){
      count++;
      i++;
    }
    v.push_back_int(count);
    v.push_back(inputString[i]);
  }
  return v.str(); 
}

std::string Compressor::decode(std::string const &inputString){
  size_t n = inputString.size();
  if(inputString == "" || n < 2){
    return inputString;
  }
  CharVector v(n);
  size_t i = 0;
  while (i < n) {
    int count = 0;
    size_t byteIndex = 0;
    while (byteIndex < sizeof(int) && i < n) {
      count |= (static_cast<unsigned char>(inputString[i]) << (byteIndex * 8));
      i++;
      byteIndex++;
    }
    
    if (i < n) {
      char ch = inputString[i];
      for (int j = 0; j < count; j++) {
      v.push_back(ch);  
    }
    i++; 
    }
  }
  return v.str(); 
}
