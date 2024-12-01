/*
 * File: compute-lcs.hpp
 * Description: This header file defines the ComputeLCS class, which provides
 *              methods to interact with the user interface for computing the longest common subsequence (LCS).
 * 
 * Usage: The ComputeLCS class provides methods to handle outputs for two different LCS computations.
 *        It includes methods to initialize the user interface for LCSOne and LCSTwo computations.
 */

#ifndef COMPUTER_LCS_HPP
#define COMPUTER_LCS_HPP

#include "data-extraction.hpp"
#include "lcs-one.hpp"
#include "lcs-two.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class ComputeLCS {
  public: 
    ComputeLCS();
    void UIOne();
    void UITwo();
};

#endif