#ifndef CHARVECTOR_H
#define CHARVECTOR_H
#include <string>

class CharVector{
private:
  char* data;
  size_t size = 0;
  size_t capacity = 0;
public:
  CharVector(size_t capacity);
  ~CharVector();
  void push_back(char const &input);
  void push_back_int(int num);
  std::string str();
};

#endif // CHARVECTOR_H
