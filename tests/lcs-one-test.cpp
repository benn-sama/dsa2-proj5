#include "lcs-one.hpp"

void test1() {
  std::string stringOne = "abcdbab";
  std::string stringTwo = "bdcaba";
  LCSOne lcs(stringOne, stringTwo);

  if (lcs.getRowSize() != 7 + 1) {
    throw std::runtime_error("Row size does not equal 7\n" + std::to_string(lcs.getRowSize()));
  }
  std::cout << "Test 1: Row size check passed." << std::endl;

  if (lcs.getColumnSize() != 6 + 1) {
    throw std::runtime_error("Column size does not equal 6" + std::to_string(lcs.getColumnSize()));
  }
  std::cout << "Test 2:Column size check passed." << std::endl;

  for (int i = 0; i < int(stringOne.size()) + 1; ++i) {
    for (int j = 0; j < int(stringTwo.size()) + 1; ++j) {
      if (lcs.returncArrayIndex(i, j) != 0) {
        throw std::runtime_error("cArray value is not zero\n[" + std::to_string(i) + "][" + std::to_string(j) + "]: " + std::to_string(lcs.returncArrayIndex(i, j)));
      }
    }
  }
  std::cout << "Test 3:All index values are zero check passed." << std::endl;
  std::cout << "test1(): passed" << std::endl << std::endl;
}

// for setting up the test
void lcsAlgorithm(int** mockArr, int row, int column, std::string stringOne, std::string stringTwo) {
  // zeros the first column
  for (int i = 1; i < row; ++i) {
    mockArr[i][0] = 0;
  }

  // zeros the first row
  for (int j = 0; j < column; ++j) {
    mockArr[0][j] = 0;
  }

  // actual algorithm
  for (int i = 1; i < row; ++i) {
    for (int j = 1; j < column; ++j) {
      if (stringOne[i - 1] == stringTwo[j - 1]) {
        mockArr[i][j] = mockArr[i - 1][j - 1] + 1;
      }
      else {
        if (mockArr[i - 1][j] >= mockArr[i][j - 1]) {
          mockArr[i][j] =  mockArr[i - 1][j];
        }
        else {
          mockArr[i][j] = mockArr[i][j - 1];
        }
      }
    }
  }
}

// automatic testing
void test2() {
  std::string stringOne = "abcdbab";
  std::string stringTwo = "bdcaba";
  int row = int(stringOne.size()) + 1;
  int column = int(stringTwo.size()) + 1;
  LCSOne lcs(stringOne, stringTwo);

  // creates a 2d arrays
  int** mockArr = new int*[row];
  for (int i = 0; i < row; ++i) {
    mockArr[i] = new int[column];
  }

  lcsAlgorithm(mockArr, row, column, stringOne, stringTwo);
  lcs.initializeCArray();

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
      if (mockArr[i][j] != lcs.returncArrayIndex(i, j)) {
        throw std::runtime_error("mockArray and cArray values do not match\nmockArray[" + std::to_string(i) + "][" + std::to_string(j) + ": " + std::to_string(mockArr[i][j])
                                  + "\ncArray[" + std::to_string(i) + "][" + std::to_string(j) + ": " + std::to_string(lcs.returncArrayIndex(i, j)));
      }
    }
  }
  std::cout << "Test 4: Automatic test passed for initializing cArray." << std::endl;

  for (int i = 0; i < row; ++i) {
    delete[] mockArr[i];
  }
  delete[] mockArr;

  std::cout << "test2(): passed" << std::endl << std::endl;
}

void test3() {
  std::string stringOne = "bdc";
  std::string stringTwo = "abc";
  int row = int(stringOne.size()) + 1;
  int column = int(stringTwo.size()) + 1;
  LCSOne lcs(stringOne, stringTwo);

  lcs.initializeCArray();

  for (int i = 0; i < row; ++i) {
    if (lcs.returncArrayIndex(i, 0) != 0) {
        throw std::runtime_error("cArray's zeroth column does not all equal to 0\ncArray[" + std::to_string(i) + "][" + std::to_string(0) + ": " + std::to_string(lcs.returncArrayIndex(i, 0)));
    }
  }
  std::cout << "Test 5: Zero column check passed." << std::endl;

  for (int j = 0; j < column; ++j) {
    if (lcs.returncArrayIndex(0, j) != 0) {
      throw std::runtime_error("cArray's zeroth row does not all equal to 0\ncArray[" + std::to_string(0) + "][" + std::to_string(j) + ": " + std::to_string(lcs.returncArrayIndex(0, j)));
    }
  }
  std::cout << "Test 6: Zero row check passed." << std::endl;

  if (lcs.returncArrayIndex(1, 1) != 0 && lcs.returncArrayIndex(1, 2) != 0 && lcs.returncArrayIndex(1, 3) != 0) {
    throw std::runtime_error("cArray's first row does not all equal to 0\ncArray[1][1 -> 3]: " + std::to_string(lcs.returncArrayIndex(1, 1)) + " " + std::to_string(lcs.returncArrayIndex(1, 2)) + " " + std::to_string(lcs.returncArrayIndex(1, 3)));
  }
  std::cout << "Test 7: [1][1 -> 3] = 0 check passed." << std::endl;

  if (lcs.returncArrayIndex(2, 1) != 1 && lcs.returncArrayIndex(2, 2) != 1 && lcs.returncArrayIndex(2, 3) != 1) {
    throw std::runtime_error("cArray's first row does not all equal to 1\ncArray[2][1 -> 3]: " + std::to_string(lcs.returncArrayIndex(2, 1)) + " " + std::to_string(lcs.returncArrayIndex(2, 2)) + " " + std::to_string(lcs.returncArrayIndex(2, 3)));
  }
  std::cout << "Test 8: [2][1 -> 3] = 1 check passed." << std::endl;

  if (lcs.returncArrayIndex(3, 1) != 1 && lcs.returncArrayIndex(3, 2) != 1) {
    throw std::runtime_error("cArray's first row does not all equal to 1\ncArray[3][1 -> 2]: " + std::to_string(lcs.returncArrayIndex(3, 1)) + " " + std::to_string(lcs.returncArrayIndex(3, 2)));
  }
  std::cout << "Test 9: [3][1 -> 2] = 1 check passed." << std::endl;

  if (lcs.returncArrayIndex(3, 3) != 2) {
    throw std::runtime_error("cArray's first row does not all equal to 1\ncArray[3][3]: " + std::to_string(lcs.returncArrayIndex(3, 3)));
  }
  std::cout << "Test 10: [3][3] = 2 check passed." << std::endl;

  std::cout << "test3(): passed" << std::endl << std::endl;
}

void test4() {
  std::string stringOne = "abcdbab";
  std::string stringTwo = "bdcaba";
  LCSOne lcs(stringOne, stringTwo);

  lcs.initializeCArray();
  lcs.LCS(int(stringOne.size()), int(stringTwo.size()));

  try {
    if (lcs.LCSCompute() != "bcba") {
      std::runtime_error("lcs does not match bcba");
    }
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "Test 11: LCSCompute return check passed." << std::endl;
  std::cout << "test4(): passed" << std::endl << std::endl;
}

int main() {
  try {
    test1();
    test2();
    test3();
    test4();
    std::cout << "All tests passed for lcs-one.hpp!" << std::endl << std::endl;
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}