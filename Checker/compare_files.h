#ifndef COMPAREFILES_H
#define COMPAREFILES_H

class CompareFiles
{
    std::string code_output, answer_output; // files
    std::vector<std::string> output_vec, answer_vec;

public:
    CompareFiles(std::string, std::string);
    void get_files();
    bool compare();
};

#include "compare_files.cpp"

#endif