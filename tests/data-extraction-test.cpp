/*
 * File: data-extraction-test.cpp
 * Description: This source file contains test cases for the DataExtraction class.
 * 
 * Usage: The file includes manual tests to verify the functionality of the DataExtraction class methods,
 *        such as extracting two strings or multiple strings from a file and storing them in a vector.
 *        It uses assertions to check the correctness of the extracted data.
 */

#include "data-extraction.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

// manual testing
void test1() {
  DataExtraction data;
  std::vector<std::string> twoStringVector;
  std::string twoStringName = "twoStrings.txt";
  std::ifstream fileStream;

  data.twoString(&twoStringVector, &fileStream, twoStringName);

  if (twoStringVector.size() != 2) {
    throw std::runtime_error("twoStringVector does not contain exactly 2 elements");
  }
  std::cout << "Test 1: mockVector size check passed." << std::endl;

  if (twoStringVector[0] != "fdsasdfdsfsdsdssdasasfdsasdfsdssasadsfsfsdsfadsfsdassdsfasdsdasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsddsasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsdsasasdfdfsadfdsasasdfdsasdadsfsdassdsfasdsddsasdfsasasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssfdsasdfsdssasadsfsfsdsfadsfsdassdsfasdsdasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsddsasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsdsasasdfdfsadfdsasasdfdsasdadsfsdassdsfasdsddsasdfsasasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssfdsasdfsdssasadsfsfsdsfadsfsdassdsfasdsdasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsddsasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsdsasasdfdfsadfdsasasdfdsasdadsfsdassdsfasdsddsasdfsasasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssfdsasdfsdssasadsfsfsdsfadsfsdassdsfasdsdasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsds") {
    throw std::runtime_error("First line of twoStrings.txt does not match");
  }
  std::cout << "Test 2: first string check passed." << std::endl;

  if (twoStringVector[1] != "adfdsasdfsdssasadsfsfsdsfadsfsdassdsfasdsdasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsddsasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsdsasasdfdfsadfdsasasdfdsasdsasdfasdfdsasdasdfdsasdfdsadfdsasdfsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfd") {
    throw std::runtime_error("Second line of twoStrings.txt does not match");
  }
  std::cout << "Test 3: second string check passed." << std::endl;
  std::cout << "test1(): passed" << std::endl << std::endl;
}

void test2() {
  DataExtraction data;
  std::vector<std::string> multiStringVector;
  std::vector<std::string> mockVector;
  std::string multiStringName = "multiStrings.txt";
  std::ifstream mockFileStream(multiStringName);
  std::ifstream fileStream;
  std::string line;
  int count;

  // automatic testing
  std::getline(mockFileStream, line);
  std::istringstream iss(line);
  iss >> count;

  for (int i = 0; i < count; ++i) {
    if (std::getline(mockFileStream, line)) {
      mockVector.push_back(line);
    }
  }

  data.multiString(&multiStringVector, &fileStream, multiStringName);

  if (multiStringVector.size() != mockVector.size()) {
    throw std::runtime_error("MultiStringVector and MockVector do not have the same size\nMultiStringVector Size: " + std::to_string(multiStringVector.size())
                            + "\nMockVector Size: " + std::to_string(mockVector.size()));
  }
  std::cout << "Test 4: mock and multi vector size check passed." << std::endl;

  for (int i = 0; i < int(multiStringVector.size()); ++i) {
    if (multiStringVector[i] != mockVector[i]) {
      throw std::runtime_error("Multi and Mock vectors do not have the same value at index " + std::to_string(i));
    }
  }
  std::cout << "Test 5: mock and multi vector string element values passed." << std::endl;

  // manual testing
  if (multiStringVector.size() != 8) {
    throw std::runtime_error("MultiStringVector size does not equal 8\nsize: " + std::to_string(int(multiStringVector.size())));
  }
  std::cout << "Test 6: mock and multi vector manual size check passed." << std::endl;

  for (int i = 0; i < int(multiStringVector.size()); ++i) {
    if (multiStringVector[0] != "asdfdsasdfdsadfdsasdf") {
      throw std::runtime_error("MultStringVector does not equal to the first line of the file\n[" + std::to_string(i) + "]: " + multiStringVector[i]);
    }
    if (multiStringVector[1] != "asdfdsasd") {
      throw std::runtime_error("MultStringVector does not equal to the second line of the file\n[" + std::to_string(i) + "]: " + multiStringVector[i]);
    }
    if (multiStringVector[2] != "asdfdsasdfdsadfdsasdfsdssasadsfsdfsdsfadsfsdassdsfasdsd") {
      throw std::runtime_error("MultStringVector does not equal to the third line of the file\n[" + std::to_string(i) + "]: " + multiStringVector[i]);
    }
    if (multiStringVector[3] != "asdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsd") {
      throw std::runtime_error("MultStringVector does not equal to the fourth line of the file\n[" + std::to_string(i) + "]: " + multiStringVector[i]);
    }
    if (multiStringVector[4] != "dsasdfsadfdsasdfsdssa") {
      throw std::runtime_error("MultStringVector does not equal to the fifth line of the file\n[" + std::to_string(i) + "]: " + multiStringVector[i]);
    }
    if (multiStringVector[5] != "asdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsd") {
      throw std::runtime_error("MultStringVector does not equal to the sixth line of the file\n[" + std::to_string(i) + "]: " + multiStringVector[i]);
    }
    if (multiStringVector[6] != "dsasasdfdfsadfdsas") {
      throw std::runtime_error("MultStringVector does not equal to the seventh line of the file\n[" + std::to_string(i) + "]: " + multiStringVector[i]);
    }
    if (multiStringVector[7] != "asdfdsasd") {
      throw std::runtime_error("MultStringVector does not equal to the eigth line of the file\n[" + std::to_string(i) + "]: " + multiStringVector[i]);
    }
  }
  std::cout << "Test 7: mock and multi vector manual string element values passed." << std::endl;
    std::cout << "test2(): passed" << std::endl << std::endl;
}

int main() {
  try {
    test1();
    test2();
    std::cout << "All tests passed for data-extraction.hpp!" << std::endl << std::endl;
  } 
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}