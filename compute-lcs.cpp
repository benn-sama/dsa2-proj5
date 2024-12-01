#include "compute-lcs.hpp"

ComputeLCS::ComputeLCS() {}

void ComputeLCS::UIOne() {
  DataExtraction extract;
  std::ifstream fileStream;
  std::vector<std::string> string;

  extract.twoString(&string, &fileStream, "twoStrings.txt");

  LCSOne lcs(string[0], string[1]);
  std::cout << "Part 1" << std::endl;
  std::cout << "String one: " << string[0] << std::endl;
  std::cout << "String two: " << string[1] << std::endl; 
  std::cout << "LCS: " << lcs.LCSCompute() << std::endl << std::endl;
}

void ComputeLCS::UITwo() {
  DataExtraction extract;
  std::ifstream fileStream;
  std::vector<std::string> string;

  extract.multiString(&string, &fileStream, "multiStrings.txt");

  LCSTwo lcs(string);
  std::cout << "Part 2" << std::endl;
  lcs.LCSCompute();
  lcs.printMatrix();
}