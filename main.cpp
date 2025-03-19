#include <iostream>
#include <string>
#include <sstream>

std::string encode(std::string const &inputString);

int main (int argc, char *argv[]) {
  std::string testString = "AAAABBBCCDAA";
  std::string encodedString = encode(testString);
  std::cout << encodedString << std::endl;
  return 0;
}

// Encode string with RLE algorithm and return encoded string
std::string encode(std::string const &inputString){
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
  return stringStream.str();
}
