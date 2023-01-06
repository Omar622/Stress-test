#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "compare_files.h"

CompareFiles::CompareFiles(std::string code_output, std::string answer_output)
    : code_output(code_output), answer_output(answer_output) {}

void CompareFiles::get_files()
{
    output_vec.clear();
    answer_vec.clear();
    std::string line;

    std::ifstream out_file(code_output);

    while (getline(out_file, line))
        output_vec.emplace_back(line);

    out_file.close();

    std::ifstream ans_file(answer_output);
    while (getline(ans_file, line))
        answer_vec.emplace_back(line);
    ans_file.close();
}

bool CompareFiles::compare()
{
    get_files();

    if (output_vec.size() != answer_vec.size())
    {
        std::cout << "files have no equel sizes\n";
        return false;
    }

    int i = 0;
    for (; i < output_vec.size() and i < answer_vec.size(); ++i)
    {
        if (answer_vec[i] != output_vec[i])
        {
            std::cout << "conflice in line " << i + 1 << "\nexpected " << answer_vec[i] << ", but found " << output_vec[i] << "\n";
            return false;
        }
    }

    return true;
}