#include "../include/compressor.hpp"
#include <iostream>
#include <string>
#include <fstream>

std::string read_file(const std::string &filename) {
    std::ifstream file(filename); 
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }
    std::string inData((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return inData;
}

void write_compressed_file(const std::string &filename, const std::string &outData) {
    std::ofstream out_file(filename);
    if (!out_file) {
        std::cerr << "Error opening output file: " << filename << std::endl;
        exit(1);  
    }
    out_file << outData;  
}

int main(int argc, char* argv[]) {  
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <input_file> <output_file> <enc OR dec>" << std::endl;
    return 1;
  }
  std::string input_file = argv[1];
  std::string output_file = argv[2];
  std::string input_data = read_file(input_file); 
  std::string method = argv[3];
  Compressor compressor;
  std::string data;
  if(method == "enc"){
    data = compressor.encode(input_data);
  } else if(method == "dec"){
    data = compressor.decode(input_data);
  } else{
    return 1; // error
  }

  write_compressed_file(output_file, data);
  std::cout << "Compression completed. Encoded data saved to: " << output_file << std::endl;
  return 0;
}

