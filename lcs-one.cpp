#include "lcs-one.hpp"

LCSOne::LCSOne(std::string stringOne, std::string stringTwo) {
  this->stringOne = stringOne;
  this->stringTwo = stringTwo;
  row = stringOne.size() + 1;
  column = stringTwo.size() + 1;

  cArray = new int*[row];

  // creates the columns 
  try {
    for (int i = 0; i < row; ++i) {
      cArray[i] = new int[column];

      for (int j = 0; j < column; ++j) {
        cArray[i][j] = 0;
      }
    }
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    exit(0);
  }
}

void LCSOne::LCSCompute() {

}

void LCSOne::LCS(int i, int j) {

}

void LCSOne::initializeCArray() { // fills in the matrix corresponding to the algorithm
  // left out initializing row 1 and column 1 because constructor already does it
  if (cArray == nullptr) {
    throw std::runtime_error("Tried to initialize a cArray that is a nullptr");
  }

  for (int i = 1; i < row; ++i) {
    for (int j = 1; j < column; ++j) {
      if (stringOne[i] == stringTwo[j]) {
        cArray[i][j] = cArray[i - 1][j - 1] + 1;
      }
      else {
        if (cArray[i - 1][j] >= cArray[i][j - 1]) {
          cArray[i][j] =  cArray[i - 1][j];
        }
        else {
          cArray[i][j] = cArray[i][j - 1];
        }
      }
    }
  }
}

LCSOne::~LCSOne() {
  for (int i = 0; i < row; ++i) {
    delete[] cArray[i];
  }

  delete[] cArray;
  row = 0;
  column = 0;
  stringOne = "undefined";
  stringTwo = "undefined";
  cArray = nullptr;
}

int LCSOne::returncArrayIndex(int i, int j) {
  int value;

  try {
    value = cArray[i][j];
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    exit(0);
  }

  return value;
}

int LCSOne::getRowSize() {
  return row;
}

int LCSOne::getColumnSize() {
  return column;
}