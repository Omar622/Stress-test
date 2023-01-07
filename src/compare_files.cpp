#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/compare_files.h"

// constructor reads files' paths
CompareFiles::CompareFiles(std::string test_file_path, std::string ref_file_path)
    : test_file_path(test_file_path), ref_file_path(ref_file_path) {}

// just read files content into vectors
void CompareFiles::read_files()
{
    test_file_content.clear();
    ref_file_content.clear();
    std::string line;

    // open test file
    std::ifstream test_file(test_file_path);
    // read content of test file into test file content
    while (getline(test_file, line))
    {
        test_file_content.emplace_back(line);
    }
    // close test file
    test_file.close();

    // open ref file
    std::ifstream ref_file(ref_file_path);
    // read content of ref file into ref file content
    while (getline(ref_file, line))
    {
        ref_file_content.emplace_back(line);
    }
    // close ref file
    ref_file.close();
}

// compare files line by line (not ignoring whitespaces). return true if identical otherwise false
bool CompareFiles::compare_lines()
{
    // first read files
    read_files();

    // it's not valid if files have no equal size
    if (test_file_content.size() != ref_file_content.size())
    {
        std::cout << "Comparator: Files have no equal sizes\n";
        return false;
    }

    for (int i = 0; i < test_file_content.size(); ++i)
    {
        if (ref_file_content[i] != test_file_content[i])
        {
            std::cout << "Comparator: Conflict in line " << i + 1
                      << "\nComparator: Expected " << ref_file_content[i] << ", but found " << test_file_content[i] << "\n";
            return false;
        }
    }

    return true;
}