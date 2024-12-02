#include "lcs-two.hpp"

LCSTwo::LCSTwo(std::vector<std::string> strings) { // parameterized constructor
  this->strings = strings;
  matrixRow = int(this->strings.size());
  matrixColumn = matrixRow;

  matrix = new char*[matrixRow];

  try {
    for (int i = 0; i < matrixRow; ++i) {
      matrix[i] = new char[column];

      for (int j = 0; j < column; ++j) {
        matrix[i][j] = '-';
      }
    }
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    exit(0);
  }
}

void LCSTwo::LCSCompute() { // computes the lcs of all the strings
  for (int i = 0; i < int(strings.size()); ++i) {
    for (int j = i + 1; j < int(strings.size()); ++j) {
      if (i != j) {
        LCS(i, j);
      }
    }
  }
}

int LCSTwo::LCS(int i, int j) { // algorithm for finding the lcs
  const std::string& str1 = strings[i];
  const std::string& str2 = strings[j];
  int m = str1.size();
  int n = str2.size();

  // create arrays based on the size of the smaller string
  int previousRow[n + 1];
  int currentRow[n + 1];

  // initialize previousRow with zeros
  for (int col = 0; col <= n; ++col) {
    previousRow[col] = 0;
  }

  for (int row = 1; row <= m; ++row) {
    currentRow[0] = 0; // first column is always 0
    for (int col = 1; col <= n; ++col) {
        if (str1[row - 1] == str2[col - 1]) {
          currentRow[col] = previousRow[col - 1] + 1;
        } 
        else {
          currentRow[col] = std::max(previousRow[col], currentRow[col - 1]);
        }
    }

    // copy currentRow into previousRow for the next iteration
    for (int col = 0; col <= n; ++col) {
      previousRow[col] = currentRow[col];
    }
  }

  // calls this to compute the similarity between strings
  this->computeSimilarity(i, j, previousRow[n]);

  return previousRow[n];
}

void LCSTwo::computeSimilarity(int i, int j, int lcs) { // computes the similarity between strings
  int shorterString;
  int longerString;

  if (int(strings[i].size()) < int(strings[j].size())) {
    shorterString = i;
    longerString = j;
  } else {
    shorterString = j;
    longerString = i;
  }

  // compute the length ratio and lcs ratio
  float shorterLength = strings[shorterString].size();
  float longerLength = strings[longerString].size();
  float lengthRatio = shorterLength / longerLength;
  float lcsRatio = float(lcs) / shorterLength;

  if (lengthRatio >= 0.9 && lcsRatio >= 0.9) {
    matrix[i][j] = 'H';
  } 
  else if (lengthRatio >= 0.8 && lcsRatio >= 0.8) {
    matrix[i][j] = 'M';
  } 
  else if (lengthRatio >= 0.6 && lcsRatio >= 0.5) {
    matrix[i][j] = 'L';
  } 
  else {
    matrix[i][j] = 'D';
  }
}

LCSTwo::~LCSTwo() { // deconstructor
  for (int i = 0; i < matrixRow; ++i) {
    delete[] matrix[i];
  }

  delete[] matrix;
  matrixRow = 0;
  matrixColumn = 0;
  strings.clear();
  matrix = nullptr;
}

void LCSTwo::printMatrix() { // prints the whole matrix
  std::cout << "  ";
  for (int i = 0; i < matrixRow; ++i) {
    std::cout << i << " ";
  }

  std::cout << std::endl;

  for (int i = 0; i < matrixRow; ++i) {
    std::cout << i << " ";
    for (int j = 0; j < matrixColumn; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void LCSTwo::printStrings() { // prints strings
  for (int i = 0; i < int(strings.size()); ++i) {
    std::cout << strings[i] << std::endl;
  }
}

std::string LCSTwo::returnString(int i) { // returns a string
  return strings[i];
}

char LCSTwo::returnChar(int i, int j) { // returns a character
  return matrix[i][j];
}

int LCSTwo::returnRow() { // returns the size of the matrix row
  return matrixRow;
}

int LCSTwo::returnColumn() { // returns the size of the matrix column
  return matrixColumn;
}