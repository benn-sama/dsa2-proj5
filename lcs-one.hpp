/*
 * File: lcs-one.hpp
 * Description: This header file defines the LCSOne class, which provides
 *              methods to compute the longest common subsequence (LCS) between two strings.
 * 
 * Usage: The LCSOne class provides methods to compute the LCS using a iterative algorithm,
 *        initialize the C array matrix, and access various properties for testing purposes.
 *        It includes methods to return the value of the C array at a specific index, get the
 *        row and column sizes, and print all relevant information.
 */

#ifndef LCS_ONE_HPP
#define LCS_ONE_HPP

#include <string>
#include <vector>
#include <iostream>

class LCSOne {
  private:
    int** cArray;
    int row;
    int column;
    std::string stringOne;
    std::string stringTwo;
    std::vector<char> lcsString;
  public:
    LCSOne(std::string stringOne, std::string stringTwo); // parameterized contructor
    std::string LCSCompute(); // executes lcs() recursive and initializesCArray
    std::string LCS(int i, int j); // recursive algorithm for finding lcs
    void initializeCArray(); // fill the carray matrix
    ~LCSOne(); // deconstructor

    // methods for testing below
    int returncArrayIndex(int i, int j); // returns cArray value
    int getRowSize();
    int getColumnSize();
    void printAll();
};

#endif