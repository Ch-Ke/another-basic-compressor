#include <iostream>
#include <string>

std::string encode(std::string &inputString);

int main (int argc, char *argv[]) {
  std::string testString = "AAAABBBCCDAA";
  std::string encodedString = encode(testString);
  std::cout << encodedString << std::endl;
  return 0;
}

// Encode string with RLE algorithm and return encoded string
std::string encode(std::string &inputString){
  std::string encodedString = "";
  int n = inputString.size();
  for(int i = 0; i < n; i++){
    int count = 1;
    while(i + 1 < n && inputString[i] == inputString[i+1]){
      count++;
      i++;
    }
    encodedString += std::to_string(count);
    encodedString.push_back(inputString[i]);
  }
  return encoded;
}
