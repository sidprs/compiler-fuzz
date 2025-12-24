#include <iostream>
#include "input.h"
#include "log.hpp"


int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: ./log <file> <search_value> \n";
    return 1;
  }

  std::string filename = argv[1];
  char search_value = *argv[2];

  std::cout << search_value << std::endl;

  std::cout << filename << std::endl;
  Log logger(filename);
  logger.LogFileParser(search_value);
  logger.Print();
  
  MetaRing(4);

  //

  return 0;
}
