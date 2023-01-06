#ifndef COMPAREFILES_H
#define COMPAREFILES_H

class CompareFiles
{
    std::string code_output, answer_output; // file paths
    std::vector<std::string> output_vec, answer_vec;
    void get_files();

public:
    CompareFiles(std::string, std::string);
    bool compare();
};

#include "compare_files.cpp"

#endif