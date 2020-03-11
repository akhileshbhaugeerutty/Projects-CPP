#include "utils.hpp"

#include <iostream>

std::string readFile(std::string filePath)
{

  std::ifstream ifs(filePath);
  std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

  return content;
}

int getRand(int min, int max)
{
    srand(time(0));
    return min + ( std::rand() % ( max - min + 1) );
}