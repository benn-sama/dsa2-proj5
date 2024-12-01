/*
 * File: lcs-two.hpp
 * Description: This header file defines the LCSTwo class, which provides
 *              methods to compute the longest common subsequence (LCS) between multiple strings.
 * 
 * Usage: The LCSTwo class provides methods to compute the LCS using a an iterative algorithm,
 *        compute the similarity between strings, and manage a matrix to keep track of LCS computation similarities.
 *        It includes methods for testing purposes such as printing the matrix and strings,
 *        returning specific characters and strings, and getting the row and column sizes.
 */

#ifndef LCS_TWO_HPP
#define LCS_TWO_HPP

#include <string>
#include <vector>
#include <iostream>

class LCSTwo {
  private:
    int column;
    int matrixRow;
    int matrixColumn;
    char** matrix;
    std::vector<std::string> strings;
  public:
    LCSTwo(std::vector<std::string> strings); // parameterized constructor
    void LCSCompute(); // computes the lcs
    int LCS(int i, int j); // lcs algorithm
    void computeSimilarity(int i, int j, int lcs); // computes the similarity between strings
    ~LCSTwo(); // deconstructor

    // methods for testing
    void printMatrix();
    void printStrings();
    std::string returnString(int i);
    char returnChar(int i, int j);
    int returnRow();
    int returnColumn();
};

#endif