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