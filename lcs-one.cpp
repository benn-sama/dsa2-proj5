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

std::string LCSOne::LCSCompute() { // initializes matrix and algorithm for LCS
  this->initializeCArray();

  return LCS(row, column);
}

// algorithm to find LCS w/ no b-array
std::string LCSOne::LCS(int i, int j) {
  std::string lcsString;
  std::vector<char> s;

  while (i > 0 && j > 0) {
    if (stringOne[i - 1] == stringTwo[j - 1]) {
      s.push_back(stringOne[i - 1]);
      --i;
      --j;
    }
    else if (cArray[i - 1][j] >= cArray[i][j - 1]) {
      --i;
    }
    else {
      --j;
    } 
  }
  while (!s.empty()) {
    lcsString += s.back();
    s.pop_back();
  }

  return lcsString;
}

void LCSOne::initializeCArray() { // fills in the matrix corresponding to the algorithm
  // left out initializing row 1 and column 1 because constructor already does it
  if (cArray == nullptr) {
    throw std::runtime_error("Tried to initialize a cArray that is a nullptr");
  }

  for (int i = 1; i < row; ++i) {
    for (int j = 1; j < column; ++j) {
      if (stringOne[i - 1] == stringTwo[j - 1]) {
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

void LCSOne::printAll() {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
      std::cout << cArray[i][j] << " ";
    }
    std::cout << std::endl;
  }
}