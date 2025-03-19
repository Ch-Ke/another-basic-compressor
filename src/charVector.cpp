#include "../include/charVector.hpp"
#include <string>
#include <iostream>
CharVector::CharVector(size_t capacity) : size(0), capacity(capacity){
  data = new char[capacity];
}

CharVector::~CharVector(){
  delete[] data;
}

void CharVector::push_back(char const &input){
  if(size >= capacity){
    capacity *= 2;
    char* newData = new char[capacity];
    for(size_t i = 0; i < size; i++){
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
  }
  data[size]=input;
  size++;
}

void CharVector::push_back_int(int num){
  for(size_t i = 0; i < sizeof(num); i++){
    push_back((num >> (i*8)) & 0xFF);
  }
}

std::string CharVector::str(){
  return std::string(data, size);
}
