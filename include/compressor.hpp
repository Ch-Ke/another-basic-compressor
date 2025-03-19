#ifndef COMPRESSOR_HPP
#define COMPRESSOR_HPP

#include <string>

class Compressor{
public:
  Compressor();
  ~Compressor();
  std::string encode(std::string const &inputString);
};

#endif // COMPRESSOR_HPP
