/*
 * File: lcs-two-test.cpp
 * Description: This source file contains test cases for the LCSTwo class.
 * 
 * Usage: The file includes manual tests to verify the functionality of the LCSTwo class methods,
 *        such as checking the values of the strings vector, row and column sizes, and initial matrix values.
 *        It uses assertions to check the correctness of the LCS computation.
 */

#include "lcs-two.hpp"

void test1() {
  std::vector<std::string> strings;
  
  strings.push_back("abcd");
  strings.push_back("adbcd");
  strings.push_back("abcdef");
  strings.push_back("fedabca");

  LCSTwo lcs(strings);

  for (int i = 0; i < int(strings.size()); ++i) {
    if (strings[i] != lcs.returnString(i)) {
      throw std::runtime_error("vector strings do not have the same value");
    }
  }
  std::cout << "Test 1: vector value check passed." << std::endl;

  if (lcs.returnColumn() != 4) {
    throw std::runtime_error("column value does not equal 4");
  }
  std::cout << "Test 2: column value check passed." << std::endl;

  if (lcs.returnRow() != 4) {
    throw std::runtime_error("row value does not equal 4");
  }
  std::cout << "Test 3: row value check passed." << std::endl;

  for (int i = 0; i < lcs.returnRow(); ++i) {
    for (int j = 0; j < lcs.returnColumn(); ++j) {
      if (lcs.returnChar(i, j) != '-') {
        throw std::runtime_error("matrix value does not equal '-' ");
      }
    }
  }

  std::cout << "Test 4: initial matrix value check passed" << std::endl;
}

void test2() {
  std::vector<std::string> strings;
  
  strings.push_back("abcd");
  strings.push_back("adbcd");
  strings.push_back("abcdef");
  strings.push_back("fedabca");

  LCSTwo lcs(strings);
  
  if (lcs.LCS(0, 1) != 4) {
    throw std::runtime_error("LCS(0, 1) does not equal 4");
  }
  std::cout << "Test 5: LCS(0, 1) check passed." << std::endl;

  if (lcs.LCS(0, 2) != 4) {
    throw std::runtime_error("LCS(1, 2) does not equal 4");
  }
  std::cout << "Test 6: LCS(0, 2) check passed." << std::endl;

  if (lcs.LCS(0, 3) != 3) {
    throw std::runtime_error("LCS(2, 3) does not equal 3");
  }
  std::cout << "Test 7: LCS(0, 3) check passed." << std::endl;

  std::cout << "test2(): passed" << std::endl << std::endl;
}

void test3() {
  std::vector<std::string> strings;
  
  strings.push_back("abcd");
  strings.push_back("adbcd");
  strings.push_back("abcdef");
  strings.push_back("fedabca");

  LCSTwo lcs(strings);

  lcs.LCSCompute();

  lcs.printMatrix();

  std::cout << "test3(): passed" << std::endl << std::endl;
}

int main() {
  try {
    test1();
    test2();
    test3();
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}