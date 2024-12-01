/*
 * File: data-extraction.hpp
 * Description: This header file defines the DataExtraction class, which provides
 *              methods to extract strings from files.
 * 
 * Usage: The DataExtraction class provides methods to extract two strings or multiple strings
 *        from a file and store them in a vector. It also includes a method to open a file.
 */

#ifndef DATA_EXTRACTION_HPP
#define DATA_EXTRACTION_HPP

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class DataExtraction {
  public:
    DataExtraction();
    void twoString(std::vector<std::string> *vector, std::ifstream *fileStream, std::string fileName); // extracts only two strings
    void multiString(std::vector<std::string> *vector, std::ifstream *fileStream, std::string fileName); // extracts multiple string
    bool openFile(std::ifstream *fileStream, std::string fileName); // opens file
};

#endif