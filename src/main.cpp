#include "../include/compressor.hpp"
#include <iostream>
#include <string>
#include <sstream>

int main (int argc, char *argv[]) {
  Compressor c;
  std::string const testString = "AAAABBBCCDAA";
  std::string encodedString = c.encode(testString);
  std::cout << encodedString << std::endl;
  return 0;
}
