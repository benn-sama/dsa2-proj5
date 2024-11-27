#include "data-extraction.hpp"

DataExtraction::DataExtraction() {} // default constructor for object creation

// specifically extracts ONLY two strings assuming the first line is the first value that needs to be extracted
void DataExtraction::twoString(std::vector<std::string> *vector, std::ifstream *fileStream, std::string fileName) {
  if (!this->openFile(fileStream, fileName)) {
   throw std::runtime_error("Failed to open file: " + fileName);
  }

  std::string line;

  for (int i = 0; i < 2; ++i) {
    if (std::getline(*fileStream, line)) {
      std::istringstream iss(line);
      std::string value;

      iss >> value;
      vector->push_back(value);
    }
  }

  fileStream->close();
}

// extracts multiple strings assuming the number count of lines is the first line 
void DataExtraction::multiString(std::vector<std::string> *vector, std::ifstream *fileStream, std::string fileName) {
  if (!this->openFile(fileStream, fileName)) {
   throw std::runtime_error("Failed to open file: " + fileName);
  }

  std::string line;
  int count;

  std::getline(*fileStream, line);
  std::istringstream iss(line);
  iss >> count;

  for (int i = 0; i < count; ++i) {
    if (std::getline(*fileStream, line)) {
      vector->push_back(line);
    }
  }

  fileStream->close();
}

// opens file. returns true or false depending if the file opened successful
bool DataExtraction::openFile(std::ifstream *fileStream, std::string fileName) {
  if (!fileStream->is_open()) {
    fileStream->open(fileName);

  if (!fileStream->is_open()) {
    return false;
  }

    return true;
  }

  fileStream->close();
  fileStream->open(fileName);

  if (!fileStream->is_open()) {
    return false;
  }

  return true;
}