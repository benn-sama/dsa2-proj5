/*
 * File: main.cpp
 * Description: This source file contains the main function to execute the LCS computations.
 * 
 * Usage: The main function creates an instance of the ComputeLCS class and calls its methods
 *        to initialize the user interface for LCSOne and LCSTwo computations.
 */

#include "compute-lcs.hpp"

#include <iostream>
#include <string>

int main() {
  ComputeLCS lcs;
  lcs.UIOne();
  std::cout << std::endl;
  lcs.UITwo();

  return 0;
}