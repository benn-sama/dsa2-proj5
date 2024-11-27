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

  if (twoStringVector[0] != "fdsasdfdsfsdsdssdasasfdsasdfsdssasadsfsfsdsfadsfsdassdsfasdsdasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsddsasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsdsasasdfdfsadfdsasasdfdsasdadsfsdassdsfasdsddsasdfsasasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssfdsasdfsdssasadsfsfsdsfadsfsdassdsfasdsdasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsddsasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsdsasasdfdfsadfdsasasdfdsasdadsfsdassdsfasdsddsasdfsasasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssfdsasdfsdssasadsfsfsdsfadsfsdassdsfasdsdasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsddsasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsdsasasdfdfsadfdsasasdfdsasdadsfsdassdsfasdsddsasdfsasasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssfdsasdfsdssasadsfsfsdsfadsfsdassdsfasdsdasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsds") {
    throw std::runtime_error("First line of twoStrings.txt does not match");
  }
  if (twoStringVector[1] != "adfdsasdfsdssasadsfsfsdsfadsfsdassdsfasdsdasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsddsasdfsadfdsasdfsdssaasdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsdsasasdfdfsadfdsasasdfdsasdsasdfasdfdsasdasdfdsasdfdsadfdsasdfsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfdsdsfasdsddsasdfsadfdsasdfsdssaasdfd") {
    throw std::runtime_error("Second line of twoStrings.txt does not match");
  }
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

  for (int i = 0; i < int(multiStringVector.size()); ++i) {
    if (multiStringVector[i] != mockVector[i]) {
      throw std::runtime_error("Multi and Mock vectors do not have the same value at index " + std::to_string(i));
    }
  }

  // manual testing
  if (multiStringVector.size() != 8) {
    throw std::runtime_error("MultiStringVector size does not equal 8\nsize: " + std::to_string(int(multiStringVector.size())));
  }

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
}

int main() {
  try {
    test1();
    test2();
    std::cout << "All tests passed!" << std::endl;
  } 
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}