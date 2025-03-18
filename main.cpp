#include <iostream>
#include <string>

std::string encode(std::string inputString);

int main (int argc, char *argv[]) {
  std::string testString = "AAAABBBCCDAA";
  std::string encodedString = encode(testString);
  return 0;
}

std::string encode(std::string inputString){
  std::cout << "Hello, world!" << std::endl;
  return "";
}
