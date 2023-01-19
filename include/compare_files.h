#ifndef COMPAREFILES_H
#define COMPAREFILES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
 * @brief 
 * Definition of the CompareFiles class. It contains two file path and compare them.
 * it will make it easy in the future to add more comparsoin methods 
 * like compare_doubles_with_EPS, compare_int64, ... .
 */

class CompareFiles
{
    // the two files' paths that will be compared
    std::string test_file_path, ref_file_path;
    // temporary vectors to read files in
    std::vector<std::string> test_file_content, ref_file_content;

    // read the tow files in the vectors
    void read_files();

public:
    // constructor reading two files' paths
    CompareFiles(std::string, std::string);
    // return true if both files are identical otherwise false. (compare line by line. not ignoring whitespaces)
    bool compare_lines();
};

#include "../src/compare_files.cpp"

#endif